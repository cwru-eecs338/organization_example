#include<stdio.h>
#include<unistd.h>

// Function prototypes:
void c1();
void c2();
void badchild(int);

void child(int number) {
    // Here we switch between behaviors
    // given the child number
    switch(number) {
        case 0:
            c1();
        case 1:
            c2();
        default:
            badchild(number);
    }
}

// In practice, you can write c1
// and c2 below as one generalized
// function. This is just for
// illustration

void c1() {
    printf("Hi, I'm Child #1!\n");
    fflush(stdout);
    _exit(0);
}

void c2() {
    // Use sleep to print in order
    // (This is a hack that is not guaranteed to work,
    //  we'll see better ways of doing this later)
    sleep(1);
    printf("Hi, I'm Child #2!\n");
    fflush(stdout);
    _exit(0);
}

void badchild(int n) {
    sleep(n); // Use sleep to print in order
    printf("I'm not going to say my name!\n");
    fflush(stdout);
    _exit(1);
}
