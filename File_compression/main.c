#include "main.h"
int fput16le(uint16_t rep, FILE *fp)
{

    int e1, e2;

    e1 = fputc(rep & 0xFF, fp);
    e2 = fputc((rep >> 8) & 0xFF, fp);

    if(e1 == EOF || e2 == EOF)
        return EOF;
    return 0;
}
int main(int argc, char **argv)
{
    FILE *fin = NULL, *fout = NULL;
    *argv = basename(*argv);
    uint16_t originCRC = 0;
    if(argc != 3) {
        fprintf(stderr, "%s: invalid number of arguments: %d detected. "
                    "Should be 2.\n%s\n", argv[0], argc-1, USE_MSG);
        return (-1);
    } else if(PACK) {

        fin = open_file(argv[2], "rb");
        originCRC = crc16(fin);
        char *fname = strtok(argv[2], ".");
        fout = open_file(strcat(fname, ".rle"), "wb");
        fprintf(fout,"%X\n", originCRC);
        rle_pack(fin, fout);
        printf("Successfully packed\n");
        fclose(fin);
        fclose(fout);

    } else if(UNPACK) {

        fin = open_file(argv[2], "rb");
        char *fname = strtok(argv[2], ".");
        fout = open_file(strcat(fname, ".new"), "wb");
        // skp first line;
        fscanf(fin, "%*[^\n]\n");
        rle_unpack(fin, fout);
        printf("Successfully unpacked\n");
        fclose(fin);
        fclose(fout);
    } else if(CRC) {

        fin = open_file(argv[2], "rb");
        originCRC = crc16(fin);
        printf("crc of file [%s] is %X\n", argv[2], originCRC);
        fclose(fin);
    }
    else {
        fprintf(stderr, "%s: invalid comand: %s detected. "
                "Should be 2.\n%s\n", argv[0], argv[1], USE_MSG);
        return (-1);
    }
    return 0;
}

int rle_pack(FILE *fin, FILE *fout)
{
    int c, pc = ASCIIEND;
    unsigned char n = 0;
    while(1) {
        c = getc(fin);
        if (c == pc && n < ASCIIEND-1)
            n++;
        else {
            if (n > 3) {
                putc(DELIM, fout);
                putc(pc, fout);
                putc(n, fout);
            } else {
                for(; n>0; n--)
                    putc(pc, fout);
              }

            if (c == DELIM) {
                for(int i = 0; i<2; i++)
                    putc(c, fout);
                n = 0;
                pc = ASCIIEND;
                continue;
            } else if (c == EOF)
                break;
            else {
                n = 1;
                pc = c;
            }
        }
    }
    return 0;
}
int rle_unpack(FILE *fin, FILE *fout)
{
    int c, rc = ASCIIEND;
    bool repeat = false;

    while ((c = getc(fin)) != EOF) {
        if (repeat) {
            if (rc == ASCIIEND) {
                if (c  == DELIM) {
                    putc(DELIM, fout);
                    repeat = false;
                } else
                    rc = c;
            } else {
                for (int i = 0; i < c; i++)
                    putc(rc, fout);
                repeat = false;
                rc = ASCIIEND;
            }
        } else if (c != DELIM)
            putc(c, fout);
        else
            repeat = true;
    }
    return 0;
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
uint16_t crc16(FILE *fp)
{
    long length = file_size(fp);
    uint8_t *data_p = (uint8_t*) malloc(length+1);
    read_file(fp, data_p, length);
    fseek(fp, 0, SEEK_SET);
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
