/* Evgenii Meshcheriakov. Excercise 18 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <ctype.h>
#include <limits.h>
#include <stdbool.h>

#define PRINT_ALL 5
#define ADD_NEW 6
#define ADD_FILE 7
#define PROG_END 8
#define STR_SIZE 20
#define FNAME "f17"
#define GARAGE_SIZE 20

typedef struct cars {
    char    make[STR_SIZE];
    char    model[STR_SIZE];
    int     price;
    float   emissions;
} CARS;

FILE * open_file(char *fname, char *mode);
int read_file(FILE *fp, CARS *c);
int write_file(FILE *fp, CARS *c);

void read_str(const char *prompt, char *buffer);
int read_int(const char *prompt, char* buffer, int min, int max);
float read_float(const char *prompt, char* buffer, float min, float max);
int add_file(char*str1,char*str2, CARS *c, int size);

void displayCars(CARS *c);
void printer(CARS *c, int i);
int add_car(CARS *c);
void menu();
void binary_write(FILE *fp, CARS *c);
void update_garage(FILE *fp, CARS *c);
int garage_size(CARS *c);

int main(void)
{
    FILE *f18 = NULL;
    char buffer[STR_SIZE];
    int choice = 0;
    CARS garage[GARAGE_SIZE] = {0};
    while(choice != PROG_END) {
        menu();
        choice = read_int("", buffer, 5, 8);
        if (choice == PRINT_ALL) {
            update_garage(f18, garage);
            displayCars(garage);
        }
        if (choice == ADD_NEW) {
            update_garage(f18, garage);

            if(add_car(garage) == -1) {
                printf("Garage is full\n");
                return 1;
            }
            else {
                binary_write(f18, garage);
                displayCars(garage);
              }
        }
        if (choice == ADD_FILE) {
            long flen = 0; char* json = 0; char *posi;
            char str[STR_SIZE], str2[STR_SIZE];
            int offset = 2, members = 0;

            update_garage(f18, garage);
            read_str("Enter file name, please: ", buffer);
            f18 = open_file(buffer, "rb");
            fseek(f18, 0, SEEK_END);
            flen = ftell(f18);
            fseek(f18, 0, SEEK_SET);
            json = malloc(flen);
            fread(json, 1, flen, f18);
            posi = strstr(json, ":");
            int size = garage_size(garage);
            while(posi && members<4) {
                while (isalpha(*(posi-offset))) offset++;

                sscanf(posi-offset+1, "%[^\":]", str);

                if((posi+1)[0] == 34) sscanf(posi+2, "%[^\"]", str2);
                else sscanf(posi+1, "%[^,\n]", str2);

                if(add_file(str, str2, garage, size) == 1) {
                    members++;
                    if(members < 4) {
                        posi = strstr((posi+offset), ":");
                        offset = 2;
                    }
                }
                else {
                    garage[size].price = 0;
                    break;
                }
            }
            free(json);
            fclose(f18);

            binary_write(f18, garage);
            displayCars(garage);
        }
        if (choice == PROG_END) {
            printf("Good bye!\n");
        }
    }

    return 0;
}

int add_file(char*str1, char*str2, CARS *c, int size) {
    int result = 0;

    if(size < GARAGE_SIZE-1) {
        if(strncmp(str1, "make", 4) == 0) {
            strcpy(c[size].make, str2);
            result++;
        }
        else if(strncmp(str1, "model", 5) == 0) {
            strcpy(c[size].model, str2);
            result++;
        }
        else if(strncmp(str1, "price", 5) == 0) {
            c[size].price = atoi(str2);
            result++;
        }
        else if(strncmp(str1, "emissions", 9) == 0) {
            c[size].emissions = atof(str2);
            result++;
        }
        else {
            printf("Data is incomplete. Please check your JSON file\n");
            result = -1;
        }
    }
    else {
        printf("Garage is full\n");
        result = -1;
    }
    return result;
}
int read_file(FILE *fp, CARS *c)
{
    int count = 0;
    count = fread(c, sizeof(CARS), GARAGE_SIZE, fp);
    return count;
}
int write_file(FILE *fp, CARS *c)
{
    int count = 0, i;
    for(i=0; i<GARAGE_SIZE; i++) {
        if(fwrite(&c[i], sizeof(CARS), 1, fp) != 1) {
            count = i;
            break;
        } else count++;
    }
    return count;
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
int add_car(CARS *c)
{
    char buffer[STR_SIZE];
    int size = 0, result = 0;

    for(size = 0; c[size].price > 0; size++);
    if(size == 0) {
        c[size].price = 0;
    }
    if(size < GARAGE_SIZE-2) {
        c[size+1] = c[size];
        read_str("Enter make of the car: ", c[size].make);
        read_str("Enter model of the car: ", c[size].model);
        c[size].price = read_int("Enter price of the car: ", buffer, 1, INT_MAX);
        c[size].emissions = read_float("Enter emission of the car: ", buffer, 0, FLT_MAX);
        result++;
    }
    else {
        result = -1;
    }
    return result;
}
void read_str(const char *prompt, char *buffer)
{
    printf("%s", prompt);
    fgets(buffer, STR_SIZE, stdin);
    if(buffer[strlen(buffer)-1] == '\n') {
        buffer[strlen(buffer)-1] = '\0';
    }
}
int read_int(const char *prompt, char* buffer, int min, int max)
{
    read_str(prompt, buffer);
    int  result = 0;
    int i = sscanf(buffer, "%d", &result);
    while(i !=1 || result < min || result > max) {
        printf("Please provide an integer in range %d-%d: ", min, max);
        read_str("", buffer);
        i = sscanf(buffer, "%d", &result);
    }
    return result;
}
float read_float(const char *prompt, char* buffer, float min, float max)
{
    read_str(prompt, buffer);
    float  result = 0;
    int i = sscanf(buffer, "%f", &result);
    while(i !=1 || result < min || result > max) {
        printf("Please provide a positive float: ");
        read_str("", buffer);
        i = sscanf(buffer, "%f", &result);
    }
    return result;
}
void displayCars(CARS *c)
{
    int i = 0;
    printf("%-5s | %-10s | %-8s | %-6s | %12s\n",
            "Car","Make","Model", "Price", "Emissions");
    while(c[i].price != 0) {
        printer(&c[i],i);
        i++;
    }
}
int garage_size(CARS *c)
{
    int i = 0;
    while(c[i].price != 0) i++;
    return i;
}
void printer(CARS *c, int i)
{
    printf("No %2d | %-10s | %-8s | %6d | %7.2f\n",
            i, c->make, c->model, c->price, c->emissions);
}
void menu() {
    printf("Please choose an action:\n"
            "5. print all cars in the file\n"
            "6. manual entry of new car to the end of the file\n"
            "7. new car from a text file\n"
            "8. quit the program.\nI choose: ");
}
void binary_write(FILE *fp, CARS *c)
{
    fp = open_file(FNAME, "wb");
    write_file(fp,c);
    fclose(fp);
}
void update_garage(FILE *fp, CARS *c)
{
    fp = open_file(FNAME, "rb");
    read_file(fp,c);
    fclose(fp);
}
