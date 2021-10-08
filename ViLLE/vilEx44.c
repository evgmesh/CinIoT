#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

#define MAX_LEN 32

typedef struct student_ {
    char name[MAX_LEN];
    int group;
    int id;
} student;

void displayStr(student *s, int size);
int move(student *source, int group, student *target, int size);

int main(void)
{
    int sizeA = 0, sizeB = 0;
    student a = { "Bubba", 2, 5 };
    student b = { "Betty", 4, 6 };
    student ar1[] = {
    { "st1", 1, 1 },  {"st2", 2, 2 },  {"st3", 3, 3 }, { "st4", 1, 1}, {"st5", 1, 0}
    };
    student ar2[] = {
    { "stud1", 3, 1 },  {"stud2", 2, 2 },  {"stud2", 2, 2 },  {"stud3", 3, 3 }, { "stud4", 1, 1}, {"stud5", 1, 0}
    };
    for(; ar1[sizeA].id != 0; sizeA++);
    for(; ar2[sizeB].id != 0; sizeB++);
    printf("Ar1:\n");
    displayStr(ar1, sizeA);
    printf("Ar2:\n");
    displayStr(ar2, sizeB);

    move(ar1, 1, ar2, 8);

    printf("AFTER:\n");

    printf("Ar1:\n");
    displayStr(ar1, sizeA);
    printf("Ar2:\n");
    displayStr(ar2, sizeB);


}

int move(student *source, int group, student *target, int size)
{
    int sizeT= 0, moved = 0;
    for(; target[sizeT].id != 0; sizeT++);

    for(int i = 0; source[i].id != 0; i++) {
        if(sizeT < size - 1) {
            if(source[i].group == group) {
                target[sizeT+1] = target[sizeT];
                target[sizeT] = source[i];
                for(int j = i; source[j].id !=0; j++) {
                    source[j] = source[j+1];
                }
                moved++;
                sizeT++;
                i--;
            }
        }
    }
    return moved;
}

void displayStr(student *s, int size) {
    for (int i = 0; i<=size; i++) {
        printf("%s with id = %d, is in group %d\n", s[i].name, s[i].id, s[i].group);
    }
}