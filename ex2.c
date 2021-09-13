/* Evgenii Meshcheriakov. Excercise 2 */

#include<stdio.h>
#define ARR_SIZE 12

int main(void)
{
    float array[ARR_SIZE] = {};
    float temp = 0, total = 0;
    printf("Enter a yearly gross income, please\n");
    for(int i = 0; i<ARR_SIZE; i++)
    {
        scanf("%f", &temp);

        if(i == 6)
        {
            array[i] = temp/12.5*1.5;
        }
        else
        {
            array[i] = temp/12.5;
        }
    }
    for(int i = 0; i<ARR_SIZE; i++)
    {
        printf("element [%2d] = %11.4f\n", i, array[i]);
        total += array[i];
    }
    printf("total        = %11.4f\n", total);
    return 0;
}