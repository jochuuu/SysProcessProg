#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
    int fd[2];
    if (pipe(fd) == -1) {
        perror("pipe");
        return 1;
    }
    
    int pid1 = fork();
    if (pid1 == -1) {
        perror("fork");
        return 2;
    }
    
    if (pid1 == 0) {
        // Child process 1 (ping)
        dup2(fd[1], STDOUT_FILENO);
        close(fd[0]);
        close(fd[1]);
        execlp("ping", "ping", "-c", "5", "google.com", NULL);
        perror("execlp ping");
        return 3; // Failed to execute ping
    }
    
    int pid2 = fork();
    if (pid2 == -1) {
        perror("fork");
        return 4;
    }
    
    if (pid2 == 0) {
        // Child process 2 (grep)
        dup2(fd[0], STDIN_FILENO);
        close(fd[0]);
        close(fd[1]);
        execlp("grep", "grep", "rtt", NULL);
        perror("execlp grep");
        return 5; // Failed to execute grep
    }
    
    close(fd[0]);
    close(fd[1]);
    
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
    
    return 0;
}

