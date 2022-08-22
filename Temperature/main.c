#include <stdio.h>

double ftoc(int x);
double ctof(int x);

int main(void) {

    int usertemp;
    char unit;
    double convertedtemp;

    scanf("%d %c", &usertemp, &unit);
    if (unit == 'C') {
        printf("%.1f F", ctof(usertemp));
    }
    else if (unit == 'F') {
        printf("%.1f C", ftoc(usertemp));
    }

    return 0;

}


double ctof(int x) {
    return((9.0 / 5) * x + 32);
}


double ftoc(int x) {
    return(5.0 / 9 * (x - 32));
}