bits 32 

global start        

extern exit, fopen, fclose, fprintf
import exit msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll
import fprintf msvcrt.dll

segment data use32 class=data
    
    text db "as123dbZ987B[;456.,-=", 0
    numbers db "0123456789", 0
    file_name db "text.txt", 0
    access_mode db "w", 0
    file_var dd 0    

segment code use32 class=code
    start:
        ; A file name and a text (defined in data segment) are given. The text contains lowercase letters, uppercase letters, digits and special characters. 
        ; Replace all digits from the text with character 'C'. Create a file with the given name and write the generated text to file.
        push dword access_mode     
        push dword file_name
        call [fopen]
        add esp, 4*2            ; open text file for writing
        
        mov [file_var], eax     ; save file descriptor in variable
        cmp eax, 0              ; if an error occurs, eax will be zero
        je final                ; jump to the end if eax = 0
        
        mov esi, text
        mov edi, numbers
        mov ecx, 22             ; number of loops to be done
        mov ebx, 0              
        cld
        repeat1:
            lodsb
            push ecx
            push esi
            
            mov ecx, 10
            repne scasb 
            jne over
            
            pop esi
            pop ecx
            mov [text+ebx], byte 'C'
            mov edi, numbers
            jmp endloop
            
            over:
                pop esi
                pop ecx
                mov edi, numbers
                
            endloop:
                inc ebx
        loop repeat1
        
        push dword text
        push dword [file_var]
        call [fprintf]
        add esp, 4*2    
        
        push dword [file_var]
        call [fclose]
        add esp, 4
        
        final:
        
        push    dword 0
        call    [exit]
