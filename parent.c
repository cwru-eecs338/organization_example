// (System libraries use angle brackets)
#include<stdio.h>
#include<unistd.h>
#include<wait.h>
#include<stdlib.h>
// Include the header file to use
// the corresponding .c file
// (Local libraries use quotes)
#include "child.h"

int CHILDREN = 4;

int main() {
    int i;
    for(i = 0; i < CHILDREN; i++) {
        int pid = fork();
        if(pid < 0) {
            // An error occurred during fork
            perror("fork");
            exit(1);
        } else if(pid == 0) {
            // We are now in a child process
            child(i);
        }
        // We are still in the parent process
    }

    int status;
    int failures = 0;
    for(i = 0; i < CHILDREN; i++) {
        // Note we give wait the
        // address of status with '&'
        wait(&status);

        // If status is non-zero,
        // something went wrong
        if(status) { failures++; }
    }
    printf("I have %d bad children.\n", failures);

    return EXIT_SUCCESS;
}
