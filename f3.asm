
SECTION .text

GLOBAL f3
f3:
    push ebp
    mov ebp, esp
    finit
    fld qword[esp + 8]
    fchs
    fldl2e
    fmulp
    frndint
    fld1
    fscale
    fld qword[esp + 8]
    fchs
    fldl2e
    fmulp
    fld qword[esp + 8]
    fchs
    fldl2e
    fmulp
    frndint
    fsubp
    f2xm1
    fld1
    fadd
    fmulp
    leave
    ret
    
