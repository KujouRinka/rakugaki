/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    Node *treeToDoublyList(Node *root) {
        if (root == nullptr)
            return nullptr;
        auto[head, tail] = toChain(root);
        head->left = tail;
        tail->right = head;
        return head;
    }

private:

    pair<Node *, Node *> toChain(Node *node) {
        Node *head, *tail;
        if (node->left) {
            auto[head_l, tail_l] = toChain(node->left);
            head = head_l;
            tail_l->right = node;
            node->left = tail_l;
        } else {
            head = node;
        }
        if (node->right) {
            auto[head_r, tail_r] = toChain(node->right);
            tail = tail_r;
            head_r->left = node;
            node->right = head_r;
        } else {
            tail = node;
        }
        return {head, tail};
    }
};

