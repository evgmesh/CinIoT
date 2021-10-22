#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <libgen.h>

#define BFRSIZE 256
#define ASCIIEND 0x100
#define DELIM 0x80
#define USE_MSG "Usage of the program:\n" \
        "rle pack filename (compresses the specified file)\n" \
        "rle unpack filename (decompresses the specified file)"

#define PACK !strcmp(argv[1], "pack")
#define UNPACK !strcmp(argv[1], "unpack")
#define CRC !strcmp(argv[1], "crc")

#define MAKELOG set_keijos_printf(&logfile,"log.txt");\
        keijos_printf(&logfile, "%-19s%-14s%14s%8ld %-12s%X\n%-19s%-14s%14s%8ld %-12s\n\n",\
                        "Original file:",argv[2], "size:", file_size(fin), "bytes   CRC:", originCRC,\
                        "Compressed file: ", outfname, "size:", file_size(fout), "bytes");

FILE * open_file(char *fname, char *mode);
void read_str(const char *prompt, char *buffer, int size);

uint16_t crc16(FILE *fp);
long file_size(FILE *fp);
int read_file(FILE *fp, uint8_t *data, long flen);
int rle_pack(FILE *fin, FILE *fout) ;
int rle_unpack(FILE *fin, FILE *fout);
void set_keijos_printf(FILE **fp, const char* filename);
int keijos_printf(FILE **fp, const char* fmt, ...);
void newfname(char* in, char* out, char * end);