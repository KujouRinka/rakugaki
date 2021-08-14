/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node *copyRandomList(Node *head) {
        map<Node *, Node *> nodeMap;

        for (Node *now = head; now != nullptr; now = now->next)
            nodeMap[now] = new Node(now->val);

        for (auto &nodePair : nodeMap) {
            nodePair.second->next = nodeMap[nodePair.first->next];
            nodePair.second->random = nodeMap[nodePair.first->random];
        }

        return nodeMap[head];
    }
};
