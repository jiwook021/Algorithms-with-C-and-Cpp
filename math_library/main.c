#include <stdio.h>
#include <math.h>

int main()
{
    int usertemp;
    scanf("%d", &usertemp);
    printf("%.8f \n", sqrt(usertemp));
    printf("%.10f \n", exp(1));
    printf("gcc -std=c11 -Wall -fmax-errors=10 -Wextra program.c -o program -lm");
}