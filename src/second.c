#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>

int main()
{
    setlocale(LC_CTYPE, "");
    wprintf(L"Hello, world!\n");
    wchar_t cat = 0x1F63B;
    wprintf(L"%lc\n", cat);
    return EXIT_SUCCESS;
}
