

#ifndef CV4_DU_H
#define CV4_DU_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>


char* trim(char* str){
    char* r = str+(strlen(str)-1);      // r = koniec stringu
    while (isblank(*r)){                // orezanie od konca
        r--;
    }
    *(r+1)="\0";                        // +1 pre skočenie z písmena na ukončenie stringu
    while (isblank(*str)){              // orezanie od začiatku
        str++;
    }
    return str;
}

char* caesar(char* src, char* dest, int shift){
    int size = strlen(src);
    while (*src != '\0'){
        *dest = *src+shift;
        src++;dest++;
    }
    return dest-size;
}

char* strDel(char* str, int pos, int count){
    int size = strlen(str)-count;
    str=str+pos;

    while(*(str+count) != '\0'){
        *(str) = *(str+count);
        str++;
    }
    *(str) = '\0';
    return str - size;
}

char* strIns(char* dest, int pos, char *src){
    char* first = dest;          // ukazovateľ na prvý prvok v poli
    int size = strlen(src);      // veľkosť pola src
    dest=dest+pos;               // posunutie sa na pozíciu v dest kde sa začnú pridávať prvky z pola src
    while(*src != '\0'){         // kým neprejde sa celé pole src
        *(dest+size) = *dest;    // pridanie do dest zvyšné znaky z dest ktoré sú za pozíciou pos ak nejaké sú
        *dest = *src;            // pridanie do dest znak z src
        dest++;src++;            // posunutie ukazovatela na dest a src
    }
    return first;                // návrat na prvú pozíciu v poli dest
}

int posOfPattern(char* src, char* pattern){
    int pos = 0;
    char* first = pattern;
    int size = strlen(pattern);
    int s = size;
    while(*src != '\0'){
        if(size == 0) { return pos-s;}
        if(*src == *pattern) {
            size--;
            pattern++;
        } else { size = strlen(pattern); pattern=first;}
        src++;pos++;
    }
    return -1;
}

char* substitute(char* src, char* pattern, char* sub){
    char* first = src;
    int pos = posOfPattern(src,pattern);
    int size = strlen(sub);
    src = first+pos;
    while(*src != '\0'){
        if(*sub == '\0'){ return first;}
        *src = *sub;
        sub++;src++;
    }
    return first;
}

_Bool isPalindrome(char* str) {


}


#endif //CV4_DU_H
