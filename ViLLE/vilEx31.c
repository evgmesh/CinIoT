#include <stdio.h>
#include <string.h>
#include <ctype.h>

int count(char *str)
{
    int uppers = 0;
    for(int i = 0; i < strlen(str); i++)
    {
        if(isupper(str[i]))
        {
            uppers++;
        }
    }
    return uppers;
}


int main(void)
{
char test1[] = "A Quick  BROwn fox jumps over THE laZY DOGG";
char test2[] = "no upper case letter in this sentence";
char test3[] = "WHY ARE YOU SHOUTING IN THE INTERNET";

printf("%d\n", count(test1));
printf("%d\n", count(test2));
printf("%d\n", count(test3));
return 0;
}