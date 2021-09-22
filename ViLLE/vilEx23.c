#include<stdio.h>
#include <stdio.h>
#include <string.h>

void sequence(int num1, int num2);
int main(void)
{
    int num1 = 5;
    int num2 = 10;
    sequence(num1,num2);
}

void sequence(int num1, int num2)
{
if(num1<num2)
{
  while(num1<=num2)
    {
        printf("%d\n", num1);
        num1++;
    }
}
else
{
    while(num2<=num1)
    {
        printf("%d\n", num2);
        num2++;
    }
}
printf("\n");
}