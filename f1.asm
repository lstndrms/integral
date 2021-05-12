SECTION .text

GLOBAL f1
f1:
    push ebp
    mov ebp, esp
    finit   
    fld qword[esp+8]
    fld1
    fsub
    fst st1
    fmulp
    fld1
    faddp
    push dword 3
    fild dword[esp]
    add esp, 4
    fxch
    fdivp
    leave
    ret