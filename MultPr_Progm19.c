#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void handle_sigcont(int sig) {
    printf("Input number: ");
    fflush(stdout);
}

int main(int argc, char* argv[]) {
    struct sigaction sa;
    sa.sa_handler = &handle_sigcont;
    sa.sa_flags = SA_RESTART;
    sigaction(SIGCONT, &sa, NULL);
    
    int x;
    printf("Input number: ");
    scanf("%d", &x);
    printf("Result %d * 5 = %d\n", x, x * 5);
    
    return 0;
}
