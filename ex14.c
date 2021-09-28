/* Evgenii Meshcheriakov. Excercise 14 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define PATH_LEN 20
#define DATASIZE 64

typedef struct chunk {
    uint8_t data[DATASIZE];
    uint16_t size;
    uint16_t crc;
} CHUNK;

CHUNK *read_file(FILE *fp, CHUNK *ch);
int read_input(char *str);
void open_file(FILE **name, char *fname, char *mode);
uint16_t crc16(const uint8_t* data_p, unsigned int length);
void printer(CHUNK *ch, int *counter);

int main(void)
{
    char fname[PATH_LEN];
    FILE *f14 = NULL;
    CHUNK *chanks = NULL;
    int count;

    read_input(fname);
    open_file(&f14, fname, "rb");
    if(f14 == NULL) return 1;
    else {
        chanks = read_file(f14, chanks);
        fclose(f14);
    }
    for(count = 0; chanks[count].size > 0; count++);

    for(int i = 0; i<=count; i++){
        chanks[i].crc = crc16(chanks[i].data, DATASIZE);
    }
    for(int i = 0; i<count; i++) {
        printer(&chanks[i], &i);
    }
    free(chanks);
    return 0;

}
CHUNK *read_file(FILE *fp, CHUNK *ch)
{
    int count=0, size = 1;
    if(ch == NULL) {
        ch = (CHUNK *) malloc(sizeof(CHUNK));
        ch->size = 0;
    }
    else {
        for(count = 0; ch[count].size > 0; count++);
    }
    while(ch != NULL && size > 0) {
        size = fread(&(ch[count].data), 1, DATASIZE, fp);
        if(size>0) {
            ch[count].size = size;
            count++;
            ch = realloc(ch, sizeof(CHUNK) * (count+1));
        }
    }
    return ch;
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
void printer(CHUNK *ch, int *counter) {
    printf("Chunk #%d, size is %d, crc is %x\n", *counter+1, ch->size, ch->crc);
}
uint16_t crc16(const uint8_t* data_p, unsigned int length) {
    uint8_t x;
    uint16_t crc = 0xFFFF;

    while (length--) {
        x = crc >> 8 ^ *data_p++;
        x ^= x>>4;
        crc = (crc << 8) ^ ((uint16_t)(x << 12)) ^ ((uint16_t)(x <<5)) ^ ((uint16_t)x);
    }
    return crc;
}
