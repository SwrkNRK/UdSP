

#ifndef CV5_BONUS_H
#define CV5_BONUS_H

#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <limits.h>
#include <math.h>
#include <string.h>
#include <time.h>

//0162302217
int rodC(){
    char pole[20];
    printf("Zadaj retazec\n");
    scanf("%s",pole);
    if(strlen(pole) != 10){ return 0;}

printf("%d\n",INT_MAX);
    if((*pole-'0') == 0 || (*pole-'0') == 9){             //kontrola roku narodenia
        printf("Rok\n");
        if(*(pole+2)-'0' == 6 || *(pole+2)-'0' == 5 || *(pole+2)-'0' <= 1 ){     //kontrola mesiaca
            printf("Mesiac\n");
            if(*(pole+4)-'0' < 4 ) {                       //kontrola dna
                printf("Den\n");
                if(atol((pole)) % 11 == 0) {                //kontrola modula 11
                    printf("Je to rodne cislo\n");
                    return 1;

                }
            }
        }
    }

    return 0;
}
void correctStr(char* str, int n, char patern){

    for (int j = 0; j < n; ++j) {
        for (int i = strlen(str); i > 0; i--) {
            *(str + i) = *(str + i - 1);
        }
        *str = patern;
    }
}

void sucet(char* strA, char* strB){
    int Alen = strlen(strA)-1;
    int Blen = strlen(strB)-1;
    if(Alen > Blen) {correctStr(strB, Alen-Blen, '0');}
    else if (Blen > Alen){correctStr(strA, Blen-Alen, '0');}
    char s;
    int ss = 0;
    int pom = 0;
    int n = 0;
    for(int i = Alen; i > -1; i--){

        pom = *(strA+i)-'0';
        ss = ((*(strB+i)-'0') + (*(strA+i)-'0') + n);
        s=(ss%10)+'0';
        *(strA+i)=s;
        if(*(strA+i)-'0' < pom) {
            n=1;
        } else { n = 0;}
    }
    if(n == 1) {

        *(strA+Alen+2) = '\0';
        for(int i = Alen+1; i > 0; i--) {
            *(strA+i) = *(strA+i-1);
        }
        *strA = n+'0';
    }

//printf("Vysledok po scitani: %s\n",strA);
}

void odpocet(char* strA, char* strB){
    int Alen = strlen(strA)-1;
    int Blen = strlen(strB)-1;
    if(Alen > Blen) {correctStr(strB, Alen-Blen, '0');}
    else if (Blen > Alen){correctStr(strA, Blen-Alen, '0');}
    int sA;
    int sB = 0;
    int n = 0;
    for(int i = Alen; i > 0; i--){
    sA = *(strA+i)-'0';
    sB = *(strB+i)-'0'+n;
    sA -= sB;
    if(sA < 0) {sA += 10; n=1;} else {n=0;}
    *(strA+i)=sA+'0';
    }

    sA=*strA-'0';
    sB=*strB-'0'+n;

    if(sA<sB) {
        for (int i = strlen(strA); i > 0; --i) {
            *(strA+i) = *(strA+i-1);
        }
        *strA='-';
        *(strA+1)=(sB-sA)+'0';
    } else {
        sA = *(strA)-'0';
        sB = *(strB)-'0'+n;
        sA -= sB;
        *(strA)=sA+'0';
    }
       // printf("Vysledok po odpocte: %s\n",strA);
}


