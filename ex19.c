/* Evgenii Meshcheriakov. Excercise 19 */

#include <stdio.h>

// In CS50 IDE test by commenting out followed line to simulate running in debug mode with MCUxpresso
// #define DEBUG

#ifdef DEBUG
#define DEBUGMSG(...) printf(__VA_ARGS__)
#else
#define DEBUGMSG(...)
#endif

int main(void)
{
    int num[5];
    printf("Enter five integers: ");
    for(int i = 0; i<5; i++)
    {
        scanf("%d", &num[i]);
        DEBUGMSG("%d\n", i);
    }
    return 0;
}
