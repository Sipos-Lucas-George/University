#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char** argv){
        srandom(getpid());
        int fread = open("fifo1", O_RDONLY);
        int fwrite = open("fifo2", O_WRONLY);
        while(1){
                int n;
                if (read(fread, &n, sizeof(int)) < 0)
                        exit(1);
                if (n == 10){
                        break;
                }
                n = random() % 10 + 1;
                if(write(fwrite, &n, sizeof(int)) < 0)
                        exit(1);
                printf("B: Number -> %d\n", n);
        }
        close(fread); close(fwrite);
        return 0;
}