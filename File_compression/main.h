#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <libgen.h>

#define BFRSIZE 500
#define ASCIIEND 0x100
#define DELIM 0x80
#define USE_MSG "Usage of the program:\n" \
        "rle pack filename (compresses the specified file)\n" \
        "rle unpack filename (decompresses the specified file)"
#define PACK !strcmp(argv[1], "pack")
#define UNPACK !strcmp(argv[1], "unpack")

FILE * open_file(char *fname, char *mode);
void read_str(const char *prompt, char *buffer, int size);

uint16_t crc16(FILE *fp);
long file_size(FILE *fp);
int read_file(FILE *fp, uint8_t *data, long flen);
int rle_pack(FILE *fin, FILE *fout) ;
int rle_unpack(FILE *fin, FILE *fout);