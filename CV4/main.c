#include <stdio.h>
#include "DU.h"

int main() {
    char te[100] = "abcdee";
    char dst[100] = "bc";
    printf("%s\n",substitute(te,dst,"gg"));
    //printf("%s\n",strIns(dst,1,te));
    //printf("%s\n",strDel(te,1,4));
    //printf("%s %s\n",trim(te),trim(te));
    return 0;
}