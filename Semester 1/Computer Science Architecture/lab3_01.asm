bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    a db 2
    b dw 3
    c dd 4
    d dq 5

; our code starts here
segment code use32 class=code
    start:
        ; (a + b + c) - d + (b - c)
        
        mov AL, [a]     ; AL = a
        cbw             ; AX = AL
        add AX, [b]     ; AX = AX + [b]
        
        cwde            ; EAX = AX
        add EAX, [c]    ; EAX = EAX + [c]
        
        cdq             ; EDX:EAX = EAX
        sub EAX, [d]    
        sbb EDX, [d+4]  ; EDX:EAX = (a + b + c) - d
        
        mov EBX, EAX    ; EBX = EAX
        
        mov AX, [b]     ; AX = [b]
        cwde            ; EAX = AX
        sub EAX, [c]    ; EAX = EAX - [c]
        
        add EAX, EBX    ; EAX = EAX + EBX
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
