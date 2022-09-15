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
    A dw 16,16,18,19
    a equ ($-A)/2
    B times a db 0

; our code starts here
segment code use32 class=code
    start:
        ; 
        
        mov ecx, a      ; ecx = a length
        mov esi, 0      ; esi = counter
        repeat1:
            mov ax, [A+esi+esi]     ; ax = takes the words from first to last
            push ecx                ; ecx = stack
            mov cl, 3               ; cl = 3
            shr ax, cl              ; shr 3 times
            mov [B+esi], al         ; mov the lowest part of word in B+next potion from 0
            pop ecx                 ; ecx out of stack
            inc esi                 ; esi = couter inc
        loop repeat1        
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
