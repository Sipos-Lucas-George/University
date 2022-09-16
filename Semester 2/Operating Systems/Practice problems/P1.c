#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(int argc, char** argv) {
        int pid = fork();
        if(pid == 0) {
                execlp("grep", "grep", "-E", "\\<imalilpie\\>", "/etc/passwd", NULL);
                exit(1);
        }
        // do some other work in the parent
        wait(0);
        return 0;
}