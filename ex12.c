/* Evgenii Meshcheriakov. Excercise 12 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ITEMS 21
#define BUF_SIZE 100
#define PATH_LEN 20

typedef struct item{
    float   price;
    char    name [100];
} item;


int read_input(char *str);
int read_file(item *store, FILE *fp, char *buffer);
void open_file(FILE **name, char *fname, char *mode);

int main(void)
{
    char fname[PATH_LEN];
    int lc = 0;
    FILE *txt12 = NULL;
    char buffer[BUF_SIZE];
    item store[ITEMS]= {};


    read_input(fname);
    open_file(&txt12, fname, "r");
    if(txt12 == NULL) return 1;
    else {
        while(lc < ITEMS && !feof(txt12)) {
            if(read_file(&store[lc], txt12, buffer) == 2)
                lc++;
        }
        fclose(txt12);
    }
    printf("\nTotal number of items is: %d\n%-40s %6s", lc, "Name", "Price\n");
    for(int i=0; i<lc; i++) {
        if(strcmp(store[i].name, "") )
            printf("%-40s %6.2f\n",store[i].name, store[i].price);
    }
    return 0;
}
int read_file(item *store, FILE *fp, char *buffer)
{
    if(fgets(buffer, BUF_SIZE, fp) == NULL) return 0;
    if(buffer[strlen(buffer)-1] == '\n'){
            buffer[strlen(buffer)-1] = '\0';
    }

    return sscanf(buffer, "%f%*[;]%[0-9a-zA-Z ]", &store->price,  store->name);
}
int read_input(char *str)
{
    printf("Enter file name, please: ");
    if(fgets(str, PATH_LEN, stdin) == NULL) return 1;
    if(str[strlen(str)-1] == '\n') {
        str[strlen(str)-1] = '\0';
    }
    return 0;
}
void open_file(FILE **name, char *fname, char *mode)
{
    *name = fopen(fname, mode);
    if(*name == NULL) {
        printf("Unable to open file, %s\n", fname);
    }
}