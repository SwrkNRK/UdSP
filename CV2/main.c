#include <stdio.h>

#include "functions.h"
#include "Dates.h"
#include "hodina2.h"

int main() {
    /*
    double ar[5] = {13315, 15, 1, 545, 54};
    printf("Min: %.2lf", min(ar, 5));
    printf("Factorial %lld", factorial(6));
    */
    //delitele(255);
    //deliteleDva(255,340);
    //(isPn(3)){printf("True\n");}
    pnRozklad(100);
    //printf("%d ",fibo(16));
    //printf("%d",sumFibo(5));
    //zadavanie();
    //kvadR(1,5,4);
/*
    if(isLeapY(2000)){printf("true\n");}
    DATE d = {1, 1, 2019};
    printf("%d\n",whatDay(d));
    printf("%d\n",daysFromStartOfY(d));
    printf("%d\n",daysToEndOfY(d));
    printf("%s\n",getDayName(dayOfWeek(d)));
    printf("%s\n",getDayName(nextDay(d)));
    printf("%s\n",getDayName(previousDay(d)));
    */

    printf("Main: %p\nPrintf: %p\nscanf: %p\n",&main, &printf, &scanf);
    printf("%d\n", sizeof(&main));

    return 0;
}