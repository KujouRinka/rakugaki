#ifndef DATA_STRUCTURES_AND_ALGORITHM_HASH_SEP_H
#define DATA_STRUCTURES_AND_ALGORITHM_HASH_SEP_H
// 分离链接法

#define MinTableSize 5
typedef int ElementType;
typedef int ValueType;

struct ListNode;
typedef struct ListNode *Position;
struct HashTbl;
typedef struct HashTbl *HashTable;

#ifdef __cplusplus
extern "C" {
#endif

HashTable InitializeTable(int TableSize);
void DestroyTable(HashTable H);
Position Find(ElementType Key, HashTable H);
void Insert(ElementType Key, ValueType Value, HashTable H);
void Delete(ElementType Key, HashTable H);
ElementType Retrieve(Position P);

#ifdef __cplusplus
}
#endif

#endif //DATA_STRUCTURES_AND_ALGORITHM_HASH_SEP_H
