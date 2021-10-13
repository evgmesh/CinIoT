#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

#define MAX_LEN 32
typedef struct student_ {
    char name[MAX_LEN];
    int group;
    int id;
    struct student_ *next;
} student;

int move(student **source, int group, student **target);

int main(void)
{

}
int move(student **source, int group, student **target)
{
    int count = 0;
    while(*source != NULL) {
        if((*source)->group == group) {
            student *pn = *source;
            *source = pn->next;
            pn->next = *target;
            *target = pn;
            count++;
        } else
          {
            source = &(*source)->next;
          }
    }
    return count;
}

#if 0
void add(struct student **ppn, struct student *item)
{
    item->next = *ppn;
    *ppn = item;
}


int remove(struct student **ppn, const char *text)
{
int count = 0;
struct student *pn;
    while (*ppn != NULL) {
        pn = *ppn;
        if (strcmp(pn->line, text)==0) {
        *ppn = pn->next;
        free(pn);
        count++;
        }
        else {
            ppn = &pn->next;
            }
    }
    return count;
}

#endif