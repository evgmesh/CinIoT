#include <stdio.h>
#include <string.h>

#define SIZE 10

int largest(int *numbers, int count);
int main(void)
{
        int array[SIZE] = {11,5,3,100,7,9,10};
        printf("%d\n", largest(array, SIZE));
}

int largest(int *numbers, int count)
{
    int result = 0;
    for(int i = 0; i<count; i++)
    {
        if(numbers[i] > result)
        {
            result = numbers[i];
        }
    }
    return result;
}