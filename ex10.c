/* Evgenii Meshcheriakov. Excercise 10 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "txt10.txt"
#define LEN 20

int read_input(char *str, FILE *fp, float *num);

int main(void)
{
    FILE *txt10;
    char str[LEN];
    int linesRead = 0;
    float sum = 0, value = 0, linesSpec = 0;

    txt10 = fopen(FILENAME, "r");
    if(txt10 == NULL) {
        printf("File does not exits\n");
    }
    else{
        read_input(str,txt10, &linesSpec);
        while(!feof(txt10)) {
            if(read_input(str,txt10, &value) == 1) {
                sum += value;
                linesRead++;
            }
        }
    }
    fclose(txt10);
    if(linesRead != linesSpec){
        printf("Error! Tried to read %.0f numbers, %d were read.\nAverage of %d " 
            "numbers is: %.2f\n", linesSpec, linesRead, linesRead, sum/linesRead);
    }
    else printf("Average of %.0f numbers is: %.2f\n", linesSpec, sum/(linesSpec));
    return 0;
}
int read_input(char *str, FILE *fp, float * num)
{
    if(fgets(str, LEN, fp) == NULL) return 0;
    if(str[strlen(str)-1] == '\n'){
        str[strlen(str)-1] = '\0';
    }
    return sscanf(str, "%f", num);
}