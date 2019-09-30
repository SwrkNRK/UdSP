/*
 * Funkcie pre načítanie real čísel a výpis ich súčtu a priemeru
 * výpis real čísle jeho celej a potom desatinnej časti
 * načítanie znaku a výpis ASCII hodnoty a naopak
 * upper a lower case
 * výpočet výdavku
 */

#ifndef CV1_UTWO_H
#define CV1_UTWO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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


void loadR(const int lenght){                         // načítanie real čísel a výpisanie ich súčtu a priemeru
    double rc[5];
    for(int i = 0; i < lenght; i++){
        printf("Zadaj %d real cislo: \n", i+1);
        scanf_s("%lf", &rc[i]);                         // načítanie real čísla a uloženie ho do pola na pozíciu i
    }

    printf("Priemer je : %.2lf \n", avg(rc, lenght));
    printf("Sucet je : %.2lf \n", sum(rc, lenght));
}

void vypisLshowR(char* c){
    int i = 0;                                        // pomocná pre zaznamenie rozdielu medzi celou a desatinnou častou
    printf("Cela cast: ");
    while (c[i] != *".") {                             // kontrola či sa hodnota v poli sa nachádza eśte v celej časti
        printf("%c ", c[i]);
        i++;
    }
    i++;                                                // preskočenie "." v poli
    printf("\ndesatinna cast: ");
    while (c[i] != *"\0") {                              // kontrola či sa hodnota v poli nie je na konci
        printf("%c ", c[i]);
        i++;
    }
    printf("\n");
}

void lshowR() {                                         //načítanie real čísla a vypísanie jeho celej a desatinnú časti
    double cislo = 0;                                   // premenná do ktorej sa uloźí zadaná reálna hodnota
    printf("Zadaj real cislo: \n");
    scanf_s("%lf", &cislo);
    char c[60];
    sprintf(c, "%lf", cislo);                           // skopírovanie zadaného čísla do pola charov
    vypisLshowR(c);                                     // výpis celej a desatinnej časti
}

void lToASCII() {
    char c;                                   // premenná do ktorej sa uloźí znak
    printf("Zadaj znak: \n");
    scanf_s("%c", &c);
    int i = (int) c;
    printf("%d\n",i);
}

void lASCIItoChar() {
    int i;                                   // premenná do ktorej sa uloźí cislo
    printf("Zadaj cislo: \n");
    scanf_s("%d", &i);
    char c = (char) i;
    printf("%c\n",c);
}

char toUpper(char c){
    if(c >= 97 && c <= 122) {
        return (char)(c-32);
    } else return c;
}

char toLower(char c){
    if(c >= 65 && c <= 90) {
        return (char)(c+32);
    } else return c;
}

void platenie(double v, double p){
    double zv = v-p;                        //zvyšok
    int mince[8] = {0,0,0,0,0,0,0,0};                           //2e 1e 0,50e 0,20e 0,10e 0,05e 0,02e 0,01e
    if(zv < 0) {printf("Zaplatili ste málo"); return; }
    if (zv >= 2) { do {mince[0]++; zv-=2; } while(zv >= 2);}
    if (zv >= 1) { do {mince[1]++; zv-=1; } while(zv >= 1);}
    if (zv >= 0.50) { do {mince[2]++; zv-=0.50; } while(zv >= 0.50);}
    if (zv >= 0.20) { do {mince[3]++; zv-=0.20; } while(zv >= 0.20);}
    if (zv >= 0.10) { do {mince[4]++; zv-=0.10; } while(zv >= 0.10);}
    if (zv >= 0.05) { do {mince[5]++; zv-=0.05; } while(zv >= 0.05);}
    if (zv >= 0.02) { do {mince[6]++; zv-=0.02; } while(zv >= 0.02);}
    if (zv >= 0.01) { do {mince[7]++; zv-=0.01; } while(zv >= 0.01);}
    printf("2e = %d\n"
           "1e = %d\n"
           "0.50e = %d\n"
           "0.20e = %d\n"
           "0.10e = %d\n"
           "0.05e = %d\n"
           "0.02e = %d\n"
           "0.01e = %d", mince[0], mince[1], mince[2], mince[3], mince[4], mince[5], mince[6], mince[7]);
}

void vydovok(){
    double vydavok;
    double platba;
    printf("Zadajte kolko je potrebne zaplatit: ");
    scanf_s("%lf", &vydavok);
    printf("Zadajte kolko platite: ");
    scanf_s("%lf", &platba);
    platenie(vydavok, platba);

}

#endif //CV1_UTWO_H
