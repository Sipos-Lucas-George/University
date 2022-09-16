#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
int main(int argc, char** argv){
        if (argc != 2){
                perror("Bye!");
                exit(1);
        }
        int c2p[2], p2c[2];
        pipe(c2p); pipe(p2c);
        int furculita = fork();
        if(furculita == 0){
                int i, nr, avg = 0, rand;
                close(c2p[0]); close(p2c[1]);
                if (read(p2c[0], &nr, sizeof(int)) < 0){
                        perror("Bye!");
                        exit(1);
                }
                for (i = 0; i < nr; ++i){
                        if (read(p2c[0], &rand, sizeof(int)) < 0)
                                exit(1);
                        avg += rand;
                }
                avg /= nr;
                if (write(c2p[1], &avg, sizeof(int)) < 0)
                        exit(1);
                close(c2p[1]); close(p2c[0]);
                exit(0);
        }
        close(c2p[1]); close(p2c[0]);
        srandom(time(0));
        int n = atoi(argv[1]);
        int i;
        if (write(p2c[1], &n, sizeof(int)) < 0){
                perror("Bye!");
                exit(1);
        }
        for (i = 0; i < n; ++i){
                int rand = random() % 100;
                printf("%d ", rand);
                if (write(p2c[1], &rand, sizeof(int)) < 0)
                        exit(1);
        }
        wait(0);
        if (read(c2p[0], &i, sizeof(int)) < 0)
                exit(1);
        printf("\nAvg = %d\n", i);
        return 0;
}