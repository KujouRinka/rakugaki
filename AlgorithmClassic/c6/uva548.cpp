//
// Created by KujouRinka on 2021/3/28.
//

#include <iostream>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

// uva548
namespace uva548v1 {
    vector<int> inOrder;
    vector<int> postOrder;
    map<int, int> res;

    struct Node {
        int value;
        Node *left;
        Node *right;

        explicit Node(int newValue) : value(newValue), \
                    left(nullptr), right(nullptr) {}
    };

    int findIndex(const int &value) {
        int i = 0;
        for (const auto &ele : inOrder) {
            if (value == ele)
                return i;
            ++i;
        }
        return -1;
    }

    Node *newNode(int nodeValue) {
        return new Node(nodeValue);
    }

    Node *makeTree(int lower, int upper, int headPtr) {
        if (lower < 0 || upper >= inOrder.size() || lower > upper)
            return nullptr;
        if (lower == upper)
            return newNode(inOrder[lower]);

        int thisValue = postOrder[headPtr];
        int headPos = findIndex(thisValue);
        int rightNum = upper - headPos;
        // find this value

        Node *head = newNode(thisValue);
        head->left = makeTree(lower, headPos - 1, headPtr - rightNum - 1);
        head->right = makeTree(headPos + 1, upper, headPtr - 1);
        return head;
    }

    void visitTree(Node *root, int sum) {
        if (root == nullptr)
            return;
        int nextValue = sum + root->value;
        Node *left = root->left, *right = root->right;
        visitTree(left, nextValue);
        visitTree(right, nextValue);
        if (left == nullptr && right == nullptr)
            res[root->value] = nextValue;
    }

    int TreeV1() {
        string buffer;
        bool flag = true;
        while (getline(cin, buffer)) {
            stringstream ss(buffer);
            int var;
            while (ss >> var)
                flag ? inOrder.push_back(var) : postOrder.push_back(var);
            flag = !flag;
            if (flag) {
                Node *root = newNode(-1), *realRoot;
                root->left = makeTree(0, inOrder.size() - 1, postOrder.size() - 1);
                realRoot = root->left;
                visitTree(realRoot, 0);

                int minTree;
                int min = 10000;
                for (auto &re : res)
                    if (re.second < min || (re.second == min && re.first < minTree)) {
                        min = re.second;
                        minTree = re.first;
                    }
                res.clear();
                inOrder.clear();
                postOrder.clear();
                cout << minTree << endl;
            }
        }
        return 0;
    }
}

namespace uva548v2 {
    struct TreeNode {
        int value;
        TreeNode *left;
        TreeNode *right;

        explicit TreeNode(int newValue) : value(newValue),
                                          left(nullptr), right(nullptr) {}
    };

    int inOrder[10005] = {0};
    int postOrder[10005] = {0};
    int leaveValue = 1000;
    int minSum = 0x7fffffff;

    TreeNode *newNode(int newValue) {
        return new TreeNode(newValue);
    }

    int find(int value, int lower, int upper) {
        for (int i = lower; i <= upper; ++i)
            if (inOrder[i] == value)
                return i;
        return -1;
    }

    TreeNode *makeTree(int inOrderLower, int inOrderUpper,
                       int postOrderLower, int postOrderUpper) {
        if (inOrderLower == inOrderUpper)
            return newNode(inOrder[inOrderLower]);
        if (inOrderLower > inOrderUpper)
            return nullptr;

        TreeNode *thisNode = newNode(postOrder[postOrderUpper]);
        int thisPos = find(postOrder[postOrderUpper], inOrderLower, inOrderUpper);
        int nextLeftTreeUpper = postOrderUpper - (inOrderUpper - thisPos) - 1;
        thisNode->left = makeTree(inOrderLower, thisPos - 1, postOrderLower, nextLeftTreeUpper);
        thisNode->right = makeTree(thisPos + 1, inOrderUpper, nextLeftTreeUpper + 1, postOrderUpper - 1);
        return thisNode;
    }

    void visitTree(TreeNode *root, int sum) {
        sum += root->value;
        if (!root->left && !root->right) {
            if (sum < minSum || (sum == minSum && root->value < leaveValue)) {
                minSum = sum;
                leaveValue = root->value;
            }
        }
        if (root->left)
            visitTree(root->left, sum);
        if (root->right)
            visitTree(root->right, sum);
    }

    int Tree() {
        int newValue;
        int ch;
        int ptr = 0;

        while (scanf("%d", &newValue) == 1) {
            inOrder[ptr++] = newValue;
            ch = getchar();
            while (ch != '\n') {
                scanf("%d", &newValue);
                inOrder[ptr++] = newValue;
                ch = getchar();
            }
            for (int i = 0; i < ptr; ++i)
                scanf("%d", postOrder + i);

            TreeNode *root = makeTree(0, ptr - 1, 0, ptr - 1);

            leaveValue = 1000;
            minSum = 0x7fffffff;
            visitTree(root, 0);
            // should free TreeNode here;
            printf("%d\n", leaveValue);

            ptr = 0;
        }
        return 0;
    }
}
