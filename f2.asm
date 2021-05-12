
SECTION .text

GLOBAL f2
f2:
    push ebp
    mov ebp, esp
    finit   
    fld1
    fld1
    faddp
    fld1
    fxch
    fdivp
    fld qword[esp+8]
    faddp
    fsqrt
    fstp
    leave
    ret
    