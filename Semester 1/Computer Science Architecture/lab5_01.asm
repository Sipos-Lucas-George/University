bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; 
    
    A db 2, 1, -3, 0
    a equ $-A
    B db 4, 5, 7, 6, 2, 1
    b equ $-B
    R times a+b db 0
    
; our code starts here
segment code use32 class=code
    start:
        ; Two byte strings A and B are given. Obtain the string R by concatenating the elements of B in reverse order and the elements of A in reverse order.
        ;Example:
        ;A: 2, 1, -3, 0
        ;B: 4, 5, 7, 6, 2, 1
        ;R: 1, 2, 6, 7, 5, 4, 0, -3, 1, 2
        
        mov ecx, b              ; length of B
        mov esi, 0              
        repeat1:
            mov al, [B+ecx-1]   ; al = last number of B
            mov [R+esi], al     ; R + position = al
            inc esi
        loop repeat1
        
        mov ecx, a              ; length of A
        mov esi, 0
        repeat2:
            mov al, [A+ecx-1]   ; al = last number of A
            mov [R+b+esi], al   ; R + length of B + position = al
            inc esi
        loop repeat2
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
