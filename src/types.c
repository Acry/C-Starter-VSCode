#include <stdio.h>
#include <stdlib.h>

void foo(void);

int main()
{
    foo();

    char key = 'a';
    printf("The key is: %c\n", key);

    // numbers
    short a = 999; // short integer
    printf("short a is: %d\n", a);

    int b = 999; // integer
    printf("integer b is: %d\n", b);

    long c = 999; // long integer
    printf("long c is: %ld\n", c);

    float f = 0.1f;
    printf("float f is: %f\n", f);

    double g = 0.1f;
    printf("double g is: %f\n", g);

    return EXIT_SUCCESS;
}

// nothing is returned
void foo(void)
{ // nothing is handed over
    printf("Void function\n");
}
