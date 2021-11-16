#include <stdlib.h>
#include <stddef.h>

#include "avl_tree.h"

static int Max(int a, int b) {
    return a > b ? a : b;
}

static int Height(Position P) {
    return P == NULL ? -1 : P->Height;
}

static Position SingleRotateWithRight(Position k2) {
    Position k1;

    k1 = k2->Right;
    k2->Right = k1->Left;
    k1->Left = k2;
    k2->Height = Max(Height(k2->Left), Height(k2->Right)) + 1;
    k1->Height = Max(Height(k1->Left), Height(k1->Right)) + 1;
    return k1;
}

static Position SingleRotateWithLeft(Position k2) {
    Position k1;

    k1 = k2->Left;
    k2->Left = k1->Right;
    k1->Right = k2;
    k2->Height = Max(Height(k2->Left), Height(k2->Right)) + 1;
    k1->Height = Max(Height(k1->Left), Height(k1->Right)) + 1;
    return k1;
}

static Position DoubleRotateWithLeft(Position k3) {
    SingleRotateWithRight(k3->Left);
    return SingleRotateWithLeft(k3);
}

static Position DoubleRotateWithRight(Position k3) {
    SingleRotateWithLeft(k3->Right);
    return SingleRotateWithRight(k3);
}

AvlTree MakeEmpty(AvlTree T) {
    if (T != NULL) {
        MakeEmpty(T->Left);
        MakeEmpty(T->Right);
        free(T);
    }
    return NULL;
}

Position Find(ElementType X, AvlTree T) {
    while (T != NULL) {
        if (X < T->Element)
            T = T->Left;
        else if (X > T->Element)
            T = T->Right;
        else
            return T;
    }
    return NULL;
}

Position FindMin(AvlTree T) {
    if (T == NULL)
        return NULL;
    while (T->Left != NULL)
        T = T->Left;
    return T;
}

Position FindMax(AvlTree T) {
    if (T == NULL)
        return NULL;
    while (T->Right != NULL)
        T = T->Right;
    return T;
}

AvlTree Insert(ElementType X, AvlTree T) {
    if (T == NULL) {
        T = malloc(sizeof(AvlTree));
        if (T == NULL) {
            // do something
        } else {
            T->Element = X;
            T->Height = 0;
            T->Left = NULL;
            T->Right = NULL;
        }
    } else if (X < T->Element) {
        T->Left = Insert(X, T->Left);
        if (Height(T->Left) - Height(T->Right) == 2) {
            if (X < T->Left->Element)
                T = SingleRotateWithLeft(T);
            else
                T = DoubleRotateWithLeft(T);
        }
    } else if (X > T->Element) {
        T->Right = Insert(X, T->Right);
        if (Height(T->Right) - Height(T->Left) == 2) {
            if (X > T->Right->Element)
                T = SingleRotateWithRight(T);
            else
                T = DoubleRotateWithRight(T);
        }
    }
    T->Height = Max(Height(T->Left), Height(T->Right)) + 1;
    return T;
}

AvlTree Delete(ElementType X, AvlTree T) {
    return NULL;
}

ElementType Retrieve(Position P) {
    return P->Element;
}
