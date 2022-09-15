bits 32 

global start        

extern exit, fopen,fclose, fread, printf, fscanf
import exit msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll
import fread msvcrt.dll
import printf msvcrt.dll
import fscanf msvcrt.dll

segment data use32 class=data

    format db "%d ", 0
    format2 db "%s", 0
    file_name db "input.txt",0
    acces_mode db "r", 0
    file_descriptor db -1
    text db -1
    sir dd 0

segment code use32 class=code
    start:
        
        push dword acces_mode
        push dword file_name
        call [fopen]
        add esp, 4*2
        
        mov [file_descriptor], eax
        cmp eax, 0
        je final
        
        push dword sir
        push dword format2
        push dword [file_descriptor]
        call [fscanf]
        add esp, 4*3
        
        mov esi, sir
        cld
        mov ebx, 0
        mov edx, 0
        loop1:
            lodsb
            cmp al, '?'
            je done
            cmp al, '0'
            jb after
            cmp al, '9'
            jbe number
            after:
            cmp al, 'a'
            jb after2
            cmp al, 'z'
            jbe letter
            after2:
        jmp loop1
        
        number:
            inc ebx
            jmp loop1
        letter:
            inc edx
            jmp loop1
            
        done:
            push edx
            push dword format
            call [printf]
            add esp, 4*3
            
            push ebx
            push dword format
            call [printf]
            add esp, 4*3
            
        push dword [file_descriptor]
        call [fclose]
        add esp, 4
        
        final:
        push    dword 0
        call    [exit]
