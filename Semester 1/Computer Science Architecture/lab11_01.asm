bits 32 

global start        

extern exit, printf, scanf
import exit msvcrt.dll
import printf msvcrt.dll
import scanf msvcrt.dll

%include "change.asm"

segment data use32 class=data

    s1 times 51 db 0
    s2 times 51 db 0
    message db "s1 = ", 0
    format db "%s", 0
    display db "s2 = %s", 0

segment code use32 class=code
    start:
        ; Read a string s1 (which contains only lowercase letters). Using an alphabet (defined in the data segment), 
        ; determine and display the string s2 obtained by substitution of each letter of the string s1 with the corresponding letter in the given alphabet.
        ; Example:
        ; The alphabet:  OPQRSTUVWXYZABCDEFGHIJKLMN
        ; The string s1: anaaremere
        ; The string s2: OBOOFSASFS
        
        push dword message
        call [printf]
        add esp, 4*1
        
        push dword s1
        push dword format
        call [scanf]
        add esp, 4*2
        
        mov esi, s1
        mov edi, s2
        cld
        repeat1:
            lodsb
            cmp eax, 0
            je over
            push eax
            call change
            stosb
        jmp repeat1
        
        over:
        push dword s2
        push dword display
        call [printf]
        add esp, 4*2
        
        push    dword 0
        call    [exit]
