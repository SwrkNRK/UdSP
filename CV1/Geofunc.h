/*
 * Funkcie pre výpočet
 * Obvodu a Obsahu
 * Trojuholníka, Obdĺžnika, Kruhu
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#ifndef CV1_GEOFUNC_H
#define CV1_GEOFUNC_H
#define PI 3.14159265358979323846

// ******************** Structs ***********************

typedef struct triangle{    // trojuholník
    float a,b,c;
} Triangle;

typedef struct rectangle {
    float a,b;
} Rectangle;



/*
 * Function canConstructT checks if triangle can be formed and returns:
 * True if can
 * False if cant
 */
 bool canConstructT(float a, float b, float c){
    float pField[3] = {a+b, a+c, b+c};
    if (pField[0] > c &&
        pField[1] > b &&
        pField[2] > a ) {
        return true;
    }
    return false;
}
/*
 * Funkcia obvodT vypočíta obvod trojuholníka
 * V prípade ak sa trojuholník nedá skonštruovať
 * navrátová hodnota bude -1
 */
float obvodT(float a, float b, float c) {  // vypočíta a navráti obvod trojuholníka
    if(canConstructT(a,b,c)) {            // kontrola či sa dá trojuholník skonštruovať
        return (a + b + c);
    } else { return -1; }
}

float calcObsahT(float a, float b, float c){        // výpočet obsahu trojuholníka pomocou Herónovho vzorca
    float sp = obvodT(a,b,c) /2;                    // semi-perimeter of the triangle
    return sqrt(sp * (sp-a) * (sp-b) * (sp-c));     // obsah
}
/*
 * Funkcia obsahT vypočíta obsah trojuholníka
 * V prípade ak sa trojuholník nedá skonštruovať
 * navrátová hodnota bude -1
 */
float obsahT(float a, float b, float c){            // vypočíta a navráti obvod trojuholníka
    if(canConstructT(a,b,c)) {                      // kontrola či sa dá trojuholník skonštruovať
        float obsah = calcObsahT(a,b,c);
        return obsah;

    } else { return -1; }
}

float obvodO(float a, float b) {    // navráti obvod obdĺžnika
    return (2*a) + (2*b);
}

float obsahO(float a, float b) {    // navráti obsah obdĺžnika
    return a*b;
}

float obvodK(float d) {             // navráti obvod kruhu
    return (2 * PI * (d/2));
}

float obsahK(float d) {             // navráti obsah kruhu
    return (PI * pow((d/2),2));
}




#endif //CV1_GEOFUNC_H
