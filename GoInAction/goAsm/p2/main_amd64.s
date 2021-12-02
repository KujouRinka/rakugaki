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
