#include "textflag.h"

// func LoopAdd(cnt, v0, step int) int
TEXT ·LoopAdd(SB),NOSPLIT,$0-32
    MOVQ $0, CX             // CX = 0
    MOVQ cnt+0(FP), BX      // BX = cnt
    MOVQ v0+8(FP), AX       // AX = v0
    MOVQ step+16(FP), R8    // R8 = step
LOOP_IF:
    CMPQ CX, BX
    JGE LOOP_END
    // do something
    ADDQ R8, AX
    ADDQ $1, CX
    JMP LOOP_IF
LOOP_END:
    MOVQ AX, ret+24(FP)
    RET
