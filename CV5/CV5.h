

#ifndef CV5_CV5_H
#define CV5_CV5_H

#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <limits.h>
#include <math.h>
#include <string.h>
#include <time.h>

void swap(int* a, int* b){
    int c = *a;
    *a = *b;
    *b = c;
    printf("a = %d b = %d\n",*a,*b);
}

kvadratKomplex(float* a, float* b, float* c,complex* d, complex* e){

    float D = (((*b) * (*b)) - 4 * (*a) * (*c));

    complex trueD;
    if (D < 0) {
        D = D*(-1);
        trueD = sqrt(D)*I;

        complex x1 = (((*b) * (-1)) + trueD) / (2 * (*a));
        complex x2 = (((*b) * (-1)) - trueD) / (2 * (*a));
        *d = x1;
        *e = x2;

    } else {
        float x1 = (((*b) * (-1)) + sqrtf(D)) / (2 * (*a));
        float x2 = (((*b) * (-1)) - sqrtf(D)) / (2 * (*a));
        *d = x1;
        *e = x2;
    }
    return *d,*e;
}


sucetKPolynomov(int n, complex pole1[n], int g, complex pole2[g], int h, complex poleVysledne[h]){

    for(int i = 0; i < h; i++){
        *(poleVysledne+i) = ((*(pole1+i)) + (*(pole2+i)));
    }

    return *poleVysledne;
}


minimumZPola(int n, int pole[n], int* index, int* minimum){
    *minimum = INT_MAX;

    for(int i = 0; i < n; i++){
        int a = *(pole+i);
        if( a < *minimum){
            *minimum = *(pole+i);
            *index = i;
        }
    }
    return *index,*minimum;
}

int modusMedian(int n, int pole[n],int* modus, int* median){
    int zoradenePole[n];
    int pom;
    int p1=0;
    int p2=0;
    for(int i = 0; i < n; i++){
        zoradenePole[i] = pole[i];
    }
    for(int j = 0; j < n; j++){

        for(int i = 0; i < n - 1; i++){
            if(zoradenePole[i] > zoradenePole[i+1]){
                pom = zoradenePole[i+1];
                zoradenePole[i+1] = zoradenePole[i];
                zoradenePole[i] = pom;
            }

        }
    }
    for(int i = 0; i <= n-1; i++){

        if(zoradenePole[i] == zoradenePole[i+1]){

            p1++;

            if(p1>p2){
                p2 = p1;
                *modus = zoradenePole[i];
            }
        }

    }

    *median = (zoradenePole[4] + zoradenePole[5])/2;
    return *modus, *median;
}

char* randCharz(int n, char* pole){
    int a,b,c;
    srand(time(NULL));
    char* end = pole + n;
    for(char* i = pole; i < end; i++){
        //randNumb = rand()%(122-97) +97;
        a = rand()%('z' - 'a' + 1) +'a';
        b = rand()%('Z' - 'A' + 1) +'A';
        c = rand()%('9' - '0' + 1) +'0';
        int selection = rand() % 3;
        *i =(char)(selection == 0 ? a:
                   (selection == 1 ? b: c));
    }
    return pole;

}
_Bool jeLittleEndian() {
    double cislo = 1.1;
    return ((char*) &cislo)[0] == (char) 1;
}


char freqAnalyza(int n, char pole[n]){

    scanf("%s",pole);
    for (int j = 0; j < n; j++){
        printf("%c",*(pole+j));
        for (int i = 0; i < n; i++){
            if(*(pole+j) == *(pole+i)){
                printf("*");
            }
        }
        printf("\n");
    }


}

int* runningSum(int n, int data[n], int runningSum[n]){
    int suma;
    for (int j = 0; j < n; j++){
        suma = 0;
        for (int i = 0; i <= j; i++ ){
            suma = *(data+i) + suma;
        }
        *(runningSum+j) = suma;
    }
    return*runningSum;
}

char* intToStr(int number, int n, char* dest){
    char *start = dest;
    int nn = 1000000;
    int c=0;
    while (nn > 1) {
        nn /= 10;
        if (number >= nn) {
            c = 0;
            while(number >= nn) {
                c++;
                number-=nn;
            }
            *dest = c+'0';
            dest++;
        }

    }
    return start;
}

int* intToArray(int number, int n, int array[n]){
    int delitel = 1;
    int c = 100;
    while(number/delitel > 10){
        delitel = delitel*10;


    }
    int PD = delitel;
    while (number-delitel > PD) {

        delitel = delitel+c;

    }
    number = number - delitel;
    *(array) = (delitel/PD);
    delitel = (PD/10);
    PD = delitel;
    c=10;
    while (number-delitel > PD) {

        delitel = delitel+c;

    }
    *(array+1) = (delitel/PD);
    number = number - delitel;
    *(array+2) = number;
    return array;
}

double gaussIntegral(double a, double b){
#define COUNTT 1000
#define M_E 2.7182818284590452354 /*e*/

    double h = (b-a)/COUNTT;
    double sum = 0;
    for (int i = 0; i < COUNTT; i++) {
        sum += pow(M_E, -(a+i*h)*(a+i*h)) * h;
    }
    return sum;

#undef COUNTT
#undef M_E
}



int* merge(int m, int sortedArrayA[m], int n, int sortedArrayB[n], int destArray[n+m]){
    int pocitadlovoFore;
    int pom;
    for(int i = 0; i < m; i++){
        *(destArray+i) = *(sortedArrayA+i);
    }
    for(int i = 0; i < n; i++){
        *(destArray+(m+i)) = *(sortedArrayB+i);
    }
    for(int j = 0; j < (n+m); j++){
        pocitadlovoFore = 0;
        for(int i = 0; i < (n+m-1); i++){
            if(destArray[pocitadlovoFore] > destArray[i+1]){
                pom = destArray[i+1];
                destArray[i+1] = destArray[pocitadlovoFore];
                destArray[pocitadlovoFore] = pom;
            }
            pocitadlovoFore++;
        }

    }
    return destArray;
}






#endif //CV5_CV5_H
