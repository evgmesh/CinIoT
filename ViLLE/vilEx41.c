#include<stdio.h>


//void swap(int *a, int *b);
void sort3(int *a, int *b, int *c);

int main(void)
{
    int n1 = 30;
    int n2 = 6;
    int n3 = 1;

    sort3(&n1, &n2, &n3);

    printf("%d, %d, %d", n1, n2, n3);

    return 0;
}

void sort3(int *a, int *b, int *c)
{
    int temp = 0;
    if (*a > *c) {
        temp = *a;
        *a = *c;
        *c = temp;
    }
    if (*a > *b) {
        temp = *a;
        *a = *b;
        *b = temp;
    }
    if (*b > *c) {
        temp = *b;
        *b = *c;
        *c = temp;
    }
}


/* better way to implement
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