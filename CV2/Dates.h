

#ifndef CV2_DATES_H
#define CV2_DATES_H

#include <stdio.h>
#include <stdbool.h>


enum day{pondelok = 1, utorok, streda, stvrtok, piatok, sobota, nedela};
enum month{januar = 1, februar, marec, april, maj, jun, jul, august, september, oktober, november, december};

typedef struct date{
    int den ;
    enum month mesiac;
    int rok;

}DATE;

const char* getDayName(enum day d){
    switch (d) {
        case 1:
            return "pondelok";
        case 2:
            return "utorok";
        case 3:
            return "streda";
        case 4:
            return "stvrtok";
        case 5:
            return "piatok";
        case 6:
            return "sobota";
        case 7:
            return "nedela";
    }
}

const char* getMonthName(enum month d){
    switch (d) {
        case 1:
            return "januar";
        case 2:
            return "februar";
        case 3:
            return "marec";
        case 4:
            return "april";
        case 5:
            return "maj";
        case 6:
            return "jun";
        case 7:
            return "jul";
        case 8:
            return "august";
        case 9:
            return "september";
        case 10:
            return "oktober";
        case 11:
            return "november";
        case 12:
            return "december";
    }
}



bool isLeapY(int rok){
    if(rok % 400 == 0 && rok % 100 == 0) {
        return true;
} else if (rok % 4 == 0 && rok % 100 != 0) {
        return true;
    }
    return false;
}

int whatDay(DATE d){
    switch (d.mesiac) {
        case 1:
            return 31;
        case 2:
            if(isLeapY(d.rok)){
                return 29;
            }   else { return 28;}
        case 3:
            return 31;
        case 4:
            return 30;
        case 5:
            return 31;
        case 6:
            return 30;
        case 7:
            return 31;
        case 8:
            return 31;
        case 9:
            return 30;
        case 10:
            return 31;
        case 11:
            return 30;
        case 12:
            return 31;
        default:
            return -1;
    }
}

bool isDValid(DATE d){
    if(d.den <= 31 && d.den > 0 &&
    d.mesiac <= 12 && d.mesiac > 0 &&
    d.rok > 0 && d.rok < 9999) {
        if(d.den <= whatDay(d)) {
            return true;
        }
    }
    return false;
}

int daysFromStartOfY(DATE d){
    int sum = 0;
    int m = d.mesiac;
    for (int i = 1; i < m; ++i) {
        d.mesiac = i;
        sum += whatDay(d);
    }
    sum += d.den;
    return sum;
}

int daysToEndOfY(DATE d){
    if(isLeapY(d.rok)){
        return 366 - daysFromStartOfY(d);
    } else { return 365 - daysFromStartOfY(d); }
}

bool isDatesEq(DATE x, DATE y){
    if(x.den == y.den && x.mesiac == y.mesiac && x.rok == y.rok) {
        return true;
    }
    return false;
}

int dayOfWeek(DATE d){
    DATE pp = {1,1,2000};
    int dc = 6;
    while(!isDatesEq(d,pp)) {
        pp.den++;
        dc++;
        if(daysToEndOfY(pp) == -1) { pp.rok++; pp.mesiac = 1; pp.den = 1; }
        if(whatDay(pp) - pp.den == -1) {pp.den = 1; pp.mesiac++;}
        if(dc > 7) { dc = 1; }
    }
    return dc;
}

int nextDay(DATE d){

    d.den++;
    if(daysToEndOfY(d) == -1) { d.rok++; d.mesiac = 1; d.den = 1; }
    if(whatDay(d) - d.den == -1) {d.den = 1; d.mesiac++;}
    return dayOfWeek(d);
}

int previousDay(DATE d){
    d.den--;
    if(daysToEndOfY(d) == 365) { d.rok--; d.mesiac = 12; d.den = 31; }
    if(whatDay(d) - d.den == -1) {d.den = 1; d.mesiac++;}
    return dayOfWeek(d);
}

#endif //CV2_DATES_H
