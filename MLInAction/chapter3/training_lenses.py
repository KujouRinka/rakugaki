from chapter3.trees import *


def parse_data():
    lenses = []
    with open('data/lenses.txt', 'rt') as f:
        for line in f.readlines():
            lenses.append(line.strip().split('\t'))
    lenses_labels = ['age', 'prescript',
                     'astigmatic', 'tearRate']
    return lenses, lenses_labels


def store_lenses_tree():
    lenses, lenses_labels = parse_data()
    lenses_tree = create_tree(lenses, lenses_labels)
    store_tree(lenses_tree, 'lensesTree.dat')


def main():
    store_lenses_tree()


if __name__ == '__main__':
    main()
