#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

char *my_gets(char *line, int size, FILE *stream);
int count_chars(const char *characters, FILE *stream);

int main(void)
{
    char line[] = {"AabCdweglwkgjJLGKWG"};
    char characters[] = {"waLz"};
    int count = 0;

    for (int i = 0; i<strlen(line); i++)
    {
        for(int j = 0; j<strlen(characters); j++)
        {
            if(characters[j] == line[i]) {
                printf("%d ", line[i]);
                count++;
            }
        }
    }
    printf("%d\n", count);
    return 0;
}

/* returned solution

char characters[];
int count_chars(const char *characters, FILE *stream)
{
    int count = 0; 
    
    char line[10];
    while(my_gets(line, 9, stream)) {
        for (int i = 0; line[i] != '\0'; i++)
        {
            for(int j = 0; characters[j] != '\0'; j++)
            {
                if(characters[j] == line[i]) count++;
            }
        }
    }
    return count;
}
*/
