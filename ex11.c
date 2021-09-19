/* Evgenii Meshcheriakov. Excercise 11 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "txt11.txt"
#define LEN 10

void open_file(FILE **name, char *c);
int read_input(char *str, FILE *fp, float *num);
void swap(float *a, float *b);
void sort3(float *a, float *b, float *c);

int main(void)
{
    FILE *txt11 = NULL;
    char str[LEN];
    float numbers[LEN];
    int lc = 0;

    open_file(&txt11, "r");
    if(txt11 == NULL) return 1;
    else {
        while(lc < LEN && !feof(txt11)) {
            if(read_input(str, txt11, &numbers[lc]) == 1)
                lc++;
        }
        fclose(txt11);
    }
    sort3(&numbers[0],&numbers[1],&numbers[2]);
    open_file(&txt11, "w");
    if(txt11 == NULL) return 1;
    else {
        for(int i = 0; i<3; i++){
            fprintf(txt11, "%.0f\n", numbers[i]);
        }
        fclose(txt11);
    }
    return 0;
}

// Function is made in cooperation with Vasily Davydov
void open_file(FILE **name, char *mode)
{
    *name = fopen(FILENAME, mode);
    if(*name == NULL) {
        printf("Unable to open file, %s\n", FILENAME);
    }
}

int read_input(char *str, FILE *fp, float *num)
{
    if(fgets(str, LEN, fp) == NULL) return 0;
    if(str[strlen(str)-1] == '\n'){
        str[strlen(str)-1] = '\0';
    }
    return sscanf(str, "%f", num);
}

void sort3(float *a, float *b, float *c)
{
    if (*a > *c) swap (a, c);
    if (*a > *b) swap (a, b);
    if (*b > *c) swap (b, c);
}
void swap(float *a, float *b)
{
    float temp = *a;
    *a = *b;
    *b = temp;
}