#include <stdio.h>
#include "DU.h"

int main() {
    char te[100] = "Ahoj Jano";
    char dst[100] = "tenet";
    //printf("%s\n",substitute(te,dst,"Fero"));
    printf("%s\n",toUpperStr(dst));
    printf("%s\n",toLowerStr(dst));
    if(isPalindrome(dst)){printf("FAS\n");}
    //printf("%s\n",strIns(dst,1,te));
    //printf("%s\n",strDel(te,1,4));
    //printf("%s %s\n",trim(te),trim(te));
    return 0;
}