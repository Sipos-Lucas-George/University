#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char** argv){
        struct timeval t1, t2;
        if (argc < 2){
                printf("ERORR!");
                exit(1);
        }
        gettimeofday(&t1, NULL);
        int furculita = fork();
        if (furculita == -1)
                perror("Error creating the furculita!");
        else if (furculita == 0){
                if (-1 == execvp(argv[1], argv+1)){
                        perror("Buci!");
                        exit(1);
                }
        }
        else {
                wait(0);
                gettimeofday(&t2, NULL);
                printf("%f", (double)(t2.tv_usec - t1.tv_usec) / 1000000 + (double)(t2.tv_sec - t1.tv_sec));
        }
        return 0;
}