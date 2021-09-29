/* Evgenii Meshcheriakov. Excercise 15 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define INPUT_LEN 20

typedef struct chunk {
    uint8_t *data;
    uint16_t size;
    uint16_t capacity;
    uint16_t crc;
} CHUNK;

CHUNK *read_file(FILE *fp, CHUNK *ch, int user_cap);
void read_input(char *str, int *choice, bool number);
void open_file(FILE **name, char *fname, char *mode);
uint16_t crc16(const uint8_t* data_p, unsigned int length);
void printer(CHUNK *ch, int *counter);

int main(void)
{
    char fname[INPUT_LEN];
    char buffer[INPUT_LEN];
    FILE *f15 = NULL;
    int count, user_capacity;
    do {
        CHUNK *chanks = NULL;
        printf("Enter file name, please: ");
        read_input(fname, &user_capacity, false);
        printf("Please enter chunk size by typing positive integer > 0: ");
        read_input(buffer, &user_capacity, true);
        open_file(&f15, fname, "rb");
        if(f15 == NULL) return 1;
        else {
            chanks = read_file(f15, chanks, user_capacity);
        }
        for(count = 0; chanks[count].size > 0; count++);

        for(int i = 0; i<=count; i++){
            chanks[i].crc = crc16(chanks[i].data, chanks[i].capacity);
            free(chanks[i].data);
        }
        for(int i = 0; i<count; i++) {
            printer(&chanks[i], &i);
        }
        fclose(f15);
        free(chanks);

        printf("Do you want to read another file? (\"no\" - for quit)\n");
        read_input(buffer, &user_capacity, false);
    } while(strncmp(buffer, "no", 2) !=0);
    printf("Good bye!\n");
    return 0;

}

CHUNK *read_file(FILE *fp, CHUNK *ch, int user_cap)
{
    int count=0, size = 1;
    if(ch == NULL) {
        ch = malloc(sizeof(CHUNK));
        if(ch == NULL) printf("Error during allocating memory\n");

        ch->data = calloc(user_cap, sizeof(uint8_t));
        if(ch->data == NULL) printf("Error during allocating memory\n");
        ch->size = 0;
    }
    else {
        for(count = 0; ch[count].size > 0; count++);
    }
    while(ch != NULL && size > 0) {
        size = fread(ch[count].data, 1, user_cap, fp);
        if(size>0) {
            ch[count].capacity = user_cap;
            ch[count].size = size;
            count++;

            ch = realloc(ch, sizeof(CHUNK) * (count+1));
            if(ch == NULL) printf("Error during allocating memory\n");
            ch[count].data = calloc(user_cap, sizeof(uint8_t));
            if(ch[count].data == NULL) printf("Error during allocating memory\n");
            ch[count].size = 0;
        }
    }
    return ch;
}

void open_file(FILE **name, char *fname, char *mode)
{
    *name = fopen(fname, mode);
    if(*name == NULL) {
        printf("Unable to open file, %s\n", fname);
    }
}
void printer(CHUNK *ch, int *counter) {
    printf("Chunk #%d: capacity is %d, size is %d, crc is %x\n",
            *counter+1, ch->capacity, ch->size, ch->crc);
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

void read_input(char *str, int *choice, bool number)
{
    int i;
    fgets(str, INPUT_LEN, stdin);
        if(str[strlen(str)-1] == '\n')
        {
            str[strlen(str)-1] = '\0';
        }
    if(number) {
        i = sscanf(str, "%d", choice);
        while(i !=1 || *choice <=0) {
            printf("Wrong input, try again: ");
            fgets(str, INPUT_LEN, stdin);
            if (str[strlen(str)-1] == '\n') str[strlen(str)-1] = '\0';
            i = sscanf(str, "%d", choice);
        }
    }
}
