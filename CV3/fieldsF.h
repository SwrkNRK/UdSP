
#ifndef CV3_FIELDSF_H
#define CV3_FIELDSF_H


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <complex.h>



int minF(int *arr, int lenght){
    int min = 2000000;
    for (int i = 0; i < lenght; i++) {
        if(arr[i] < min){ min = arr[i]; }
    }
    return min;
}

double getAbs(double complex val){
    return sqrt(pow(creal(val),2) + pow(cimag(val),2));
}

double complex getGonio(double complex val){
    return getAbs(val) * (cos(creal(val)/getAbs(val)) + I*sin(cimag(val)));
}

double minFComplex(double complex *f, int lenght){
    double min = 2000000;
    for (int i = 0; i < lenght; ++i) {
        if(getAbs(f[i]) < min) { min = getAbs(f[i]); }
    }
    return min;
}


void fillField(int *f, int lenght, int lower, int upper) {
    srand(time(NULL));                      //  inicializácia generátora náhodných čísel srand(time(NULL)) – „náhodná“ inicializácia //<time.h>
    for (int i = 0; i < lenght; ++i) {
        f[i] = rand() % (upper-lower+1) + lower;
    }
}



void fillFieldComplex(double complex *f, int lenght, int lower, int upper){
    srand(time(NULL));                      //  inicializácia generátora náhodných čísel srand(time(NULL)) – „náhodná“ inicializácia //<time.h>
    for (int i = 0; i < lenght; ++i) {
        f[i] = rand() % (upper-lower+1) + lower;
        f[i] += rand() % ((upper-lower+1) + lower) * I;
        printf("%.2lf %2lf\n ",creal(f[i]), cimag(f[i]));
    }
}

void printComplexF(double complex *f, int lenght, int ch){
    switch (ch) {
        case 1:
            for (int i = 0; i < lenght; ++i) {
                printf("%.2lf + %.2lfI\n",creal(f[i]), cimag(f[i]));
            }
            return;
        case 2:
            for (int j = 0; j < lenght; ++j) {
                double complex v = getGonio(f[j]);
                printf("%.2lf + %.2lfI\n",creal(v), cimag(v));
            }
            return;
        default:
            printComplexF(f,lenght,1);
    }
}

void sortDesc(double complex *f, int lenght){
    for (int i = 0; i < lenght; ++i) {
        for (int j = 0; j < lenght; ++j) {
            if (getAbs(f[i]) > getAbs(j)) {
            double complex pom = f[i];
            f[i] = f[j];
            f[j] = pom;
            }
        }
    }
}

void sortAsc(double complex *f, int lenght) {
    for (int i = 0; i < lenght; ++i) {
        for (int j = 0; j < lenght; ++j) {
            if (getAbs(f[i]) > getAbs(j)) {
                double complex pom = f[i];
                f[i] = f[j];
                f[j] = pom;
            }
        }
    }
}

void sortComplexF(double complex *f, int lenght, int ch) {
    switch (ch) {
        case 1:
            sortAsc(f, lenght);
            return;
        case 2:
            sortDesc(f,lenght);
            return;
        default:
            sortAsc(f,lenght);
    }
}





#endif //CV3_FIELDSF_H
