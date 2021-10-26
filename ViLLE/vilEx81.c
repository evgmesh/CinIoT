#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>


uint32_t get_bits(uint32_t value, uint32_t shift, uint32_t bits)
{
    uint32_t mask = 0x0;
    for(int i = 0; i<bits; i++)
       mask = (mask << 1) + 1;
    return (value >> shift) & mask;

// can be solved even as: return ( value >> shift ) & (0xFFFFFFFF >> (32 - bits));
/*
uint32_t mask = 0x0;
int cnt = 1;
    for(int i = 0; i<bits; i++) {
        mask += cnt;
        cnt *= 2;
    }
value = (value >> shift) & mask;

return value;
*/
}

int main(void)
{


}