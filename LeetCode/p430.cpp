/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
private:
    static void link(Node *n1, Node *n2) {
        n1->next = n2;
        if (n2 != nullptr)
            n2->prev = n1;
    }
    
    static void visit(Node *head, Node *&cur) {
        while (head != nullptr) {
            cur = head;
            Node *headNext = head->next;
            if (head->child != nullptr) {
                Node *chTp = head->child;
                link(head, chTp);
                visit(head->child, cur);
                link(cur, headNext);
            }
            head->child = nullptr;
            head = headNext;
        }
    }

public:
    Node* flatten(Node* head) {
        Node *cur = head;
        visit(head, cur);
        return head;
    }
};
