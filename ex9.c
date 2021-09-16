/* Evgenii Meshcheriakov. Excercise 9 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define GARAGE_SIZE 15
#define INPUT_LEN 200

typedef struct cars {
    char    make[20];
    char    model[20];
    char    cat[20];
    char    regN[20];
    int     mileage;
    bool    avail;
} cars;

void read_input(char *str, int *choice, bool number);
void displayCars(cars *c, char *str);
void reservation(cars *c, char *str);
void printer(cars *c, int i);

int main(void)
{
    char str[INPUT_LEN];
    int choice;
    cars garage[GARAGE_SIZE] =
    {
        {"BMW", "320d", "Premium", "ERE-415", 110000, false},
        {"Toyota", "avensis", "Standart", "FOC-274", 112340, true},
        {"Hynday", "Gets", "Compact", "ABC-321", 74281, false},
        {"Toyota", "auris", "Standart", "GGG-444", 2340, true},
        {"Aston", "aston", "Premium", "AAA-415", 110000, true},
        {"Volvo", "C60", "Standart", "DFS-274", 112340, false},
        {"WV", "Polo", "Compact", "ABC-321", 17428, false}
    };

    printf("Please choose an action:\n");
    printf("1. print all cars\n2. print free cars of given category\n");
    printf("3. change state of a car\n4. quit the program.\nI choose: ");
    read_input(str, &choice, true);

    switch (choice) {
        case 1:
            strcpy(str, "*");
            displayCars(garage, str);
            break;
        case 2:
            printf("Type category (Premium, Standart or Compact) please: ");
            read_input(str, &choice, false);
            displayCars(garage, str);
            break;
        case 3:
            printf("Type registration plate number please: ");
            read_input(str, &choice, false);
            reservation(garage, str);
            break;
        case 4:
            printf("Good bye!\n");
            break;
        default:
            printf("Never going to happen\n");
            break;
    }
    return 0;
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
        while(i !=1 || *choice < 1 || *choice > 4) {
            printf("Please choose an action by typing integer in range 1-4: ");
            fgets(str, INPUT_LEN, stdin);
            if (str[strlen(str)-1] == '\n') str[strlen(str)-1] = '\0';
            i = sscanf(str, "%d", choice);
        }
    }
}
void printer(cars *c, int i)
{
    printf("No %d: %-6s %-7s %-9s %-7s %7d %-10s",
            i, c->make, c->model, c->cat, c->regN, c->mileage,
            c->avail ? "Availiable for rent\n" : "Currently rented\n");
}
void displayCars(cars *c, char *str)
{
    printf("Car   Make   Model   Category  Plate No Mileage  Availability\n");
    for(int i = 0; i< GARAGE_SIZE; i++) {
        if(c[i].avail && strcmp(c[i].cat, str) == 0) {
            printer(&c[i],i);
        }
        else if(strcmp("*", str) == 0 && c[i].regN[0] != '\0') {
            printer(&c[i],i);
        }
    }
}
void reservation(cars *c, char *str)
{
    bool found = false;
    for(int i = 0; i< GARAGE_SIZE; i++) {
        if(strcmp(c[i].regN, str) == 0) {
            found = true;
            c[i].avail = (c[i].avail == true) ? false : true;
            printf("Car with registration number %s now is %s\n",
            c[i].regN, c[i].avail ? "availiable" : "NOT availiable");
        }
        else if (!found && i == GARAGE_SIZE-1) {
            printf("Car %s is not found.\n", str);
        }
    }
}