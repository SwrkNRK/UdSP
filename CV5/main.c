#include <stdio.h>
#include "CV5.h"
#include "Bonus.h"
#include "Subor.h"



int main() {
    
    char strA[100] = "Hello kind my frands";
    char strB[100] = "lod my ran";
    int i = 0;
    //printf("%d\n",copyFile("C:\\Users\\LK\\Desktop\\UdSP\\UdSP\\CV5\\Source.txt", "C:\\Users\\LK\\Desktop\\UdSP\\UdSP\\CV5\\Dest.txt"));
    char* s = longestSubstr(strA, strB, &i);
    printf("%d : %s\n",i,s);

    //sucet(strA,strB);
    //odpocet(strA,strB);
    //nasobenie(strA,strB);
    //delenie(strA,strB);
    printf("\nFinish\n");
    //rodC();


    /*
    FILE *src = fopen("C:\\Users\\LK\\Desktop\\UdSP\\UdSP\\CV5\\Source.txt","r+");
    //FILE *src2 = fopen(argv[1],"w");

    if(src != NULL){
    //súbor existuje;
    }
    FILE *dest = fopen("C:\\Users\\LK\\Desktop\\UdSP\\UdSP\\CV5\\Dest.txt", "w");
    char vyskyt[10] = "jur";
    char nahrad[10] = "robin";
    nahradaRetazca(src, dest, vyskyt, nahrad); */


    //*******************************DU*********************************************

    /*
    float a = 4;
    float b = 5;
    float c = 6;
    complex d,e;

    int n = 4;
    int g = 3;
    int h = 4;
    complex pole1[4] = {2+2*I,4+4*I,6+6*I,40 + 400*I};
    complex pole2[3] = {10+100*I,20+200*I,30+300*I};
    complex poleVysledne[4];

    //swap(&a,&b);
    //kvadratKomplex(&a,&b,&c,&d,&e);


    sucetKPolynomov(n, pole1, g, pole2, h, poleVysledne);

    for(int i = 0; i < h; i++){

      printf("%.2f + %.2fi \n",creal(*(poleVysledne + i)), cimag(*(poleVysledne+i)));
    }


    int poleTest[5] = {2,4,1,8,9};
    int index;
    int minimum;
    //minimumZPola(5,poleTest,&index, &minimum);
    // printf("%d minimum = %d\n",index, minimum);

    int poleModus[10] = {1,5,4,9,22,30,22,4,5,22};
    int modus;
    int median;
    /*
   modusMedian(10, poleModus, &modus, &median);
   printf("Modus je: %d\n",modus);
   printf("median je: %d\n",median);
   */
    /*
    char poleChar[10];
    randCharz(10, poleChar);
    for(int i = 0; i < 10; i++){
        printf("%c \n",*(poleChar+i));
    }*/
    /*
    int poleArray[3];
    intToArray(935, 3, poleArray);
    for(int i = 0; i < 3;i++){
        printf("%d ",poleArray[i]);
    }*/

    //char poleCharov[10];
    //freqAnalyza(10,poleCharov);
    /*
    int runSum[10] = {};
    int data[10] = {1,2,3,4,5,6,7,8,9,10};
    runningSum(10, data, runSum);
    for (int i = 0; i < 10; i++){
        printf("%d = %d\n",i,*(runSum+i));
    }*/
    /*
    if(jeLittleEndian())
        printf("Poradie bajtov je little endian.\n");
    else
        printf("Poradie bajtov je big endian.\n");
    */


    /*
    int arrayA[5] = {2,4,8,1,2};
    int arrayB[10] = {10,9,8,7,6,5,4,3,2,1};
    int arrayAB[15];
    merge(5, arrayA, 10, arrayB, arrayAB);
    for (int i = 0; i < 15; i++){
        printf("%d = %d\n",i,*(arrayAB+i));
    }

    //program
    int pocetCifier;
    for(int i = 1; i < 10; i++){
        printf("%f \n",gaussIntegral(-i, i));
    }
    */

    return 0;
}