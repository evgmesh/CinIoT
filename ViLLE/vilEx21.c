#include <stdio.h>
#include <string.h>

void sequence(int num1, int num2);

int main(void)
{
    int n1 = 1;
    int n2 = 10;
    sequence(n1,n2);
}
void sequence(int num1, int num2)
{
    while(num1<=num2)
    {
        printf("%d\n", num1);
        num1++;
    }
        printf("\n");
}