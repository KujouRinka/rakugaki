package main

/*
#cgo CXXFLAGS: -std=c++11

#include "my_buffer_capi.h"
*/
import "C"

type cgoMyBuffer C.MyBuffer_T

func cgoNewMyBuffer(size int) *cgoMyBuffer {
	p := C.NewMyBuffer(C.int(size))
	return (*cgoMyBuffer)(p)
}

func cgoDeleteMyBuffer(p *cgoMyBuffer) {
	C.DeleteMyBuffer((*C.MyBuffer_T)(p))
}

func cgoMyBufferData(p *cgoMyBuffer) *C.char {
	return C.MyBufferData((*C.MyBuffer_T)(p))
}

func cgoMyBufferSize(p *cgoMyBuffer) C.int {
	return C.MyBufferSize((*C.MyBuffer_T)(p))
}
