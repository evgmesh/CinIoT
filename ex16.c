/* Evgenii Meshcheriakov. Excercise 16 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define INPUT_LEN 20
void read_input(char *str, int *num1, int *num2, bool number);
int open_file(FILE **name, char *fname, char *mode);

int main(void)
{
    FILE *fp = NULL;
    char *data = NULL;
    int fsize = 0, offset =0, bremove = 0;
    char fname[INPUT_LEN], buffer[INPUT_LEN];
    printf("Enter file name, please: ");
    read_input(fname, &offset, &bremove, false);
    open_file(&fp, fname, "rb");

    printf("Enter offset and number of bytes to remove,"
            " please \nprototype(int int): ");
    read_input(buffer, &offset, &bremove, true);

    fseek(fp, 0L, SEEK_END);
    fsize = ftell(fp);

    if(offset+bremove>fsize) {
        printf("Sorry, you are trying to go outside of file data\n");
        printf("Try again. Bye...\n");
        return 0;
    }
    data = (char*) calloc(fsize+1, sizeof(char));
    if(data == NULL){
        printf("Fail of malloc\n");
        return 0;
    }
    fseek(fp, 0, SEEK_SET);
    for(int i=0; i<fsize; i++) {
        fread(&data[i], 1, 1, fp);
    }
    fclose(fp);

    open_file(&fp, fname, "wb");
    for(int i=0; i<offset-1; i++) {
        fwrite(&data[i], 1, 1, fp);
    }
    for(int i=offset+bremove-1; i<fsize; i++) {
        fwrite(&data[i], 1, 1, fp);
    }
    fclose(fp);
    free(data);
    return 0;
}

void read_input(char *str, int *num1, int *num2, bool number)
{
    int i;
    fgets(str, INPUT_LEN, stdin);
        if(str[strlen(str)-1] == '\n')
        {
            str[strlen(str)-1] = '\0';
        }
    if(number) {
        i = sscanf(str, "%d %d", num1, num2);
        while(i !=2 || *num1 <=0 || *num2 <=0) {
            printf("Wrong input, try again: ");
            fgets(str, INPUT_LEN, stdin);
            if (str[strlen(str)-1] == '\n') str[strlen(str)-1] = '\0';
            i = sscanf(str, "%d %d", num1, num2);
        }
    }
}

int open_file(FILE **name, char *fname, char *mode)
{
    *name = fopen(fname, mode);
    if(*name == NULL) {
        printf("Unable to open file, %s\n", fname);
        exit(-1);
    }
    return 0;
}
