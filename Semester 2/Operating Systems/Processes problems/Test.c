#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char** argv){
        int p2a[2], a2b[2], a2p[2];
        pipe(p2a); pipe(a2b); pipe(a2p);
        while(1){
                char* str = malloc(sizeof(char) * 50);
                int v[11], i;
                scanf("%s", str);
                if (strcmp(str, "x")==0){
                        free(str);
                        break;
                }
                int f1 = fork();
                if (f1==0){
                        //A
                        close(p2a[1]); close(a2b[0]); close(a2p[0]);
                        char* str = malloc(sizeof(char) * 50);

                        int v[11]={0};
                        if(read(p2a[0], str, sizeof(char) * 50) < 0)
                                exit(1);
                        for(i = 0; i < strlen(str); ++i){
                                if(isdigit(str[i]))
                                        ++v[(int)(str[i]) - '0'];
                                else
                                        ++v[10];
                        }
                        if(write(a2p[1], v, sizeof(int) * 11) < 0)
                                exit(1);
                        if(write(a2b[1], v, sizeof(int) * 11) < 0)
                                exit(1);

                        free(str);
                        close(p2a[0]); close(a2b[1]); close(a2p[1]);
                        exit(0);
                }
                int f2 = fork();
		if(f2 == 0){
                        //B
                        close(p2a[1]); close(p2a[0]); close(a2p[0]); close(a2p[1]); close(a2b[1]);
                        int v[11], i;

                        if(read(a2b[0], v, sizeof(int) * 11) < 0)
                                exit(1);
                        int sum = 0;
                        for(i = 0; i < 11; ++i)
                                sum += v[i];
                        printf("SUM = %d\n", sum);

                        close(a2b[0]);
                        exit(0);
                }
                close(a2b[0]); close(a2b[1]); close(p2a[0]); close(a2p[1]);
                if(write(p2a[1], str, sizeof(char) * 50) < 0)
                        exit(1);
                if(read(a2p[0], v, sizeof(int) * 11) < 0)
                        exit(1);
                for(i = 0; i < 11; ++i)
                        printf("Iteration %d -> %d\n", i, v[i]);
                close(p2a[1]); close(a2p[0]);
                free(str);
                wait(0); wait(0);
        }
        return 0;
}