#ifndef my_buffer_capi
#define my_buffer_capi

typedef struct MyBuffer_T MyBuffer_T;

MyBuffer_T *NewMyBuffer(int size);
void DeleteMyBuffer(MyBuffer_T *p);

char *MyBufferData(MyBuffer_T *p);
int MyBufferSize(MyBuffer_T *p);
#endif
