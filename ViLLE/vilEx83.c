#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>

#define DOT '.'
#define DASH '-'

typedef struct MorseCode_ {
        char symbol;
        char code[7];
} MorseCode;

const MorseCode ITU_morse[] = {
{ 'A',{ DOT, DASH } }, // A
{ 'B',{ DASH, DOT, DOT, DOT } }, // B
{ 'C',{ DASH, DOT, DASH, DOT } }, // C
{ 'D',{ DASH, DOT, DOT } }, // D
{ 'E',{ DOT } }, // E
{ 'F',{ DOT, DOT, DASH, DOT } }, // F
{ 'G',{ DASH, DASH, DOT } }, // G
{ 'H',{ DOT, DOT, DOT, DOT } }, // H
{ 'I',{ DOT, DOT } }, // I
{ 'J',{ DOT, DASH, DASH, DASH } }, // J
{ 'K',{ DASH, DOT, DASH } }, // K
{ 'L',{ DOT, DASH, DOT, DOT } }, // L
{ 'M',{ DASH, DASH } }, // M
{ 'N',{ DASH, DOT } }, // N
{ 'O',{ DASH, DASH, DASH } }, // O
{ 'P',{ DOT, DASH, DASH, DOT } }, // P
{ 'Q',{ DASH, DASH, DOT, DASH } }, // Q
{ 'R',{ DOT, DASH, DOT } }, // R
{ 'S',{ DOT, DOT, DOT } }, // S
{ 'T',{ DASH } }, // T
{ 'U',{ DOT, DOT, DASH } }, // U
{ 'V',{ DOT, DOT, DOT, DASH } }, // V
{ 'W',{ DOT, DASH, DASH } }, // W
{ 'X',{ DASH, DOT, DOT, DASH } }, // X
{ 'Y',{ DASH, DOT, DASH, DASH } }, // Y
{ 'Z',{ DASH, DASH, DOT, DOT } }, // Z
{ '1',{ DOT, DASH, DASH, DASH, DASH } }, // 1
{ '2',{ DOT, DOT, DASH, DASH, DASH } }, // 2
{ '3',{ DOT, DOT, DOT, DASH, DASH } }, // 3
{ '4',{ DOT, DOT, DOT, DOT, DASH } }, // 4
{ '5',{ DOT, DOT, DOT, DOT, DOT } }, // 5
{ '6',{ DASH, DOT, DOT, DOT, DOT } }, // 6
{ '7',{ DASH, DASH, DOT, DOT, DOT } }, // 7
{ '8',{ DASH, DASH, DASH, DOT, DOT } }, // 8
{ '9',{ DASH, DASH, DASH, DASH, DOT } }, // 9
{ '0',{ DASH, DASH, DASH, DASH, DASH } }, // 0
{ 0,{ 0 } } // terminating entry - Do not remove!
};

void print_morse(const char *str)
{
    for(int i = 0; str[i] != '\0'; i++) {
        for(int j = 0; strlen(ITU_morse[j].code) != 0; j++) {
            if(toupper(str[i]) == ITU_morse[j].symbol && str[i] != ' ') {
                printf("%s    ", ITU_morse[j].code);
            }
            if(str[i] == 32 || str[i] == 10 || str[i] == 9) {
                printf("\n\n");
                break;
            }
            if (toupper(str[i]) == '#' || str[i] == 33 ) {
                printf("%s    ", ITU_morse[23].code);
                break;
            }
        }
    }
}

int main(void)
{

}