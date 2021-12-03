#include "textflag.h"

// func main()
TEXT ·main(SB),$8-0
    MOVQ $10, 0(SP)     // a = 10
    CALL ·printNum(SB)
    MOVQ 0(SP), AX      // AX = a
    MOVQ 0(SP), BX      // BX = a
    ADDQ BX, AX         // AX += BX
    MULQ BX             // AX *= BX
    MOVQ AX, 0(SP)      // b = AX
    CALL ·printNum(SB)
    RET

// func If(ok bool, a, b int) int
TEXT ·If(SB),NOSPLIT,$0-32
    MOVBQZX ok+0(FP), BX
    CMPB BX, $0
    JE R
    MOVQ a+8(FP), AX
    JMP L
R:
    MOVQ b+16(FP), AX
L:
    MOVQ AX, ret+24(FP)
    RET
