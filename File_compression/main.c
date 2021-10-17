#include "main.h"
#define BFRSIZE 100
//test
int main(void)
{
    FILE *fstream = NULL;
    long flen = 0;
    char buffer[BFRSIZE];
    uint8_t *data = NULL;
    read_str("Enter file name, please: ", buffer, BFRSIZE);
    fstream = open_file(buffer, "rb");
    flen = file_size(fstream);
    data = (uint8_t) malloc(flen);
    printf("%u\n", crc16(data, flen));
    free(data);
    fclose(fstream);
}
long file_size(FILE *fp)
{
    long flen = 0;
    fseek(fp, 0, SEEK_END);
    flen = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    return flen;
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
void read_str(const char *prompt, char *buffer, int size)
{
    printf("%s", prompt);
    fgets(buffer, size, stdin);
    if(buffer[strlen(buffer)-1] == '\n') {
        buffer[strlen(buffer)-1] = '\0';
    }
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
int read_file(FILE *fp, uint8_t *data, long flen)
{
    int count = 0;
    count = fread(data, sizeof(uint8_t), flen, fp);
    return count;
}