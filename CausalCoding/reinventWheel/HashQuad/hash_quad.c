#include <stdio.h>
#include <stdlib.h>

#include "hash_quad.h"

enum KindOfEntry {
    Legitimate = 0, Empty, Deleted,
};

struct HashEntry {
    ElementType Element;
    ValueType Value;
    enum KindOfEntry Info;
};

typedef struct HashEntry Cell;

struct HashTbl {
    int TableSize;
    Cell *TheCells;
};

void FatalError(const char *msg) {
    printf("%s\n", msg);
    exit(1);
}

Index Hash(ElementType Key, int TableSize) {
    return Key % TableSize;
}

int NextPrime(int TableSize) {
    // TODO implement this function.
    return TableSize;
}

HashTable InitializeTable(int TableSize) {
    if (TableSize < MinTableSize) {
        printf("Table size too small\n");
        return NULL;
    }

    HashTable H = (HashTable) malloc(sizeof(struct HashTbl));
    if (H == NULL)
        FatalError("out of space");
    TableSize = NextPrime(TableSize);
    H->TheCells = (Cell *) malloc(sizeof(Cell) * TableSize);
    if (H->TheCells == NULL)
        FatalError("out of space");

    for (int i = 0; i < TableSize; ++i)
        H->TheCells[i].Info = Empty;
    return H;
}

void DestroyTable(HashTable H) {
    free(H->TheCells);
    free(H);
}

Position Find(ElementType Key, HashTable H) {
    int CollisionNum = 0;
    Position CurrentPos = Hash(Key, H->TableSize);
    while (H->TheCells[CurrentPos].Info != Empty &&
           H->TheCells[CurrentPos].Element != Key) {
        CurrentPos += 2 * ++CollisionNum - 1;
        if (CurrentPos >= H->TableSize)
            CurrentPos -= H->TableSize;
    }
    return CurrentPos;
}

void Insert(ElementType Key, ValueType Value, HashTable H) {
    Position Pos = Find(Key, H);
    if (H->TheCells[Pos].Info != Legitimate) {
        H->TheCells[Pos].Info = Legitimate;
        H->TheCells[Pos].Element = Key;
        H->TheCells[Pos].Value = Value;
    }
}

ElementType Retrieve(Position P, HashTable H) {
    return H->TheCells[P].Value == Legitimate ? H->TheCells[P].Value : 0;
}

HashTable Rehash(HashTable H) {
    return NULL;
}
