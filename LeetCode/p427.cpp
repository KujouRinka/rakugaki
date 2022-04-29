/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        vp = &grid;
        Node *r = make(0, grid[0].size(), 0, grid.size());
        return r;
    }

    Node *make(int l, int r, int u, int d) {
        if (l + 1 == r) {
            auto n = new Node((*vp)[u][l], true);
            return n;
        }
        auto n = new Node;
        int ho_split = (l + r) / 2;
        int ve_split = (u + d) / 2;
        n->topLeft = make(l, ho_split, u, ve_split);
        n->topRight = make(ho_split, r, u, ve_split);
        n->bottomLeft = make(l, ho_split, ve_split, d);
        n->bottomRight = make(ho_split, r, ve_split, d);
        n->val = 1;
        if (n->topLeft->isLeaf && n->topRight->isLeaf && n->bottomLeft->isLeaf && n->bottomRight->isLeaf) {
            int v1 = n->topLeft->val, v2 = n->topRight->val, v3 = n->bottomLeft->val, v4 = n->bottomRight->val;
            if (v1 == v2 && v2 == v3 && v3 == v4) {
                n->isLeaf = true;
                n->val = v1;
                n->topLeft = n->topRight = n->bottomLeft = n->bottomRight = NULL;
                // should free memory here
            }
        }
        return n;
    }

    vector<vector<int>> *vp;
};

