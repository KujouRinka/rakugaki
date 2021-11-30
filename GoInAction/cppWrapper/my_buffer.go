package main

import (
	"reflect"
	"unsafe"
)

type MyBuffer struct {
	cPtr *cgoMyBuffer
}

func NewMyBuffer(size int) *MyBuffer {
	return &MyBuffer{
		cPtr: cgoNewMyBuffer(size),
	}
}

func (p *MyBuffer) Delete() {
	cgoDeleteMyBuffer(p.cPtr)
}

func (p *MyBuffer) Data() []byte {
	data := cgoMyBufferData(p.cPtr)
	size := cgoMyBufferSize(p.cPtr)
	var b []byte
	bHeader := (*reflect.StringHeader)(unsafe.Pointer(&b))
	bHeader.Data = uintptr(unsafe.Pointer(data))
	bHeader.Len = int(size)
	return b
}
