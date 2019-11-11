#include <stdio.h>
#include "EvidStructs.h"
#include "EvidFunctions.h"

int main() {

    LIST list;
    list.booksCount=0;
    list.authorsCount=0;
    FILE *subor = fopen("C:\\Users\\LK\\Desktop\\UdSP\\UdSP\\CV6\\subor.txt","r");
    importData(&list,subor);
    //printBookList(&list);
    DATE dateOd = {1,1,1800};
    DATE dateDo;
    dateDo.day = 10;
    dateDo.month = 2;
    dateDo.year = 1850;
    /*
    //printBookBetweenDates(&list,dateOd,dateDo);
    FILE* outputBin = fopen("pom.bin","w");
    saveToFile(&list, outputBin);
    fclose(outputBin);

    LIST list2;
    FILE* inputBin = fopen("pom.bin","r");
    loadFromFile(&list2, inputBin);
    fclose(inputBin);
    printBookList(&list2);
    */
    // delaUthor(&list);
    //printBookList(&list);
    fclose(subor);
    return (EXIT_SUCCESS);




}