
#ifndef CV6_EVIDFUNCTIONS_H
#define CV6_EVIDFUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "EvidStructs.h"

#define BUF_SIZE 1000


bool areDatesEqual(const DATE date1, const DATE date2){
    return date1.day==date2.day &&
           date1.month==date2.month &&
           date1.year==date2.year;
}

bool areAuthorsEqual(const AUTHOR* author1, const AUTHOR* author2){
    return(strcmp(author1->name,author2->name)==0 &&
           strcmp(author1->surname,author2->surname)==0 &&
           areDatesEqual(author1->birthDate,author2->birthDate));


}
bool areBooksEqual(const BOOK* book1, const BOOK* book2){

    return(strcmp(book1->title,book2->title) == 0 &&
           book1->issueYear == book2->issueYear &&
           areAuthorsEqual(book1->author,book2->author));



}
AUTHOR* addAuthor(LIST* list, const AUTHOR* author){
    for(int i = 0; i < list->authorsCount; i++){
        if(areAuthorsEqual(author,&(list->authors[i]))){
            return &(list->authors[i]);
        }
    }
    if(list->authorsCount < LIST_SIZE){
        list->authors[list->authorsCount++] =*author;
        return &(list->authors[list->authorsCount-1]);
    }
    return NULL;
}
bool addBook(LIST* list, const BOOK* book){
    for(int i = 0; i < list->booksCount; i++){
        if(areBooksEqual(book,&(list->books[i]))){
            return true;
        }
    }
    AUTHOR* bookAuthor = addAuthor(list,book->author);
    if(bookAuthor != NULL){
        if(list->booksCount<LIST_SIZE){
            list->books[list->booksCount++]=*book;
            list->books[list->booksCount-1].author = bookAuthor;
            return true;
        }
    }
    return false;
}
printBook(const BOOK* book){
    printf("%s %s : %s %d\n",book->author->name,book->author->surname,book->title,book->issueYear);
}
void printBookList(const LIST* list){
    for(int i=0 ;i < list->booksCount; i++){
        printBook(&(list->books[i]));
    }
}

void importData(LIST* list,FILE* input){
    char buf[BUF_SIZE];
    int i = 0;
    while(fgets(buf,BUF_SIZE-1,input)!=NULL){
        AUTHOR author;
        BOOK book;

        char* pom1 = strchr(buf,';');
        strncpy(book.title,buf,pom1 - buf);
        book.title[pom1-buf] = '\0';


        char* pom2 = strchr(pom1 + 1,';');
        book.issueYear = atoi(pom1 + 1);
        printf("%s\n",pom2);
        char* pom3 = strchr(pom2 + 1,';');
        strncpy(author.surname,pom2 + 1,pom3 - pom2);
        author.surname[pom3 - pom2 -1] = '\0';

        char* pom4 = strchr(pom3 + 1,';');
        strncpy(author.name,pom3 + 1,pom4 - pom3);
        author.name[pom4 - pom3 -1] = '\0';

        char* pom5 = strchr(pom4 + 1,'/');
        author.birthDate.year = atoi(pom4 + 1);

        char* pom6 = strchr(pom5 + 1,'/');
        author.birthDate.month = atoi(pom5 + 1);

        char* pom7 = strchr(pom6 + 1,'\n');
        author.birthDate.day = atoi(pom6 + 1);

        book.author = &author;
        addBook(list,&book);


    }
}

void printBookBetweenDates(const LIST* list,const DATE dateOd, const DATE dateDo){
    for(int i = 0; i < list->booksCount; i++){
        if(list->books[i].author->birthDate.day  >= dateOd.day &&
           list->books[i].author->birthDate.month  >= dateOd.month &&
           list->books[i].author->birthDate.year  >= dateOd.year &&
           list->books[i].author->birthDate.day  < dateDo.day &&
           list->books[i].author->birthDate.month  < dateDo.month &&
           list->books[i].author->birthDate.year  < dateDo.year ){
            printf("%s %s %s\n",list->books[i].title, list->books[i].author->name, list->books[i].author->surname);
        }


    }
}

void saveToFile(const LIST* list, FILE* f) {
    fwrite(&(list->authorsCount), sizeof(list->authorsCount), 1, f);
    fwrite(&(list->booksCount), sizeof(list->booksCount), 1, f);
    fwrite(list->authors, sizeof(list->authors), 1, f);

    for(int i = 0; i < list->booksCount; i++){
        fwrite(&(list->books[i]), sizeof(list->books[i]), 1, f);
        AUTHOR* at = list->books[i].author;
        fwrite(at, sizeof(*at), 1, f);       // *at * dereferencujeme aby sme tam nemali adresu ale autorove atribúty
    }
}

void loadFromFile(LIST* list, FILE* f){
    fread(&(list->authorsCount),sizeof(list->authorsCount), 1, f);
    fread(&(list->booksCount), sizeof(list->booksCount), 1, f);
    fread(list->authors, sizeof(list->authors), 1, f);

    for(int i = 0; i < list->booksCount; i++){
        fread(&(list->books[i]), sizeof(list->books[i]), 1, f);
        AUTHOR at;
        fread(&at, sizeof(at), 1, f);
        AUTHOR* pAt = addAuthor(list, &at);
        list->books[i].author = pAt;
    }
}

void delaUthor(LIST* list){
    list->books[0].title[0] = '\0';
    list->books[0].author->name[0] = '\0';
    list->books[0].issueYear = '\0';
    list->books[0].author->surname[0] = '\0';
    list->books[0].author->birthDate.day = '\0';
    list->books[0].author->birthDate.month = '\0';
    list->books[0].author->birthDate.year = '\0';
    list->authorsCount--;
    list->booksCount--;
}


#endif //CV6_EVIDFUNCTIONS_H
