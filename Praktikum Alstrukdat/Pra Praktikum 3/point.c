#include <stdio.h>
#include "point.h"
#include <math.h>

POINT MakePOINT (float X, float Y){
    POINT p ;
    Absis(p) = X ;
    Ordinat(p) = Y;
    return p;
}

void BacaPOINT (POINT * P){
    float x, y;
    scanf("%f %f", &x, &y);
    *P = MakePOINT(x, y);
}

void TulisPOINT (POINT P){
    printf("(%.2f,%.2f)", Absis(P), Ordinat(P) );
}

boolean EQ (POINT P1, POINT P2) {
    return ((Absis(P1) == Absis(P2)) && (Ordinat(P1) == Ordinat(P2)));
}

boolean NEQ (POINT P1, POINT P2) {
    return ((Absis(P1) != Absis(P2)) || (Ordinat(P1) != Ordinat(P2)));
}

boolean IsOrigin (POINT P) {
    return ((Absis(P) == 0) && (Ordinat(P) == 0));
}

boolean IsOnSbX (POINT P){
    return (Ordinat(P) == 0);
}

boolean IsOnSbY (POINT P){
    return (Absis(P) == 0);
}

int Kuadran (POINT P) {
    if (Absis(P) > 0)
	{
		if (Ordinat(P) > 0)
		{
			return 1;
		}
		else /* (Ordinat(P) < 0) */
		{
			return 4;
		}
	}
	else  /* (Absis(P) < 0) */
	{
		if (Ordinat(P) > 0)
		{
			return 2;
		}
		else /* (Ordinat(P) < 0) */
		{
			return 3;
		}
	}
}

POINT PlusDelta (POINT P, float deltaX, float deltaY){
    Absis(P)=Absis(P)+deltaX;
    Ordinat(P)=Ordinat(P)+deltaY;
    return P;
}

void Geser (POINT *P, float deltaX, float deltaY){
    Absis(*P)=Absis(*P)+deltaX;
    Ordinat(*P)=Ordinat(*P)+deltaY;
}

float Jarak0 (POINT P){
    return sqrt((Absis(P)*Absis(P)) + (Ordinat(P)*Ordinat(P)));
}

float Panjang (POINT P1, POINT P2){
    float jarakX, jarakY ;
    jarakX = Absis(P1) - Absis(P2);
    jarakY = Ordinat(P1) - Ordinat(P2);
    return sqrt((jarakX*jarakX+jarakY*jarakY));
}



