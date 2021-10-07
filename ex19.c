/* Evgenii Meshcheriakov. Excercise 19 */

#include <stdio.h>

// test by commenting out followed line to simulate running in debug mode with MCUxpresso
// #define DEBUG

#ifdef DEBUG
#define DEBUGMSG 1
#else
#define DEBUGMSG 0
#endif

int main(void)
{
    int num[5];
    printf("Enter five integers: ");
    scanf("%d %d %d %d %d", &num[0], &num[1], &num[2], &num[3], &num[4]);

#if DEBUGMSG
    printf("%d %d %d %d %d\n", num[0], num[1], num[2], num[3], num[4]);
#endif

    return 0;
}


//https://stackoverflow.com/questions/1644868/define-macro-for-debug-printing-in-c