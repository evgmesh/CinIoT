#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

void sort3(int *pa[3]);
/* write a function that implements the function declared above */



#define TEST_SIZE 12

int main(int arcg, char **argv)
{
const int v[TEST_SIZE] = { 1, 2, 3, 7, 4, 9, 12, 4, -1, 67, 67, 34 };
int a[TEST_SIZE];
int *ta[3];

for (int i = 0; i < TEST_SIZE; i++) a[i] = v[i];

for (int k = 0; k < TEST_SIZE; k += 3) {
for (int i = 0; i < 3; ++i) {
ta[i] = &a[i+k];
}
sort3(ta);

printf("%d, %d, %d\n", *ta[0], *ta[1], *ta[2]);
}

for (int i = 0; i < TEST_SIZE; ++i) {
if(a[i] != v[i]) printf("Data corrupted\n");
}

return 0;

}

void sort3(int *pa[3])
{
    int *temp = NULL;
    if (*pa[0] > *pa[2]) {
        temp = pa[0];
        pa[0] = pa[2];
        pa[2] = temp;
    }
    if (*pa[0] > *pa[1]) {
        temp = pa[0];
        pa[0] = pa[1];
        pa[1] = temp;
    }
    if (*pa[1] > *pa[2]) {
        temp = pa[1];
        pa[1] =pa[2];
        pa[2] = temp;
    }
}

/* better way to solve with two functions, which is no allowed by the task. PROTOTYPE:
void sort3(int *a, int *b, int *c)
{
    int temp = 0;
    if (*a > *c) swap (a, c);
    if (*a > *b) swap (a, b);
    if (*b > *c) swap (b, c);
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
*/