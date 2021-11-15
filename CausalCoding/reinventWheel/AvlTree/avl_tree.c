#include <stdlib.h>
#include <stddef.h>

#include "avl_tree.h"

static int Max(int a, int b) {
    return a > b ? a : b;
}

static int Height(Position P) {
    return P == NULL ? -1 : P->Height;
}

static Position SingleRotateWithRight(Position k1) {

}

static Position SingleRotateWithLeft(Position k2) {

}

static Position DoubleRotateWithLeft(Position k3) {

}

static Position DoubleRotateWithRight(Position k3) {

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
