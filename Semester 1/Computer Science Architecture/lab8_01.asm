bits 32 

global start        

extern exit, printf, scanf
import exit msvcrt.dll
import printf msvcrt.dll
import scanf msvcrt.dll

segment data use32 class=data
    
    store times 32 dd 0
    a dd 0
    b dd 0
    k dd 2
    doi dd 2
    message_a db "a=", 0
    format_a db "%d", 0
    message_b db "b=", 0
    format_b db "%d", 0
    format_result db "(a / b) * k = ", 0
    format_store db "%d", 0

segment code use32 class=code
    start:
        ; Two numbers a and b are given. Compute the expression value: (a/b)*k, where k is a constant value defined in data segment. 
        ; Display the expression value (in base 2).
        
        push dword message_a
        call [printf]
        add esp, 4*1
        
        push dword a
        push dword format_a
        call [scanf]
        add esp, 4*2
        
        push dword message_b
        call [printf]
        add esp, 4*1
        
        push dword b
        push dword format_b
        call [scanf]
        add esp, 4*2
        
        mov eax, [a]
        cdq
        div dword [b]
        mul dword [k]
       
        mov edi, store
        cld
        convert:
            cmp eax, 0
            je jump1
            cmp eax, 1
            je carry
            cmp eax, 511
            jle clear1
            mov edx, 0
            div dword[doi]
            back:
            push eax
            mov eax, edx
            stosd
            pop eax
        jmp convert
        clear1:
            div word[doi]
            mov ah, 0
            jmp back
        carry:
            stosd 
        jump1:
        
        push dword format_result
        call [printf]
        add esp, 4*1
        
        mov esi, store+124
        std
        mov bx, 32
        afisare:
            lodsd
            push eax
            push dword format_store
            call [printf]
            add esp, 4*2
            sub bx, 1
            cmp bx, 0
            je jump2
            jmp afisare
        jump2:
        
        push    dword 0
        call    [exit]
