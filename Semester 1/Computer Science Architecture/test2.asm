bits 32 

global start        

extern exit, scanf, fopen, fclose, fprintf
import exit msvcrt.dll
import scanf msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll
import fprintf msvcrt.dll

segment data use32 class=data

    text dd 0
    doi dd 2
    file_name db "output.txt", 0
    access_mode db "a", 0
    file_descriptor db -1
    format db "%d", 0
    format2 db "%d - ", 0
    format3 db "%d", 0ah, 0
    numbers times 100 dd 0
    

segment code use32 class=code
    start:
        
        mov ecx, 0
        loop1:
            push ecx
            
            push dword text 
            push dword format
            call [scanf]
            add esp, 4*2
            
            pop ecx
            cmp dword[text], 0
            je over
            mov eax, dword[text]
            mov dword[numbers+4*ecx], eax
            inc ecx
            jmp loop1
        
        over:
        push ecx
        
        push dword access_mode
        push dword file_name
        call [fopen]
        add esp, 4*2
        
        mov [file_descriptor], eax
        cmp eax, 0
        je done
        
        mov esi, 0
        pop ecx
        loop2:
            mov eax, [numbers+4*esi]
            
            push ecx
            push esi
            
            push dword eax
            push dword format2
            push dword [file_descriptor]
            call [fprintf]
            add esp, 4*3
            
            pop esi
            mov eax, [numbers+4*esi]
            push esi
            mov ebx, 0
            cdq
            loop3:
                mov edx, 0
                div dword[doi]
                cmp edx, 1
                jne after
                inc ebx
                after:
                cmp eax, 0
                je its
                jmp loop3
            its:
            
            push dword ebx
            push dword format3
            push dword [file_descriptor]
            call [fprintf]
            add esp, 4*3
            
            pop esi
            pop ecx
            inc esi
        loop loop2
        
        push dword [file_descriptor]
        call [fclose]
        add esp, 4
        
        done:
        
        push    dword 0
        call    [exit]
