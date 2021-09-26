#include <stdio.h>
#include <string.h>

int main(void)
{
    int matrix[5][3];
    int count = 1;
    for(int i = 0; i<3; i++) {
        for(int j = 0; j <5; j++) {
            matrix[j][i] = count;
            count ++;
        }
    }
    for(int i = 0; i<5; i++) {
        for(int j = 0; j <3; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

return 0;
}