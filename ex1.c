/* Evgenii Meshcheriakov. Excercise 1 */

#include <stdio.h>

int main(void)
{
    float sum = 0;
    float enteredNum = 0;
    int nNumbers = 0;

    printf("Please enter the positive number\n");
    do
    {
        scanf("%f", &enteredNum);
        if(enteredNum < 0)
        {
            printf("Sorry, only positive numbers are accepted. Enter the number again\n");
        }
        else if (enteredNum > 0)
        {
            sum += enteredNum;
            nNumbers++;
        }
    } while(enteredNum != 0);
    printf("Average is %0.2f\n", sum/nNumbers);
    return 0;
}

