#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char** argv) {
        if (mkfifo("./fifo1", 0600) < 0) {
                perror("No");
                exit(1);
        }
        if (mkfifo("./fifo2", 0600) < 0) {
                perror("No");
                exit(1);
        }
        int w = open("./fifo1", O_WRONLY);
        int r = open("./fifo2", O_RDONLY);

        int i, len = 0;
        for (i = 1; i < argc; ++i) {
                len += strlen(argv[i]) + 1;
        }
        ++len;

        write(w, &argc, sizeof(int));
        char *all = malloc(len * sizeof(char));
        for (i = 1; i < argc; ++i) {
                int size = sizeof(char) * strlen(argv[i]);
                write(w, &size, sizeof(int));
                write(w, argv[i], size);
                char *this = malloc(strlen(argv[i]) * sizeof(char));
                read(r, this, strlen(argv[i]) * sizeof(char));
                strcat(all, this);
                free(this);
        }

        printf("%s\n", all);

        free(all);
        close(w);
        close(r);
        if (0 > unlink("./fifo1")) {
                perror("Error unlink w");
        }
        if (0 > unlink("./fifo2")) {
                perror("Error unlink r");
        }

        return 0;
}