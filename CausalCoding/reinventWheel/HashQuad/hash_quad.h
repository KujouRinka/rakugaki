#ifndef DATA_STRUCTURES_AND_ALGORITHM_HASH_QUAD_H
#define DATA_STRUCTURES_AND_ALGORITHM_HASH_QUAD_H

#ifdef __cplusplus
extern "C" {
#endif


// 该散列表的假设：散列表大小至少为表中元素个数的两倍
#define MinTableSize 10

typedef unsigned int Index;
typedef Index Position;

typedef int ElementType;
typedef int ValueType;

struct HashTbl;
typedef struct HashTbl *HashTable;

HashTable InitializeTable(int TableSize);
void DestroyTable(HashTable H);
Position Find(ElementType Key, HashTable H);
void Insert(ElementType Key, ValueType Value, HashTable H);
ElementType Retrieve(Position P, HashTable H);
HashTable Rehash(HashTable H);

#ifdef __cplusplus
}
#endif
#endif //DATA_STRUCTURES_AND_ALGORITHM_HASH_QUAD_H
