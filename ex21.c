/* Evgenii Meshcheriakov. Excercise 21 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define PRTLEN 10
#define STR_SIZE 20
typedef struct char_ {
    unsigned char ch;
    int count;
} CHAR;

FILE * open_file(char *fname, char *mode);
long read_file(FILE *fp, unsigned char **c);
void read_str(const char *prompt, char *buffer);
int database_size(CHAR *c);
int cmp( const void *a, const void *b );

int main(void)
{
    FILE *f20 = NULL;
    unsigned char* file_data = NULL;
    long flen = 0, counter = 0;
    char buffer[STR_SIZE];
    CHAR* data_base = NULL;

    read_str("Enter file name, please: ", buffer);
    f20 = open_file(buffer, "rb");
    flen = read_file(f20, &file_data);
    data_base = (CHAR*) calloc(flen+1, sizeof(CHAR));

    int size = 0;
    for(int i = 0; i<flen; i++)
    {
        if(size == 0) {
            data_base[size].ch = file_data[i];
            data_base[size].count++;
            data_base[size+1].count = 0;
            size = database_size(data_base);
        }
        for (int j=0; j<size; j++)
        {
            if(data_base[j].ch == file_data[i+1]) {
                data_base[j].count++;
                break;
            }
            else if(data_base[j].ch != file_data[i+1]
                    && j+1==size && i != flen-1) {
                data_base[size].ch = file_data[i+1];
                data_base[size].count++;
                data_base[size+1].count = 0;
                size = database_size(data_base);
                break;
            }
        }
    }
    qsort(data_base, size, sizeof(CHAR), cmp);


    printf("Most popular characters are:\n");
    int printlen = (size < PRTLEN) ? size : PRTLEN;
    for (int i = 0; i<printlen; i++) {
        if (data_base[i].ch == '\n')
            printf("#%d is: 'NEW LINE', count: %d\n",
                    i+1, data_base[i].count);
        else if (!isprint(data_base[i].ch))
            printf("#%d is: NOT PRINTABLE, count: %d\n",
                    i+1, data_base[i].count);
        else
            printf("#%d is: '%c', count: %d\n",
                    i+1, data_base[i].ch, data_base[i].count);
    }
    free(data_base);
    free(file_data);
    fclose(f20);
    return 0;
}

int database_size(CHAR *c)
{
    int size = 0;
    while(c[size].count != 0) size++;
    return size;
}
int cmp( const void *a, const void *b )
{
    const CHAR *one  = a;
    const CHAR *two = b;

    return ( one->count < two->count ) - ( two->count < one->count );
}

FILE * open_file(char *fname, char *mode)
{
    FILE* fp = fopen(fname, mode);
    if(fp == NULL) {
        printf("Unable to open file, %s\n", fname);
        exit(-1);
    }
    return fp;
}
long read_file(FILE *fp, unsigned char **c)
{
    long flen = 0;
    fseek(fp, 0, SEEK_END);
    flen = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    *c = malloc(flen+1);
    fread(*c, sizeof(unsigned char), flen, fp);
    return flen;
}
void read_str(const char *prompt, char *buffer)
{
    printf("%s", prompt);
    fgets(buffer, STR_SIZE, stdin);
    if(buffer[strlen(buffer)-1] == '\n') {
        buffer[strlen(buffer)-1] = '\0';
    }
}