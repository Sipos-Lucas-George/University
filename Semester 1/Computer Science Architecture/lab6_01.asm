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
    A dd 12345678h, 98675342h, 36754890h, 17349802h
    a equ ($-A)/4
    B times a dd 0

; our code starts here
segment code use32 class=code
    start:
        ; Being given a string of doublewords, build another string of doublewords which will include only the doublewords 
        ; from the given string which have an even number of bits with the value 1.
        
        mov ecx, a
        mov esi, A
        mov edi, B
        cld
        repeat1:
            lodsd
            add eax, 0
            jpo jump
            stosd
            jump:
        loop repeat1
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
