import numpy as np


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

