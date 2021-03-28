//
// Created by KujouRinka on 2021/3/28.
//

// uva122

#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

namespace uva122 {
    struct Node {
        int value;
        bool active;
        Node *left;
        Node *right;

        Node() : active(false), left(nullptr), right(nullptr) {}
    };

    queue<Node *> tmpStore;
    vector<int> resV;
    int v;
    char buffer[300];
    Node *root = nullptr;
    bool sta;

    void insertTree(int value, char *posMark);

    Node *newNode() {
        return new (Node);
    }

    void readInfo() {
        sta = true;
        queue<Node *> empty;
        tmpStore.swap(empty);
        resV.clear();
        root = newNode();
        while (true) {
            if (scanf("%s", buffer) != 1)
                exit(0);
            if (!strcmp(buffer, "()"))
                return;
            sscanf(buffer + 1, "%d", &v);
            insertTree(v, strchr(buffer, ',') + 1);
            if (!sta) {
                printf("not complete\n");
                int ch;
                while ((ch = getchar()) != '\n');
                return;
            }
        }
    }

    void insertTree(int value, char *posMark) {
        char ch;
        Node *thisPtr = root;
        while (ch = *posMark++) {
            if (ch == 'L') {
                if (thisPtr->left == nullptr)
                    thisPtr->left = newNode();
                thisPtr = thisPtr->left;
            } else if (ch == 'R') {
                if (thisPtr->right == nullptr)
                    thisPtr->right = newNode();
                thisPtr = thisPtr->right;
            } else
                break;
        }
        if (thisPtr->active) {
            sta = false;
            return;
        }
        thisPtr->value = value;
        thisPtr->active = true;
        sta = true;
    }

    void traversTree() {
        Node *thisPtr = root;
        tmpStore.push(thisPtr);
        while (!tmpStore.empty()) {
            thisPtr = tmpStore.front();
            tmpStore.pop();
            if (!thisPtr->active) {
                printf("not complete\n");
                sta = false;
                return;
            }
            resV.push_back(thisPtr->value);
            if (thisPtr->left != nullptr)
                tmpStore.push(thisPtr->left);
            if (thisPtr->right != nullptr)
                tmpStore.push(thisPtr->right);
        }
        printf("%d", resV[0]);
        for (int i = 1; i != resV.size(); ++i)
            printf(" %d", resV[i]);
        printf("\n");
    }

    int TreeOfLevel() {
        while (true) {
            readInfo();
            if (sta)
                traversTree();
            // should delete node here
        }
        return 0;
    }
}
