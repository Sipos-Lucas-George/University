bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    a dd 2
    b db 3
    c db 4
    d db 5
    x dq 6

; our code starts here
segment code use32 class=code
    start:
        ; a-(7+x)/(b*b-c/d+2); a-doubleword; b,c,d-byte; x-qword
    
        mov AL, [b]     ; AL = [b]
        mul byte[b]    ; AX = AL * [b]
        mov BX, AX      ; BX = AX
        
        mov AL, [c]     ; AL = [c]
        cbw             ; AX = AL
        idiv byte[d]    ; AL = AX / [d] , AH = AX % [d]
        
        cbw             ; AX = AL
        sub BX, AX      ; BX = BX - AX
        add BX, 2       ; BX = BX + 2
        
        mov EAX, 7      ; EAX = 7
        cdq             ; EDX:EAX = EAX
        add EAX, [x]    ; EAX = EAX + [x]
        adc EDX, [x+4]  ; EDX = EDX + [x+4]
        
        mov ECX, EAX    ; ECX = EAX
        mov AX, BX      ; AX = BX
        cwde            ; EAX = AX
        mov EBX, EAX    ; EBX = EAX
        mov EAX, ECX    ; EAX = ECX
        
        idiv EBX        ; EAX = EDX:EAX / EBX , EDX = EDX:EAX % EBX
        
        mov EBX, [a]    ; EBX = [a]
        sub EBX, EAX    ; EBX = EBX - EAX
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
