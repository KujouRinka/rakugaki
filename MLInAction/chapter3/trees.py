import operator
from math import log
from treePlotter import *


def create_data_set() -> (list, list):
    data_set = [
        [1, 1, 'yes'],
        [1, 1, 'yes'],
        [1, 0, 'no'],
        [0, 1, 'no'],
        [0, 1, 'no'],
    ]
    labels = ['no surfacing', 'flippers']
    return data_set, labels


def calc_shannon_ent(data_set) -> float:
    """
    calculate shannon entropy of data_set
    """
    num_entries = len(data_set)
    label_counts = {}
    for feat_vec in data_set:
        current_label = feat_vec[-1]
        if current_label not in label_counts.keys():
            label_counts[current_label] = 0
        label_counts[current_label] += 1
    shannon_ent = 0.0
    for key, value in label_counts.items():
        prob = value / num_entries
        shannon_ent -= prob * log(prob, 2)
    return shannon_ent


def split_data_set(data_set, axis, value) -> list:
    """
    split data into one list
    :param data_set:
    :param axis:
    :param value:
    :return:
    """
    ret_data_set = []
    for feat_vec in data_set:
        if feat_vec[axis] == value:
            reduced_feat_vec = feat_vec[:axis]
            reduced_feat_vec.extend(feat_vec[axis + 1:])
            ret_data_set.append(reduced_feat_vec)
    return ret_data_set


def choose_feature(data_set) -> int:
    num_features = len(data_set[0]) - 1
    base_entropy = calc_shannon_ent(data_set)
    best_into_gain = 0
    best_feature = -1
    for i in range(num_features):
        feat_list = [example[i] for example in data_set]
        unique_vals = set(feat_list)
        new_entropy = 0
        for value in unique_vals:
            sub_data_set = split_data_set(data_set, i, value)
            prob = len(sub_data_set) / len(data_set)
            new_entropy += prob * calc_shannon_ent(sub_data_set)
        info_gain = base_entropy - new_entropy
        if info_gain > best_into_gain:
            best_into_gain = info_gain
            best_feature = i
    return best_feature


def majority_cnt(class_list) -> any:
    class_count = {}
    for vote in class_list:
        if vote not in class_count.keys():
            class_count[vote] = 0
        class_count[vote] += 1
    sorted_class_count = sorted(class_count.items(),
                                key=operator.itemgetter(1),
                                reverse=True)
    return sorted_class_count[0][0]


def create_tree(data_set, labels) -> dict:
    class_list = [example[-1] for example in data_set]
    if len(set(class_list)) == 1:
        return class_list[0]
    if len(data_set[0]) == 1:
        return majority_cnt(class_list)

    best_feat = choose_feature(data_set)
    best_feat_label = labels[best_feat]
    my_tree = {best_feat_label: {}}
    del labels[best_feat]
    feat_values = [example[best_feat] for example in data_set]
    unique_vals = set(feat_values)
    for value in unique_vals:
        sub_labels = labels[:]
        my_tree[best_feat_label][value] = create_tree(
            split_data_set(data_set, best_feat, value),
            sub_labels
        )
    return my_tree


def classify(input_tree, feat_labels, test_vec):
    root_name = tuple(input_tree.keys())[0]
    node_struct = input_tree[root_name]
    feat_index = feat_labels.index(root_name)
    for choose, node in node_struct.items():
        if test_vec[feat_index] == choose:
            if isinstance(node, dict):
                return classify(node, feat_labels, test_vec)
            else:
                return node


def store_tree(input_tree, filename):
    import pickle
    with open(filename, 'wb') as f:
        pickle.dump(input_tree, f)


def grab_tree(filename):
    import pickle
    with open(filename, 'rb') as f:
        tree = pickle.load(f)
    return tree


def main():
    pass


if __name__ == '__main__':
    main()
