import matplotlib.pyplot as plt


decision_node = dict(boxstyle='sawtooth', fc='0.8')
leaf_node = dict(boxstyle='round4', fc='0.8')
arrow_args = dict(arrowstyle='<-')


def retrieve_tree(i):
    list_of_trees = [
        {'no surfacing': {0: 'no', 1: {'flippers': {0: 'no', 1: 'yes'}}}},
        {'no surfacing': {0: 'no', 1: {'flippers': {0: {'head': {0: 'no', 1: 'yes'}}, 1: 'no'}}}}
    ]
    return list_of_trees[i]


def plot_node(node_txt, center_pt, parent_pt, node_type):
    create_plot.ax1.annotate(node_txt, xy=parent_pt,
                             xycoords='axes fraction',
                             xytext=center_pt,
                             textcoords='axes fraction',
                             va='center', ha='center',
                             bbox=node_type,
                             arrowprops=arrow_args)


def get_num_leaves(my_tree):
    leaves = 0
    root_name = tuple(my_tree.keys())[0]
    tree_struct = my_tree[root_name]
    for node in tree_struct.values():
        if isinstance(node, dict):
            leaves += get_num_leaves(node)
        else:
            leaves += 1
    return leaves


def get_tree_depth(my_tree):
    children_depth_list = []
    root_name = tuple(my_tree.keys())[0]
    tree_struct = my_tree[root_name]
    for node in tree_struct.values():
        if isinstance(node, dict):
            children_depth_list.append(get_tree_depth(node))
        else:
            children_depth_list.append(1)
    return max(children_depth_list) + 1


def plot_mid_text(cntr_pt, parent_pt, txt_string):
    x_mid = (parent_pt[0] - cntr_pt[0]) / 2 + cntr_pt[0]
    y_mid = (parent_pt[1] - cntr_pt[1]) / 2 + cntr_pt[1]
    create_plot.ax1.text(x_mid, y_mid, txt_string)


def plot_tree(my_tree, parent_pt, node_txt):
    num_leaves = get_num_leaves(my_tree)
    depth = get_tree_depth(my_tree)
    first_str = tuple(my_tree.keys())[0]
    cntr_pt = (plot_tree.xOff + (1.0 + num_leaves)
               / 2 / plot_tree.totalW, plot_tree.yOff)
    plot_mid_text(cntr_pt, parent_pt, node_txt)
    plot_node(first_str, cntr_pt, parent_pt, decision_node)
    second_dict = my_tree[first_str]
    plot_tree.yOff = plot_tree.yOff - 1 / plot_tree.totalD
    for key, value in second_dict.items():
        if isinstance(value, dict):
            plot_tree(value, cntr_pt, str(key))
        else:
            plot_tree.xOff = plot_tree.xOff + 1 / plot_tree.totalW
            plot_node(value, (plot_tree.xOff, plot_tree.yOff),
                      cntr_pt, leaf_node)
            plot_mid_text((plot_tree.xOff, plot_tree.yOff),
                          cntr_pt, str(key))
    plot_tree.yOff = plot_tree.yOff + 1 / plot_tree.totalD


def create_plot(in_tree):
    fig = plt.figure(1, facecolor='white')
    fig.clf()
    axprops = dict(xticks=[], yticks=[])
    create_plot.ax1 = plt.subplot(111, frameon=False, **axprops)
    plot_tree.totalW = float(get_num_leaves(in_tree))
    plot_tree.totalD = float(get_tree_depth(in_tree))
    plot_tree.xOff = -0.5 / plot_tree.totalW
    plot_tree.yOff = 1.0
    plot_tree(in_tree, (0.5, 1.0), '')
    plt.show()


def main():
    pass


if __name__ == '__main__':
    main()
