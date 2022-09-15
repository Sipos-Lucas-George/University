; bits 32 

; global start        

; extern exit, printf
; import exit msvcrt.dll
; import printf msvcrt.dll

; segment data use32 class=data
    
    ; format db "%d", 0
    ; sir dd 1234a678h, 12785634h, 1a4d3c26h
    ; len equ ($-sir)/4
    ; sir2 times len dw 0
    
; segment code use32 class=code
    ; start:
    
        ; mov dh, 62h
        ; mov ch, 200
        ; sub dh, ch
        
        ; mov esi, sir
        ; mov edi, sir2
        
        ; cld
        ; mov ecx, len
        ; mov edx, 0
        ; repeta:
            ; push ecx
            ; lodsb
            ; lodsb
            ; mov bl, al
            ; lodsb
            ; lodsb
            ; mov bh, al
            ; stosw
            ; mov ecx, 16
            
            ; repeta2:
                ; shr bx, 1
                ; adc edx, 0
            ; loop repeta2
            
            ; pop ecx
        ; loop repeta
        
        ; push edx
        ; push dword format
        ; call [printf]
        ; add esp, 4*2
        
        ; push    dword 0
        ; call    [exit]
; bits 32 

; global start        

; extern exit
; import exit msvcrt.dll

; segment data use32 class=data

    ; a1 db '256'
    ; a2 dw 256, 256h
    ; a4 equ 1
    ; a5 db 256>>1, 256<<1
    ; a6 dw a5-a2, !(a5-a2)
    ; a8 dd 256h^256, 256256h
    ; a9 dd $-a9
    ; a10 db 256, -255
    ; a11 dw 256h-256
    ; a12 dw 256-256h
    ; a13 dw -256
    ; a14 dw -256h
    ; a15 db 2,5,6,25,6,2,56
    ; sir db '0123456789'
    
; segment code use32 class=code
    ; start:
    
        
        
        ; push    dword 0
        ; call    [exit]
bits 32 

global start        

extern exit, scanf, printf
import exit msvcrt.dll
import scanf msvcrt.dll
import printf msvcrt.dll

segment data use32 class=data

    n dd 0
    f db "%d",0
    s times 10 dd 0
    t dd 0
    z dd 10
    
segment code use32 class=code
    start:
        
        push dword n
        push dword f 
        call [scanf]
        add esp, 4*2
        
        mov ecx, [n]
        mov edi, s 
        repeta:
            push ecx
            push dword t 
            push dword f 
            call [scanf]
            add esp, 4*2
            mov eax, [t]
            stosd
            pop ecx
        loop repeta
        
        mov ecx, [n]
        mov esi, s
        mov ebx, 0
        repeta2:
            lodsd
            push ecx
            mov ecx, 5
            repeta3
                mov edx, 0
                div dword[z]
                test edx, 01h
                jnz after
                add ebx, edx
                after:
            loop repeta3
            pop ecx
        loop repeta2
        
        push ebx
        push dword f 
        call [printf]
        add esp, 4*2
        push    dword 0
        call    [exit]
