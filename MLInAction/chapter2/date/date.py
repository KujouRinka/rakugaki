import numpy as np
import matplotlib.pyplot as plt
from chapter2.k_NN import *


def file2matrix(filename):
    with open(filename, 'r') as fr:
        array_lines = fr.readlines()
    number_of_lines = len(array_lines)
    return_mat = np.zeros((number_of_lines, 3))
    class_label_vector = []
    index = 0
    for line in array_lines:
        line = line.strip()
        list_from_line = line.split('\t')
        return_mat[index, :] = list_from_line[:3]
        class_label_vector.append(list_from_line[-1])
        index += 1

    return return_mat, class_label_vector


def auto_norm(data_set):
    min_vals = data_set.min(0)
    max_vals = data_set.max(0)
    ranges = max_vals - min_vals
    norm_data_set = np.zeros(data_set.shape)
    m = data_set.shape[0]
    norm_data_set = data_set - np.tile(min_vals, (m, 1))
    norm_data_set = norm_data_set / np.tile(ranges, (m, 1))
    return norm_data_set, ranges, min_vals


def dating_class_test():
    ho_ratio = 0.1
    dating_data_mat, dating_labels = \
        file2matrix('datingTestSet2.txt')
    norm_mat, ranges, min_vals = auto_norm(dating_data_mat)
    m = norm_mat.shape[0]
    num_test_vecs = int(m * ho_ratio)
    error_count = 0
    for i in range(num_test_vecs):
        classifier_result = \
            classify0(norm_mat[i, :], norm_mat[num_test_vecs:m, :],
                      dating_labels[num_test_vecs:m], 3)
        print('the classifier came back with: {}, the real answer '
              'is: {}'.format(classifier_result, dating_labels[i]))
        if classifier_result != dating_labels[i]:
            error_count += 1
    print('the total error rate is: {}'
          .format(error_count / num_test_vecs))


def classify_person():
    result_list = ['not at all', 'in small doses', 'in large doses']
    percent_tats = float(input(
        'percentage of time spent playing video games: '))
    ff_miles = float(input('frequent flier miles earned per year: '))
    ice_cream = float(input(
        'liters of ice cream consumed per year: '))
    dating_data_mat, dating_labels = \
        file2matrix('datingTestSet2.txt')
    norm_mat, ranges, min_vals = auto_norm(dating_data_mat)
    in_arr = np.array([ff_miles, percent_tats, ice_cream])
    classifier_result = classify0((in_arr - min_vals) / ranges,
                                  norm_mat,
                                  dating_labels, 3)
    print('you will probably like this person: ',
          result_list[int(classifier_result) - 1])


def main():
    # dating_data_mat, dating_labels = \
    #     file2matrix('datingTestSet2.txt')

    # fig = plt.figure()
    # ax = fig.add_subplot(111)
    # ax.scatter(dating_data_mat[:, 0], dating_data_mat[:, 1],
    #            15.0 * np.array(dating_labels).astype(np.float_),
    #            15.0 * np.array(dating_labels).astype(np.float_))
    # plt.show()
    classify_person()


if __name__ == '__main__':
    main()
