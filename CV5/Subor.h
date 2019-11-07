

#ifndef CV5_SUBOR_H
#define CV5_SUBOR_H

#include <stdio.h>
#include <stdlib.h>

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



#endif //CV5_SUBOR_H
