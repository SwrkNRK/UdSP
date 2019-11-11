

#ifndef CV5_SUBOR_H
#define CV5_SUBOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

int copyFile(const char* srcFileName, const char* destFileName){
    FILE* srcFile = fopen(srcFileName,"r");
    if(srcFile == NULL){ return -1; }

    FILE* destFile = fopen(destFileName, "w");
    if(destFile == NULL){ fclose(srcFile); return -2; }

    int c = fgetc(srcFile);
    while (c != EOF){
        fputc(c, destFile);
        c = fgetc(srcFile);
    }

    fclose(srcFile);
    if(fclose(destFile) != 0) {
        perror("Closing dest file has failed");
    }
    return 0;
}

int* zamiesaniePola(int n, int pole[n]){
    int random;
    int pom;
    int size = n;

    for(int i = 0; i < n; i++){
        random = rand()%(size);
        pom = pole[random];
        pole[random] = pole[i];
        pole[i] = pom;
    }

    printf("Zamiešanie hotovo\n");
    return pole;
}

int scitanieRiadkov(FILE* src){
    rewind(src);
    int riadok = 1;
    int c = 0;
    while(c != EOF){
        c = fgetc(src);

        if(c == '\n'){
            riadok++;
        }
    }
    return riadok;
}


int* indexyRiadkov(FILE* src, int n, int pole[]){
    rewind(src);
    pole[0] = 0;
    int i = 1;
    int c = 0;
    while(c != EOF){
        c = fgetc(src);

        if(c == '\n'){

            pole[i] = ftell(src);

            i++;
        }
    }

    return pole;
}


void kopirovanie(FILE* src, FILE* dest){

    int c = 0;
    while(c != EOF){
        c = fgetc(src);
        if(c != EOF)
            fputc(c,dest);
    }


}
void presun(FILE* src, FILE* dest){
    int c = 0;
    while(c != EOF){
        c = fgetc(src);
        if(c != EOF)
            fputc(c,dest);
    }
    remove("Source.txt");
}
void prehadzovanie(FILE* src, FILE* dest){
    int pom = 1;
    int c = 0;
    while(c != EOF){
        c = fgetc(src);

        if(c == '\n'){
            pom++;
        }
    }
    rewind(src);
    c = 0;
    int polePom[pom];
    polePom[0] = 0;
    int i = 1;

    while(c != EOF){
        c = fgetc(src);

        if(c == '\n'){
            polePom[i] = ftell(src);

            i++;
        }
    }

    zamiesaniePola(pom, polePom);

    for(int g = 0; g < pom; g++){
        printf("%d ",polePom[g]);

    }

    int a = 0;
    i = 0;
    for(int j = 0 ; j < pom; j++){
        rewind(src);
        fseek(src,polePom[i],SEEK_CUR);
        a = 0;
        while(a != '\n'){

            a = fgetc(src);
            if(a == EOF){

                fseek(src,8,SEEK_CUR);
                a = fgetc(src);
                fputc(a, dest);
                break;
            }
            fputc(a, dest);
        }



        i++;
    }
}

void odstranenieRiadku(FILE* src, FILE* dest, int riadok){
    riadok = riadok -1;
    int pom = scitanieRiadkov(src);
    int pomPole[pom];
    indexyRiadkov(src,pom,pomPole);
    for(int i = 0; i < pom; i++){
        printf("%d ",pomPole[i]);
    }
    int c = 0;
    long position = 0;
    rewind(src);
    while(c != EOF){
        position = ftell(src);
        c = fgetc(src);
        if(position != pomPole[riadok]){
        fputc(c,dest);
    }
    if(position == pomPole[riadok] && position != pomPole[pom-1]){
    fseek(src,pomPole[riadok+1],SEEK_SET);

    }
    else if(position == pomPole[pom-1] && position == pomPole[riadok]){
    break;
        }
    }
}

void putToFile(FILE* dest, char* nnahrad, char* ttmp, int* pocitadlo) {

    *(ttmp + (*pocitadlo)) = '\0';
    fputs(nnahrad,dest);
    strcpy(ttmp, "");
    *pocitadlo = 0;

}

void nahradaRetazca(FILE* src, FILE* dest, char* vyskyt, char* nahrad) {
    int c = 0;
    int i = 0;
    int size = strlen(vyskyt);
    char tmp[size+1];
    strcpy(tmp, "");
    rewind(src);
    while (c != EOF) {
        c = fgetc(src);
        if (c == *(vyskyt + i)) {
            *(tmp + i) = (char) c;
            i++;
            if(i == size){
                putToFile(dest,nahrad,tmp,&i);
            }

        } else {
            if(i != 0) {
                putToFile(dest,tmp,tmp,&i);
            } else {
                if(c == EOF){ break;}
                fputc(c, dest);
            }
        }
    }
}



void sifrovanie(FILE* src, FILE* dest, int posun){
    int c = 0;
    while(c != EOF){
        c = fgetc(src);
        if(c != EOF)
            fputc((c+posun),dest);
    }
}

void desifrovanie(FILE* src, FILE* dest, int posun){
int c = 0;
while(c != EOF){
c = fgetc(src);
if(c != EOF)
fputc((c-posun),dest);
}
}

void FilefreqAnalyza(FILE* src, FILE* dest){
rewind(src);
char pomPole[200];
int pocitadlo[200];
int c = 0;
int a = 0;
while(c != EOF){
c = fgetc(src);
if(c != EOF)
if(c != '\n' && !isspace(c)){
pomPole[a] = c;
a++;
}
}
int poc = 0;
for(int j = 0; j < strlen(pomPole); j++){
poc = 0;
for(int i = 0; i < strlen(pomPole); i++){

if(pomPole[j] == pomPole[i]){
if(i != j){
pomPole[i] = '!';
}
poc++;

}
}
pocitadlo[j] = poc;
}
for(int i = 0; i < strlen(pomPole); i++){
if(pomPole[i] != '!'){
printf("%c = %d\n",pomPole[i],pocitadlo[i]);
}
}

}

void staty(FILE* src){
int pocPismen = 0;
int pocRiadok = scitanieRiadkov(src);
int bieleZnaky = 0;
int vsetkyZnaky = 0;
int slova = 0;
int c = 0;
rewind(src);
while(c != EOF){
c = fgetc(src);
if(c != EOF){
if(isalpha(c)){
pocPismen++;
}
if(isspace(c)){
bieleZnaky++;
}
vsetkyZnaky++;
}
}

rewind(src);
c = 0;
long position = 0;
while(c != EOF){
position = ftell(src);
c = fgetc(src);
if(isblank(c) || c == '\n'){
slova++;
}
}

printf("Počet písmen = %d\n",pocPismen);
printf("Počet riadkov = %d\n",pocRiadok);
printf("Počet bielych znakov = %d\n",bieleZnaky);
printf("Počet všetkých znakov = %d\n",vsetkyZnaky);
printf("Počet slov = %d\n",slova);
}






#endif //CV5_SUBOR_H
