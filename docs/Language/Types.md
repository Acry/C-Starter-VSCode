wchar_t

A wchar_t is similar to a char in the sense that it is a number, but when displaying a char or wchar_t we don't want to see the number, but the drawn character corresponding to the number. The mapping from the number to the characters aren't defined by neither char nor wchar_t, they depend on the system. So there is no difference in the end usage between char and wchar_t except for their sizes.

Given the above, the most trivial implementation of printf("%ls") is one where you know what are the system encodings for use with char and wchar_t. For example, in my system, char has 8 bits, has encoding UTF-8, while wchar_t is 32 bits and has encoding UTF-32. So the printf implementation just converts from UTF-32 to UTF-8 and outputs the result.

A more general implementation must support different and configurable encodings and may need to inspect what's the current encoding. In this case functions like wcsnrtombs() or iconv() must be used.