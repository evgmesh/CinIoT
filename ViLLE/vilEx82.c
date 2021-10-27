#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>


void print_binaryw(uint32_t value, uint32_t width)
{
    uint32_t mask;
    int bits = 31;
    for(mask = 1 << bits; mask > 0; mask /= 2)
    {
        if( value & mask) {
            printf("1");
            bits = 0;
        }
        if(!( value & mask) && (int) width > bits)
            printf("0");
        bits--;
    }
    printf("\n");
}

int main(void)
{
    print_binaryw(17,8);
}
