#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>
#include <stdbool.h>

int printd(const char *format, ...)
{
va_list argptr;
char str[356];      int cnt = 0;
const char *str2 = "DEBUG: ";
va_start (argptr, format);
strcat(str, str2);

fputs(str2, stdout);
cnt = vsprintf(str, format, argptr);
fputs(str, stdout);
va_end(argptr);

return(cnt+7);

}

int main(void)
{
    int i = printd("12345678\n");
    printf("%d\n", i);
}