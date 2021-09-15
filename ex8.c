/* Evgenii Meshcheriakov. Excercise 8 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define INPUT_LEN 200

void read_input(char *str);
void upper(char * input);

int main(void)
{
    char str[INPUT_LEN];
    int end, end2;
    do {
        printf("Enter string: ");
        read_input(str);
        end = strncmp("stop", str, 4);
        end2 = strncmp("STOP", str, 4);

        if(end != 0 && end2 != 0) {
            printf("Original str is: [%s]\n", str);
            upper(str);
            printf("Converted str is: [%s]\n", str);
        }
    } while (end != 0 && end2 != 0);

    printf("Good bye\n");

    return 0;
}
void upper(char * input)
{
    for(int i = 0; i < strlen(input); i++) {
        if(i == 0 || isspace(input[i-1])) {
            input[i] = toupper(input[i]);
        }
    }
}
void read_input(char *str)
{
    fgets(str, INPUT_LEN, stdin);
        if(str[strlen(str)-1] == '\n'){
            str[strlen(str)-1] = '\0';
        }
}