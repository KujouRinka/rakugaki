//
// Created by KujouRinka on 2021/3/28.
//

// uva12657

#include <iostream>
#include <vector>
#include <stack>

using namespace std;
namespace uva12657v1 {
    using COL = vector<int>;

    int leftNode[100005];
    int rightNode[100005];
    COL value;
    stack<int> allocNode;

    void init() {
        leftNode[0] = -1;
        leftNode[1] = 0;
        rightNode[0] = 1;
        rightNode[1] = -1;
        value = {-1, -1};
        stack<int> empty;
        allocNode.swap(empty);
    }

    void del(int cursor) {
        rightNode[leftNode[cursor]] = rightNode[cursor];
        leftNode[rightNode[cursor]] = leftNode[cursor];
        value[cursor] = -1;
        allocNode.push(cursor);
    }

    void insert(int cursor, int var) {
        int allocID;
        if (allocNode.empty()) {
            allocID = value.size();
            value.push_back(var);
        } else {
            allocID = allocNode.top();
            allocNode.pop();
            value[allocID] = var;
        }

        leftNode[allocID] = cursor;
        rightNode[allocID] = rightNode[cursor];
        leftNode[rightNode[cursor]] = allocID;
        rightNode[cursor] = allocID;
    }

    int find(int var) {
        int cursor = -1;
        for (const auto &i : value)
            if (++cursor && i == var)
                return cursor;
        return -1;
    }

    int BoxesInALinev1() {

        int CASE = 0;
        int n;
        int instrNum;
        while (cin >> n >> instrNum) {

            init();
            uint8_t reversed = 0;
            int s = 0;
            for (int i = 1; i <= n; i++) {
                insert(s, i);
                s = rightNode[s];
            }

            int instr, o1, o2;
            int cursor1, cursor2;
            for (int i = 0; i < instrNum; ++i) {
                cin >> instr;
                if (instr == 4)  // reverse
                    reversed = ~reversed;
                else {
                    cin >> o1 >> o2;
                    cursor1 = find(o1);
                    cursor2 = find(o2);
                    if (instr == 1) {
                        if (reversed) {
                            if (cursor1 == rightNode[cursor2]) continue;
                            insert(cursor2, value[cursor1]);
                        } else {
                            if (cursor1 == leftNode[cursor2]) continue;
                            insert(leftNode[cursor2], value[cursor1]);
                        }
                        del(cursor1);
                    } else if (instr == 2) {
                        if (reversed) {
                            if (cursor1 == leftNode[cursor2]) continue;
                            insert(leftNode[cursor2], value[cursor1]);
                        } else {
                            if (cursor1 == rightNode[cursor2]) continue;
                            insert(cursor2, value[cursor1]);
                        }
                        del(cursor1);
                    } else {
                        int tmp = value[cursor1];
                        value[cursor1] = value[cursor2];
                        value[cursor2] = tmp;
                    }
                }
            }

            uint16_t counter = 0;
            long long sum = 0;
            if (reversed) {
                int cursor = leftNode[1];
                do {
                    ++counter;
                    if (counter & 1)
                        sum += value[cursor];
                } while ((cursor = leftNode[cursor]) != -1 && value[cursor] != -1);
            } else {
                int cursor = rightNode[0];
                do {
                    ++counter;
                    if (counter & 1)
                        sum += value[cursor];
                } while ((cursor = rightNode[cursor]) != -1 && value[cursor] != -1);
            }

            cout << "Case " << ++CASE << ": " << sum << endl;
        }
        return 0;
    }
}

namespace uva12657v2 {
    struct Node {
        int left;
        int right;
    };

    Node node[100005];

    void link(int L, int R) {
        node[L].right = R;
        node[R].left = L;
    }

    void init(int n) {
        int upper = n + 1;
        for (int i = 0; i < upper; ++i)
            link(i, i + 1);
        node[0].left = -1;
        node[n + 1].right = -1;
    }

    int BoxesInALine() {

        int n, instrNum;
        int CASE = 0;
        while (cin >> n >> instrNum) {
            init(n);

            bool reversed = false;
            while (instrNum--) {
                int op, o1, o2;
                cin >> op;

                if (op == 4)   // reverse
                    reversed = !reversed;
                else {
                    cin >> o1 >> o2;
                    if (reversed)
                        op = 3 - op;
                    if (op == 1) {  // o1 -> o2
                        if (node[o2].left == o1)
                            continue;
                        link(node[o1].left, node[o1].right);
                        link(node[o2].left, o1);
                        link(o1, o2);
                    } else if (op == 2) {   // o2 -> o1
                        if (node[o2].right == o1)
                            continue;
                        link(node[o1].left, node[o1].right);
                        link(o1, node[o2].right);
                        link(o2, o1);
                    } else {    // o1 <-> o2
                        if (node[o1].left == o2) {
                            link(node[o2].left, o1);
                            link(o2, node[o1].right);
                            link(o1, o2);
                        } else if (node[o1].right == o2) {
                            link(node[o1].left, o2);
                            link(o1, node[o2].right);
                            link(o2, o1);
                        } else {
                            int o1l = node[o1].left;
                            int o1r = node[o1].right;
                            int o2l = node[o2].left;
                            int o2r = node[o2].right;
                            link(o1l, o2);
                            link(o2, o1r);
                            link(o2l, o1);
                            link(o1, o2r);
                        }
                    }
                }
            }

            long long sum = 0;
            int counter = 0;
            if (reversed) {
                int c = n + 1;
                while ((c = node[c].left) && c != 0) {
                    ++counter;
                    if (counter & 1)
                        sum += c;
                }
            } else {
                int c = 0;
                while ((c = node[c].right) && c != n + 1) {
                    ++counter;
                    if (counter & 1)
                        sum += c;
                }
            }
            cout << "Case " << ++CASE << ": " << sum << endl;
        }
        return 0;
    }
}
