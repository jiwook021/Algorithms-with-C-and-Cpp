#include <stdio.h>
#include <math.h>

int main()
{
    int usertemp;
    printf("Input a Integer\n");
    scanf("%d", &usertemp);
    printf("Square root of %d is %.8f \n", usertemp, sqrt(usertemp));
    printf("e to the 1 is %.10f \n", exp(1));
 }