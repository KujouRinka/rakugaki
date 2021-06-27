import os
import numpy as np
from chapter2.k_NN import *


def file2vector(filename):
    return_vect = np.zeros((1, 1024))
    with open(filename, 'r') as fr:
        count = 0
        for line in fr.readlines():
            for i in range(32):
                return_vect[0, count * 32 + i] = int(line[i])
            count += 1
    return return_vect


def handwriting_class_test():
    hw_labels = []
    training_file_list = os.listdir('trainingDigits')
    m = len(training_file_list)
    training_mat = np.zeros((m, 1024))
    for i in range(m):
        filename = training_file_list[i]
        class_num_str = int(filename[0])
        hw_labels.append(class_num_str)
        training_mat[i, :] = file2vector('trainingDigits/' +
                                         filename)
    test_file_list = os.listdir('testDigits')
    error_count = 0
    m_test = len(test_file_list)
    for i in range(m_test):
        filename = test_file_list[i]
        class_num_str = int(filename[0])
        vector_test = file2vector('testDigits/' + filename)
        classifier_result = classify0(vector_test, training_mat,
                                      hw_labels, 3)
        print('the classifier came back with: {}, the real '
              'answer is: {}'.format(classifier_result, filename[0]))
        if classifier_result != class_num_str:
            error_count += 1
    print('the total number of errors is: {}'.format(error_count))
    print('the total error rate is: {}'.format(error_count / m_test))


def main():
    handwriting_class_test()


if __name__ == '__main__':
    main()
