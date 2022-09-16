#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char** argv){
        srandom(getpid());
        if (mkfifo("./fifo1", 0600) < 0)
                exit(1);
        if (mkfifo("./fifo2", 0600) < 0)
                exit(1);
        int fwrite = open("fifo1", O_WRONLY);
        int fread = open("fifo2", O_RDONLY);
        while(1){
                int n = random() % 10 + 1;
                if (write(fwrite, &n, sizeof(int)) < 0)
                        exit(1);
                printf("A: Write -> %d\n", n);
                if (read(fread, &n, sizeof(int)) < 0)
                        exit(1);
                if (n == 10){
                        break;
                }
        }
        close(fwrite); close(fread);
        if(unlink("./fifo1") < 0)
                perror("./fifo1 was a fking bitch!\n");
        if(unlink("./fifo2") < 0)
                perror("same as ./fifo1 but ./fifo2\n");
        return 0;
}