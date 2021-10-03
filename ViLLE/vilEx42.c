#include<stdio.h>
#include<string.h>
#include<ctype.h>

void merge_whitespace(char *);

int main(void)
{

char str1[50] = "[This is a test.   Whole  lot a  spaces going on.]";
char str2[100] = "[This  is another test. 	Now we \n \n have all kinds of    white space   ]";
char str3[100] = "[   This  time with   		leading spaces. 	One \n more for the road ]";
char str4[100] = "[ Start with one space         and end with   couple more    ]";

printf("str1: %s\n", str1);
printf("str2: %s\n", str2);
printf("str3: %s\n", str3);
printf("str4: %s\n", str4);
merge_whitespace(str1);
merge_whitespace(str2);
merge_whitespace(str3);
merge_whitespace(str4);
printf("AFTER:\n");
printf("str1: %s\n", str1);
printf("str2: %s\n", str2);
printf("str3: %s\n", str3);
printf("str4: %s\n", str4);

return 0;

}

void merge_whitespace(char * str)
{
    char *c = str;
    while(*str != '\0') {
        while (*str == '\t' || *str == '\r' || *str == '\n' || *str =='\f'
                || *str =='\v' || (*str == ' ' && *(str+1) == ' ')
                || (*str == ' ' && *(str+1) == '\n')) {
          str++;
        }
      *c++ = *str++;
    }
    *c = '\0';
}
