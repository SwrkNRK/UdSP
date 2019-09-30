
#ifndef CV3_PROG_H
#define CV3_PROG_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <complex.h>

void hadajCislo(int lower, int upper){
    srand(time(NULL));
    int c = rand() % (upper-lower+1) + lower;
    int i = 0;
    printf("Hadaj cislo: ");
    do {
        scanf("%d", &i);
        if (i < c) { printf("Hladane cislo je vacsie\n Hadaj znova: ");}
        else {printf("Hladane cislo je mensie\n Hadaj znova: ");}
        printf("\n");
    } while (c != i);
    printf("Uhadol si\n");
}


double diskr(double a, double b, double c){
    return (double)(pow(b,2) - (4*a*c));;
}


void kvadR(double a, double b, double c){
    double x1,x2;
    double disk = diskr(a,b,c);
    double complex xi1, xi2;
    if (diskr(a,b,c) < 0) {
        xi1 = (((-b) + sqrt((disk*(-1)))*I )/ (2*a));
        xi2 = (((-b) - sqrt((disk*(-1)))*I )/ (2*a));
        printf("x1 = %.2lf + %.2lf\nx2 = %.2lf + %.2lf\n",creal(xi1), cimag(xi1), creal(xi2), cimag(xi2));
    } else {
        x1 = ((-b) + sqrt(disk)) / (2*a);
        x2 = ((-b) - sqrt(disk)) / (2*a);
        printf("x1 = %.2lf \nx2 = %.2lf\n",x1,x2);
    }
}



#endif //CV3_PROG_H
