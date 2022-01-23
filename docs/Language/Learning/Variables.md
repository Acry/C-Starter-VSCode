
declare, announce to the compiler
define, give it a value

datatype

variable

type name declare
int x;

name and assignment operator = definition

x=5;

## Dynamic (implicit) typing vs. static (explicit) typing

```c
int a = 3;
int b = 2;
int c = a + b;
```
Type-Checking during translation time (compile time)

```python 3
a = 3
b = 2
c = a + b
print(c)
```
Type-Checking during execution (run time)

a = 3
b = 'hello'
c = a + b
print(c)

result in runtime error
Traceback (most recent call last):
  File "main.py", line 3, in <module>
    c = a + b
TypeError: unsupported operand type(s) for +: 'int' and 'str'