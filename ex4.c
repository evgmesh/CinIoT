/* Evgenii Meshcheriakov. Excercise 4 */

#include <stdio.h>
#include <string.h>

#define INPUT_LEN 20
#define HOUR_MAX 24
#define MINU_MAX 60

void read_input(int *i, char *str, int *hour, int *min);
int main(void)
{
    int curr_h = 0, curr_m = 0, sleep_h = 0, sleep_m = 0, extra_h = 0, sscan_return = 0;
    char str[INPUT_LEN];

    printf("Enter current time (hh:mm): ");
    read_input(&sscan_return, str, &curr_h, &curr_m);

    printf("How long do you want to sleep (h:mm): ");
    read_input(&sscan_return, str, &sleep_h, &sleep_m);

    extra_h = (curr_m + sleep_m) / MINU_MAX;
    curr_m = (curr_m + sleep_m) % MINU_MAX;
    curr_h = (curr_h + sleep_h + extra_h) % HOUR_MAX;
    printf("If you go to bed now you must wake up at %02d:%02d\n", curr_h, curr_m);

    return 0;
}

void read_input(int *i, char *str, int *hour, int *min)
{
    fgets(str, INPUT_LEN, stdin);
        if(str[strlen(str)-1] == '\n')
        {
            str[strlen(str)-1] = '\0';
        }
    *i = sscanf(str, "%2d%*[:]%2d", hour, min);
    while(*i != 2 || *hour < 0 || *min < 0 || *hour >= HOUR_MAX || *min >= MINU_MAX)
    {
        printf("Time must have format (hh:mm): ");
        fgets(str, INPUT_LEN, stdin);
        if (str[strlen(str)-1] == '\n')
        {
            str[strlen(str)-1] = '\0';
        }
        *i = sscanf(str, "%2d%*[:]%2d", hour, min);
    }
}

