#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_sep.h"

struct ListNode {
    ElementType Element;
    ValueType Value;
    Position Next;
};

typedef Position List;
typedef int Index;

struct HashTbl {
    int TableSize;
    List *TheLists;     // pointer point to head node of ListNode
};

void FatalError(const char *msg) {
    printf("%s\n", msg);
    exit(1);
}

Index Hash(ElementType Key, int TableSize) {
    return Key % TableSize;
}

HashTable InitializeTable(int TableSize) {
    HashTable H;

    if (TableSize < MinTableSize) {
        printf("Table size too small\n");
        return NULL;
    }

    H = (HashTable) malloc(sizeof(struct HashTbl));
    if (H == NULL)
        FatalError("out of space");
    H->TableSize = TableSize;
    H->TheLists = (List *) malloc(sizeof(List) * TableSize);
    if (H->TheLists == NULL)
        FatalError("out of space");
    for (int i = 0; i < TableSize; ++i) {
        H->TheLists[i] = (List) malloc(sizeof(struct ListNode));
        if (H->TheLists[i] == NULL)
            FatalError("out of space");
        else
            H->TheLists[i]->Next = NULL;
    }
    return H;
}

void DestroyTable(HashTable H) {
    for (int i = 0; i < H->TableSize; ++i) {
        Position Current = H->TheLists[i];
        while (Current != NULL) {
            Position tmp = Current->Next;
            free(Current);
            Current = tmp;
        }
    }
    free(H->TheLists);
    free(H);
}

Position Find(ElementType Key, HashTable H) {
    List L = H->TheLists[Hash(Key, H->TableSize)];
    Position P = L->Next;

    while (P != NULL && P->Element != Key)
        P = P->Next;
    return P;
}

void Insert(ElementType Key, ValueType Value, HashTable H) {
    Position Pos = Find(Key, H);

    if (Pos == NULL) {
        Position NewCell = (Position) malloc(sizeof(struct ListNode));
        if (NewCell == NULL) {
            FatalError("out of space");
        } else {
            List L = H->TheLists[Hash(Key, H->TableSize)];
            NewCell->Next = L->Next;
            NewCell->Element = Key;
            NewCell->Value = Value;
            L->Next = NewCell;
        }
    }
}

void Delete(ElementType Key, HashTable H) {
    Position Pos = Find(Key, H);
    if (Pos != NULL) {
        if (Pos->Next != NULL) {
            Position tmp = Pos->Next;
            Pos->Element = tmp->Element;
            Pos->Value = tmp->Value;
            Pos->Next = tmp->Next;
            free(tmp);
        } else {
            List L = H->TheLists[Hash(Key, H->TableSize)];
            while (L->Next->Element != Key)
                L = L->Next;
            L->Next = Pos->Next;
            free(Pos);
        }
    }
}

ValueType Retrieve(Position P) {
    return P == NULL ? 0 : P->Value;
}
