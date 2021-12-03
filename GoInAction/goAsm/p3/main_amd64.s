#include "textflag.h"

// func main()
TEXT ·main(SB),$16-0
    MOVQ $2, 0(SP)  // a = 2
    MOVQ $3, +8(SP) // b = 3
    CALL ·printSum(SB)
    RET

// func printSum(a, b int)
TEXT ·printSum(SB),$24-16
    MOVQ a+0(FP), BX
    MOVQ BX, 0(SP)
    MOVQ b+8(FP), BX
    MOVQ BX, +8(SP)
    CALL ·sum(SB)
    MOVQ t-8(SP), BX
    MOVQ BX, 0(SP)
    CALL ·printNum(SB)
    RET

// func sum(a, b int) int
TEXT ·sum(SB),NOSPLIT,$0-24
    MOVQ a+0(FP), AX    // AX = a
    ADDQ a+8(FP), AX    // AX += b
    MOVQ AX, a+16(FP)   // ret = AX
    RET
