/*
 * Min, faktorial
 */

#ifndef CV2_FUNCTIONS_H
#define CV2_FUNCTIONS_H

#include <stdio.h>
#include <math.h>
#include <stdbool.h>



double min(double *arr, int lenght){
    int min = 2000000;
    for (int i = 0; i < lenght; i++) {
        if(arr[i] < min){ min = arr[i]; }
    }
    return min;
}

unsigned long long int factorial(int n){
    unsigned long long int fac = n;
    while(n > 1){
        n--;
        fac *= n;
    }
    return fac;
}

void delitele(int n){
    for (int i = 1; i < n; i++) {
        if(n%i == 0){ printf("%d ",i); }
    }
    printf("\n");
}

void deliteleDva(int n1, int n2){
    int max = 0;
    if( n1 < n2 ){ max = n1; n1 = n2; n2 = max; max = 0; } // vymenenie n1 a n2 v prípade ak je n1 menšie ako n2
    for (int i = 1; i < n1; i++) {
        if(n1%i == 0 && n2%i == 0){ max = i;}
    }
    printf("Najvacsi delitel je %d\n",max);
}

bool isPn(int n){                       // prime number
    if (n < 0) { return false;}
    int i=0;
    for (int j = 1; j < n; ++j) {
        if(n%j == 0) {i++; }
        if(i>1) { return false; }
    }

    return true;
}

void pnRozklad(int n){
    int pn[30]= {0};
    int lenght = 0;
    for (int i = n-1; i > 1; i--) {
        if(isPn((n-i)) && n > 0 && isPn(i)) {
            pn[lenght]=i;
            n=n-i;
            lenght++;
        }
    }
    for (int j = 0; j <lenght ; ++j) {
        printf("%d ",pn[j]);
    }
    printf("\n");
}

int fibo(int n){
    int a = 1;
    int b = 0;
    for (int i = 0; i < n; ++i) {
        b = a-b;
        a = a + b;
    }
    return b;
}

int sumFibo(int n){
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += fibo(i);
    }
    return sum;
}

double sum(double *rc, int lenght){                 // výpočet súčtu pre všetky hodnoty v poli
    double sum = 0;
    for(int i = 0; i < lenght; i++){
        sum += rc[i];
    }
    return sum;
}

double avg(double *rc, int lenght) {            // výpočet priemeru pre všetky hodnoty v poli
    return sum(rc, lenght)/lenght;
}

void zadavanie(){
    int lenght = -1;
    double p[100] = {0};
    do {
        lenght++;
        printf("zadajte cislo :  ");
        scanf("%lf", &p[lenght]);
    } while (p[lenght] != 0);
    printf("AVG: %.2lf \n SUM: %.2lf",avg(p,lenght), sum(p, lenght));
}

double diskr(double a, double b, double c){
    return (double)(pow(b,2) - (4*a*c));
}


void kvadR(double a, double b, double c){
    double x1,x2;
    x1 = ((-b) + sqrt((diskr(a,b,c)))) / (2*a);
    x2 = ((-b) - sqrt((diskr(a,b,c)))) / (2*a);
    printf("x1 = %.2lf\nx2 = %.2lf\n",x1, x2);

}












#endif //CV2_FUNCTIONS_H
