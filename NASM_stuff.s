section .data
    string db "string is good", 10, 0

section .text
    global _start

_start:
    mov rsi, string
    call std__cout
    
    
    mov rax, 60
    mov rdi, 0
    syscall


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; printf (std::cout)
std__cout:
    ; rsi is holding the pointer to the string
    ; Save rsi's value for later
    push rsi

    ; Find the length of the string (null terminated)
    ; rdx will hold the length
    xor rdx, rdx
    strlen:
        mov al, [rsi]
        inc rdx
        inc rsi

        cmp al, 0
        jne strlen

    ; Get ready to make a system call
    mov rax, 1
    mov rdi, 1
    pop rsi
    syscall

    ret
    










