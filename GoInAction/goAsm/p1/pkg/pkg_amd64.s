#include "textflag.h"

// var Int32Value int32 = 114514
GLOBL ·Int32Value(SB),NOPTR,$4
DATA ·Int32Value+0(SB)/4,$0x01bf52

// var Uint32Value uint32 = 2333
GLOBL ·Uint32Value(SB),NOPTR,$4
DATA ·Uint32Value+0(SB)/1,$0x1d
DATA ·Uint32Value+1(SB)/1,$0x09
DATA ·Uint32Value+2(SB)/1,$0x00
DATA ·Uint32Value+3(SB)/1,$0x00

// var Float32Value float32 = 1.5
GLOBL ·Float32Value(SB),NOPTR,$4
DATA ·Float32Value+0(SB)/4,$1.5

// var Float64Value float64 = 2.33
GLOBL ·Float64Value(SB),NOPTR,$8
DATA ·Float64Value+0(SB)/8,$2.333

// var NumSlice [2]int = {42, 44}
GLOBL ·NumSlice(SB),NOPTR,$16
DATA ·NumSlice+0(SB)/8,$42
DATA ·NumSlice+8(SB)/8,$44

// var BoolValue bool
GLOBL ·BoolValue(SB),NOPTR,$1

// var TrueValue bool = true
GLOBL ·TrueValue(SB),NOPTR,$1
DATA ·TrueValue+0(SB)/1,$1

// var FalseValue bool = false
GLOBL ·FalseValue(SB),NOPTR,$1
DATA ·FalseValue+0(SB)/1,$0

// var HelloWorld string = "hello world"
GLOBL ·HelloWorld(SB),NOPTR,$16
GLOBL text<>(SB),RODATA|DUPOK,$16

DATA text<>+0(SB)/8,$"hello wo"
DATA text<>+8(SB)/8,$"rld"

DATA ·HelloWorld+0(SB)/8,$text<>(SB)    // StringHeader.Data
DATA ·HelloWorld+8(SB)/8,$11              // StringHeader.Len = 11

// var AsmSlice []byte = []byte("what's this?")
GLOBL ·AsmSlice(SB),NOPTR,$24
GLOBL slicedata<>(SB),NOPTR,$16

DATA slicedata<>+0(SB)/8,$"what's t"
DATA slicedata<>+8(SB)/8,$"his?"

DATA ·AsmSlice+0(SB)/8,$slicedata<>(SB)
DATA ·AsmSlice+8(SB)/8,$12
DATA ·AsmSlice+16(SB)/8,$16
