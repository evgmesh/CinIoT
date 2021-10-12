#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define LSIZE 10
/* call this function to read input */
bool read_line(char *line, size_t size);

int main(void) {

int num1, num2;
char line[LSIZE] = "3 d kjl";
char str[LSIZE];

//while(read_line(line, LSIZE)){
    int read = sscanf(line, "%d %d %s", &num1, &num2, str);
    printf("%d\n", read);
#if 0
    if(read == 3)
    {
            if(strcmp(str, "add") == 0) {
                printf("%d + %d = %d\n", num1,num2,num1+num2);
            }
            else if(strcmp(str, "sub") == 0) {
                printf("%d - %d = %d\n", num1,num2,num1-num2);
            }
            else if(strcmp(str, "mul") == 0) {
                printf("%d * %d = %d\n", num1,num2,num1*num2);
            }
            else if(strcmp(str, "div") == 0) {
                printf("%d / %d = %d\n", num1,num2,num1/num2);
            } else printf("Input: \"%s\" Invalid argument in position: %d\n", line, 3);
        }
    else if (read == 2) {
        printf("Input: \"%s\" Invalid argument in position: %d\n", 2);
    }
    else if (read == 1) {
        printf("Input: \"%s\" Invalid argument in position: %d\n", 1);
    }
#endif
//}
}