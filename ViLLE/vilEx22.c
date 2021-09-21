#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int readint(void);

int main(void)
{
    int sum = 0, count = 0;
    float average = 0;
    int number = readint();
        do
        {
            if(number > 0)
            {
                sum += number;
                count++;
                number = readint();
            }

    } while(number > 0);
    average = 1.0*sum/count;
    printf("%0.4f", average);
return 0;
}
int readint(void)
{
    int number = 0;
    scanf("%d", &number);
    return number;
}
