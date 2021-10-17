#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>

FILE * open_file(char *fname, char *mode);
void read_str(const char *prompt, char *buffer, int size);

uint16_t crc16(const uint8_t* data_p, unsigned int length);
long file_size(FILE *fp);
int read_file(FILE *fp, uint8_t *data, long flen);