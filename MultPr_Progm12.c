#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
    int pid = fork();
    if (pid == -1) {
        return 1;
    }
    
    if (pid == 0) {
        execlp("ping", "ping", "-c", "3", "google.com", NULL);
        printf("THIS SHOULD NOT PRINT ON THE TERMINAL\n");
    } else {
        wait(NULL);
        printf("Success\n");
        printf("Some post processing goes here\n");
    }

    return 0;
}
