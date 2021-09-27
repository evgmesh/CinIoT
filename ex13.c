/* Evgenii Meshcheriakov. Excercise 13 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MALL_SIZE 5
#define STRSIZE str_size-1

int main(void)
{
    char *line;
    FILE *file;
    int str_size = 0;
    int mall_size = 5;

    file = fopen("f13", "a");
    if(file == NULL) printf("Can not open a file\n");

    line = (char *) calloc(MALL_SIZE, sizeof(char));
    if(line == NULL) printf("Fail of malloc\n");

    printf("Enter a string, please(end with [.]): \n");
    do{
        fgets(line, MALL_SIZE , stdin);
        str_size = strlen(line);
        if (line[0] == '.' && str_size == 2) printf("Ending...\n");

        else{
            while(line[STRSIZE] != '\n') {
                line = (char*)realloc(line, (mall_size+1)*sizeof(char));
                mall_size++;
                fgets(line+str_size, mall_size, stdin);
                str_size = strlen(line);
            }
            if(line[STRSIZE] == '\n' || line[STRSIZE] == '\r') {
                line[STRSIZE] = '\0';
            }
            fprintf(file, "%d:%s\n", STRSIZE, line);
        }
    } while(line[0] != '.' || STRSIZE != 1) ;

    free(line);
    fclose(file);
    return 0;
}
