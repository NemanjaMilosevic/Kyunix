[bits 32]

extern syscall
SYS_halt equ 8


section .text
align 4
GLOBAL halt
halt:
    push SYS_halt
    call syscall
    add esp,4
    ret

