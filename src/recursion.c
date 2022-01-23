#include <stdlib.h>
#include <stdio.h>

void recursion(int);

int main() {
    recursion(3);
    return EXIT_SUCCESS;
}

void recursion(int i) {
    printf("i: %d \n",i);
    if (i==0){
        return;
    };
    i--;
    recursion(i);
}