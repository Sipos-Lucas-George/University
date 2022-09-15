bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    a db 2
    b db 3
    c db 4
    d dw 320
; our code starts here
segment code use32 class=code
    start:
        ;(10*a-5*b)+(d-5*c)
        
        mov AL, 10
        mul byte[a]
        mov BX, AX
        
        mov AL, 5
        mul byte[b]
        neg AX
        
        add BX, AX
        
        mov AL, 5
        mul byte[c]
        neg AX
        
        add AX, [d]
        
        add AX, BX
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
