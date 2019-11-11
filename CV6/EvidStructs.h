
#ifndef CV6_EVIDSTRUCTS_H
#define CV6_EVIDSTRUCTS_H

#include <stdio.h>
#include <stdlib.h>

#define STRING_SIZE 30
#define LIST_SIZE 10

typedef struct date{
    int day;
    int month;
    int year;
} DATE;
typedef struct author{
    char name[STRING_SIZE];
    char surname[STRING_SIZE];
    struct date birthDate;
}AUTHOR;

typedef struct book{
    char title[STRING_SIZE];
    AUTHOR* author;
    int issueYear;
}BOOK;

typedef struct list{
    AUTHOR authors[LIST_SIZE];
    int authorsCount;
    BOOK books[LIST_SIZE];
    int booksCount;
}LIST;




#endif //CV6_EVIDSTRUCTS_H
