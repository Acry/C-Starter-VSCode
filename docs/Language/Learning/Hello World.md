
Entry point

```c
int main(int argc, char **argv)
{
    return 0; // return a literal integer
}
```

Here we are explicitly returning 0. Which stands for success on most operating systems.

The correct way to return success is the macro `EXIT_SUCCESS` defined in `stdlib.h`:

```c
#include <stdlib.h>

int main()
{
    return EXIT_SUCCESS;
}
```

`echo $?`

```asm at&t
; x86-64 gcc 11.2 - godbolt.org
main:
        push    rbp
        mov     rbp, rsp
        mov     eax, 0
        pop     rbp
        ret
```

function

out $name(param1, param2)
{
    do stuff;
    return if not void;
}

Two kinds of C main functions:

int and void

## char **argv vs. char *argv[]

char **argv, char *argv[]

char *argv[]
array of pointers to char

char **argv
pointer to pointer to char

They are entirely equivalent.

```c
int main(int argc, char **argv)
{
    return 0; // return a literal integer
}
```

and

```c
int main(int argc, char *argv[])
{
    return 0; // return a literal integer
}
```

are translating both to the same code:

```asm at&t
; x86-64 gcc 11.2 - godbolt.org
main:
        push    rbp
        mov     rbp, rsp
        mov     DWORD PTR [rbp-4], edi
        mov     QWORD PTR [rbp-16], rsi
        mov     eax, 0
        pop     rbp
        ret
```

Squinting assembly (asm) language :

`push`
Decrements the stack pointer and then stores the source operand on the top of the stack.

http://www.felixcloutier.com/x86/PUSH.html

`mov`
Copies the source operand to the destination operand.

The source operand can be an:

- immediate value,
- general-purpose register,
- segment register, or
-  memory location;

Both operands must be the same size.

http://www.felixcloutier.com/x86/MOV.html

`ret`
Transfers program control to a return address located on the top of the stack.

http://www.felixcloutier.com/x86/RET.html

int main() - if you don't work with args, you can omit the parameters

## Leads to arrays vs address of arrays

a[]

*a

char text[] = "A string of characters.";

char thirdChar = text[3];
char thirdChar2 = *(text+3);

## Intel-Syntax die AT&T-Assembler-Syntax

as -msyntax=intel
as -msyntax=att (default)

## To ABI

https://www.agner.org/optimize/calling_conventions.pdf

## Debug Symbols

## inline assembly gcc -masm=intel

## Preprocessor, Compiler, Linker, Assembler

AST - Abstract Syntax Tree

## Executable Formats and shared objects

## Binutils

## Codestyle

## optimization

https://www.agner.org/optimize/

