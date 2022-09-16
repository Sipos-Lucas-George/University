#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char** argv) {
        int r = open("./fifo1", O_RDONLY);
        int w = open("./fifo2", O_WRONLY);

        int i, size, charsize;
        read(r, &size, sizeof(int));
        for (i=0; i<size; ++i) {
                read(r, &charsize, sizeof(int));
                char *sir = malloc(charsize);
                read(r, sir, charsize);
                int j;
                //printf("%s\n", sir);
                for (j=0; j < charsize/sizeof(char); ++j) {
                        if(sir[j] >= 'a' && sir[j] <= 'z') {
                                sir[j] += 'A' - 'a';
                        }
                }
                //printf("%s\n", sir);
                write(w, sir, charsize);
                free(sir);
        }

        close(w);
        close(r);

        return 0;
}