#include<stdio.h>
#include<unistd.h>

// Function prototypes:
void c1();
void c2();
void badchild();

void child(int number) {
    switch(number) {
        case 0:
            c1();
        case 1:
            c2();
        default:
            badchild();
    }
}

// In practice, you can write c1
// and c2 below as one generalized
// function. This is just for
// illustration
void c1() {
    printf("Hi, I'm Child #1!\n");
    _exit(0);
}

void c2() {
    sleep(1);
    printf("Hi, I'm Child #2!\n");
    _exit(0);
}

void badchild() {
    sleep(2);
    printf("I'm not going to say my name!\n");
    _exit(1);
}
