#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    char* arr[] = {"ping", "google.com", NULL};

    char* env[] = {
        "TEST=environment variables",
        NULL
    };

    // Without env and PATH variable
    execv("/bin/ping", arr);
    execl("/bin/ping", "ping", "google.com", NULL);

    // Without env but with PATH variable
    execvp("ping", arr);
    execlp("ping", "ping", "google.com", NULL);

    // With env and PATH variable
    execve("/bin/ping", arr, env);
    execl("/bin/ping", "ping", "google.com", NULL);

    return 0;
}

