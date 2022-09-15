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
    
    M dd 10011011010101001010101001010110b
    MNew dd 0b

; our code starts here
segment code use32 class=code
    start:
        ; Given the doubleword M, compute the doubleword MNew as follows:
        ;the bits 0-3 a of MNew are the same as the bits 5-8 a of M.
        ;the bits 4-7 a of MNew have the value 1
        ;the bits 27-31 a of MNew have the value 0
        ;the bits 8-26 of MNew are the same as the bits 8-26 a of M.
        
        mov EBX,0    ; EBX = 0
        mov EAX, [M]   ; EAX = [M]
        and EAX, 00000000000000000000000111100000b   ; we isolate bits 5-8
        mov CL, 5
        shr EAX, CL  ; EAX = 00000000000000000000000000000010b , CF=0
        or EBX, EAX   ; EBX = 00000000000000000000000000000010b
        
        or EBX, 00000000000000000000000011110000b    ; EBX = 00000000000000000000000011110010b
        
        mov EAX, [M]
        and EAX, 00000111111111111111111100000000b   ;we isolate bits 8-26
        or EBX, EAX
        
        mov [MNew], EBX     ; MNew = 00000011010101001010101011110010b
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
