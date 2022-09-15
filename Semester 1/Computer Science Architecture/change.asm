%ifndef _CHANGE_ASM_ 
%define _CHANGE_ASM_ 

change:
    jmp realC
    alphabet db "abcdefghijklmnopqrstuvwxyz", 0
    weirdAl db  "QWERTYUIOPASDFGHJKLZXCVBNM", 0
    
    realC:
   	mov eax, [esp + 4]
	mov ecx, 26
    mov ebx, 0
    repeta2:
        cmp al, [alphabet+ebx]
        je done
        inc ebx
    loop repeta2

    done:
    mov al, [weirdAl+ebx]
	ret 4

%endif