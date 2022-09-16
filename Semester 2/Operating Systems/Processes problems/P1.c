#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char** argv){
        if (argc != 2){
                printf("ERORR!");
                exit(1);
        }
        int num = atoi(argv[1]);
        int i = num;
        while(num != 0){
                if(fork() == 0){
                        printf("PID: %d PPID: %d\n", getpid(), getppid());
                        exit(0);
                }
                else{
                        printf("PID: %d\n", getpid());
                }
                --num;
        }
        while(i != 0){
                wait(0);
                --i;
        }
        return 0;
}