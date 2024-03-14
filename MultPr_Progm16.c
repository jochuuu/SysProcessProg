#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

int main(int argc, char* argv[]) {
    int pid = fork();
    if (pid == -1) {
        return 1;
    }
    
    if (pid == 0) {
        while (1) {
            printf("Some text goes here\n");
            usleep(50000);
        }
    } else {
        sleep(1);
        kill(pid, SIGKILL);
        wait(NULL);
    }

    return 0;
}
