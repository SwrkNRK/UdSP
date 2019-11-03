#include <stdio.h>
#include "CV5.h"
#include "Bonus.h"


int main() {
    char strA[100] = "33";
    char strB[100] = "15";
    int i = 212;
    intToStr(i,1,strA);
    printf("efw: %s\n",strA);
    //char* s = longestSubstr(strA, strB, &i);
    //sucet(strA,strB);
    odpocet(strA,strB);
    //nasobenie(strA,strB);
    //delenie(strA,strB);
    printf("");
    //rodC();

    return 0;
}