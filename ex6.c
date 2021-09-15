/* Evgenii Meshcheriakov. Excercise 6 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define INPUT_LEN 200
#define DECRYPT 26

void read_input(char *str);
void shifter(char * input, int shift);

int main(void)
{
    char str[INPUT_LEN];
    int shift = 0;
    do
    {
        printf("Enter shift (only numbers are accepted): ");
        read_input(str);
        sscanf(str, "%d", &shift);
    } while(shift == 0);

    printf("Enter string: ");
    read_input(str);

    printf("Original str is: [%s]\n", str);
    shifter(str, shift);
    printf("Crypted str is: [%s]\n", str);
    shifter(str, DECRYPT-shift);
    printf("Decrypted str is: [%s]\n", str);

    return 0;
}
void shifter(char * input, int shift)
{
    for(int i = 0; i < strlen(input); i++) {
        input[i] = toupper(input[i]);
        if(isspace(input[i])) {
            input[i] = input[i];
        }
        else {
            input[i] += shift;
            if((int)input[i] > 90){
                input[i] -= 26;
            }
        }
    }
}

void read_input(char *str)
{
    fgets(str, INPUT_LEN, stdin);
        if(str[strlen(str)-1] == '\n')
        {
            str[strlen(str)-1] = '\0';
        }
}