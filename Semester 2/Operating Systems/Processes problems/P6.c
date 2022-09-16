#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <time.h>

int main(int argc, char **argv) {
        srandom(time(0));
        int one_to_two[2], two_to_one[2];
        pipe(one_to_two);
        pipe(two_to_one);
        // printf("ecio");
        if (fork() == 0) {
                // 1
                close(one_to_two[0]);
                close(two_to_one[1]);
                int rand = random() % 10 + 1;
                if (write(one_to_two[1], &rand, sizeof(int)) < 0)
                        exit(1);
                while (1) {
                        if (read(two_to_one[0], &rand, sizeof(int)) < 0)
                                exit(1);
                        printf("1.Read %d\n", rand);
                        if (rand == 10) {
                                printf("sexy time ;)\n");
                                exit(1);
                        } else {
                                rand = random() % 10 + 1;
                                printf("1. Generated: %d\n", rand);
                                if (write(one_to_two[1], &rand, sizeof(int)) < 0)
                                        exit(1);
                        }
                        wait(0);
                }
                close(one_to_two[1]);
                close(two_to_one[0]);
                exit(0);
        }
        if (fork() == 0) {
                // 2
                close(one_to_two[1]);
                close(two_to_one[0]);
                int rand;
		while (1) {
                        if (read(one_to_two[0], &rand, sizeof(int)) < 0) {
                                exit(1);
                        }
                        printf("2.Read %d\n", rand);
                        if (rand == 10) {
                                printf("Pepsi\n");
                                exit(1);
                        } else {
                                rand = random() % 10 + 1;
                                printf("2. Generated: %d\n", rand);
                                if (write(two_to_one[1], &rand, sizeof(int)) < 0)
                                        exit(1);
                        }
                        wait(0);
                }
                close(one_to_two[0]);
                close(two_to_one[1]);
                exit(0);
        }
        wait(0);
        //wait(0);
        return 0;
}