//
// Created by kujou on 11/15/2021.
//

#ifndef DATA_STRUCTURES_AND_ALGORITHM_AVL_TREE_H
#define DATA_STRUCTURES_AND_ALGORITHM_AVL_TREE_H

typedef int ElementType;
struct AvlNode;
typedef struct AvlNode *Position;
typedef struct AvlNode *AvlTree;

AvlTree MakeEmpty(AvlTree T);
Position Find(ElementType X, AvlTree T);
Position FindMin(AvlTree T);
Position FindMax(AvlTree T);
AvlTree Insert(ElementType X, AvlTree T);
AvlTree Delete(ElementType X, AvlTree T);
ElementType Retrieve(Position P);

struct AvlNode {
    ElementType Element;
    AvlTree Left;
    AvlTree Right;
    int Height;
};

#endif //DATA_STRUCTURES_AND_ALGORITHM_AVL_TREE_H
