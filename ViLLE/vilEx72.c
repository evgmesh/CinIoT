#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>
#include <stdbool.h>

typedef enum { logCritical, logWarning, logInfo, logVerbose } loglevel;
// Log levels as strings:  "Critical", "Warning", "Info", "Verbose"
// impelement this function
const char *log_level_to_str(loglevel level);
// implement this function
int log1(loglevel level, const char *format, ...);


// this (existing) function sets the global log_level variable
void set_log_level(loglevel level);

int main(void) {

}

int log(loglevel level, const char *format, ...)
{
    va_list argptr;
    char str[256];
    char str2[20];
    strcpy(str2, log_level_to_str(level));

    va_start (argptr, format);
    strcat(str, str2);
    if(level <= log_level)
    {
        vsprintf(str, format, argptr);
        printf("LOG[%s]: ", str2);
        fputs(str, stdout);
    }
    va_end(argptr);
}

const char *log_level_to_str(loglevel level)
{
    char *str = malloc(100);
    if(level==logCritical) str = "Critical\0";
    else if(level==logWarning) str = "Warning\0";
    else if(level==logInfo) str = "Info\0";
    else if(level==logVerbose) str = "Verbose\0";

    return str;
}