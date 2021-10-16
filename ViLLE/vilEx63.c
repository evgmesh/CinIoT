#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>


#define MAX_LEN 32

typedef struct student_ {
    char name[MAX_LEN];
    int group;
    int id;
} student;

typedef enum { byGroup, byLastName, byFirstName } sort_order;

void sort_students(student *students, int count, sort_order sb);


int cmp_gr( const void *a, const void *b )
{
    const student *one  = a;
    const student *two = b;

    return ( two->group - one->group );
//    return ( one->group > two->group ) - ( two->group > one->group );
}
int cmp_fnam( const void *a, const void *b )
{
    const student *one  = a;
    const student *two = b;
    const char s[2] = " ";
    char *token; char *token2;
    token = strtok(one->name, s);
    token2 = strtok(two->name, s);
    return strcmp(token, token2);
}
int cmp_lnam( const void *a, const void *b )
{
    const char s[2] = " ";
    char *token; char *token2;
    const student *one  = a;
    const student *two = b;
    token = strtok(one->name, s);
    token = strtok(NULL, s);
    token2 = strtok(two->name, s);
    token2 = strtok(NULL, s);

    return strcmp(token, token2);
}

void sort_students(student *students, int count, sort_order sb)
{
    int size = 0;
    for(; students[size].id == 0; size++);
    if(count<=0) count = size;

    if(sb == byGroup)
        qsort(students, count, sizeof(student), cmp_gr);
    else if(sb == byLastName)
        qsort(students, count, sizeof(student), cmp_fnam);
    else if(sb == 2)
        qsort(students, count, sizeof(student), cmp_lnam);
}

int main(void)
{
student students[] = {
    {"Ian McShane"    , 1,  2019001},
{"John Woo"       , 3,  2019007},
{"Nick Name"      , 3,  2019019},
{"Molly Westwood" , 2,  2019021},
{"Peter Thornton" , 2,  2019031},
{"Sammy Davis"    , 3,  2019671}
};

}


/*
{"Ian McShane"    , 1,  2019001},
{"John Woo"       , 3,  2019007},
{"Nick Name"      , 3,  2019019},
{"Molly Westwood" , 2,  2019021},
{"Peter Thornton" , 2,  2019031},
{"Sammy Davis"    , 3,  2019671}
"Will Smith"     , 1,  2019761
"Patti Smith"    , 4,  2018492
"Willy Wonka"    , 2,  2016290
"Jack Daniels"   , 4,  2016892
"Ernie West"     , 1,  2015192
"Sean Bean"      , 2,  2016112
"Eric Idle"      , 2,  2017822
"Susan Sarandon" , 5,  2016034
"Nick Cave"      , 5,  2015002
*/