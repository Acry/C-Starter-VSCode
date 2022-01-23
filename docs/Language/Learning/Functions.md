# functions

A program is a sequence of instructions that can be executed.

A procedure.

main
    part1
    part2
    part3

conditional execution of functions
main
    parta
    if part a is successful
        partb
    else
        partc

If we defined a function part4 we would get a compiler warning of unused function.


nested functions

main
    part1
        part2
            part3

A function is a sub-procedure
a function is a block of code that can be called from another block of code.

statement, expression

// function head
// return type name(param1, param2)
out $name(param1 type param1 name, param2 type param2 name)

// function body
{
    do stuff;
    return if not void;
}

void myFunction() // implicit void
{
    // statements
}


An expression evaluates to a value.
 "do something" (more formally: have a side effect)

A statement does something.

The entry point is a function named main, by convention.

Inside this sub-procedure
Can control the control flow of the program.

code block

```c
// function declaration / function prototype
int calculate(int, int);

int main(int argc, char **argv)
{
    // function call
    int result = calculate(5, 3);

}

// function definition
int calculate(int a, int b)
{
    return a + b;
}
```