void nasobenie(char* strA, char* strB) {
    int Alen = strlen(strA)-1;
    int Blen = strlen(strB)-1;

    int sA;
    int sB = 0;
    int n = 0;
    int posun = 0;
    char pom[100];
    char suc[100]="0";
    strcpy(pom,strA);
    for(int j = Blen; j > -1; j--) {
        for (int i = Alen; i > -1; i--) {
            sA = *(pom + i) - '0';
            sB = *(strB+j) - '0';
            sA *= sB;
            sA+=n;
            if(sA >= 10) {
                n = sA;
                sA = sA % 10;
                n = (n - sA) / 10;
            } else { n = 0;}
            *(pom + i) = sA + '0';
        }
        if(n!=0) {
            for (int i = strlen(pom); i > 0; --i) {
                *(pom+i) = *(pom+i-1);
            }
            *pom = '1';
            n=0;
        }
            if(posun==0){
                strcpy(suc,pom);
            } else {
                for (int i = 0; i < posun; ++i) {
                    *(pom+strlen(pom)) = '0';
                }
                sucet(suc, pom);
            }

        posun++;
        strcpy(pom,strA);
    }
    strcpy(strA,suc);
    printf("výsledok: %s\n",strA);
}

int isStrNUll(char* str){
    for (int i = 0; i <strlen(str) ; ++i) {
        if(*(str+i) != '0'){ return 0;}
    }
    return 1;
}

void delenie(char* strA, char* strB){

    char tmp[100]="1";
    char tmp2[100]="1";
    char c = "546";
    char t[10]="2";
    char t2[10]="1";

    while(1){
        strcpy(tmp2,strA);
        odpocet(tmp2,strB);
        c=*tmp2;
        sucet(tmp,t2);
        if(c != '-'){odpocet(strA,strB);} else { break;}

    }

    odpocet(tmp,t);
    printf("STRA: %s\n",tmp);
    *(strA+strlen(strA))='0';
    *(tmp+strlen(tmp))=',';

    char tmp3[100]="1";
    char tmp4[100]="2";

    int cc = 0;
    char tLast[100]="";
    int index=0;
    while(cc != 30){
        strcpy(tmp3,strA);
        odpocet(tmp3,strB);
        c=*tmp3;
        sucet(tmp4,t2);

        if(c != '-'){odpocet(strA,strB); if(isStrNUll(strA)){ break;}}
        if(c == '-'){
            *(strA+strlen(strA))='0';
            odpocet(tmp4,t);
            *(tLast+index)=*(tmp4+1);
            index++;
            strcpy(tmp4,t2);

        }
        cc++;
    }

    printf("STRA2: %s\n",tLast);
    for (int i = 0; i <strlen(tLast) ; ++i) {
        *(tmp+strlen(tmp))=*(tLast+i);
    }

    strcpy(strA,tmp);
    printf("Vysledok po deleni: %s\n",strA);
}

int longestSub(const char*strA, const char* strB, int pos, int* lenght, char** startPos){
    int max = *lenght;                                // max = doterajšia nájdená max hodnota
    int pocitadlo = 0;                                // pocitadlo pre zhodujúce sa písmená po sebe
    for (int i = 0; i <strlen(strB) ; ++i) {          // cyklus prejde celé pole strB
        if(*(strA+pos+pocitadlo) == *(strB+i)) {      // if true bude sa v ďalšom cykle hľadať zhoda v nasledujúcom písmene atd
            pocitadlo++;                              // navýšenie počitadla pre posunutie sa k ďalšiemu písmenu
            if(max < pocitadlo){ max = pocitadlo; *startPos = (strA+pos);} //ak pocitadlo je viac ako max nastavenie nového max a zaznamenanie pozície písme do startPos
        } else{pocitadlo=0;}                          // znulovanie pocitadla
        if(*(strA+pos+pocitadlo) == '\0') {break;}    // zistenie či už nie sme na konci pola
    }
    if(max < pocitadlo){ *startPos = (strA+pos); return pocitadlo;} // na konci cyklu opätovná kontrola maxima a pocitadla
    return max;
}

const char* longestSubstr(const char*strA, const char* strB, int* length){
    int i = 0;
    char* position = strA;
    while(*(strA+i) != '\0') {
        *length = longestSub(strA,strB,i,length, &position);
        i++;
    }
    if(*length == 0){ return NULL;}
    return position;
}





#endif //CV5_BONUS_H
