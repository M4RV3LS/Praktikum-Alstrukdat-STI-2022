#include <stdio.h>
#include "jumlahkonsonanvokal.h"

int isAlphabet (char huruf) {
	char Alphabet[10] = {'a','i','u','e','o','A','I','U','E','O'};
	int Benar = 0;
	int i;
	for (i=0; i<10; i++) {
		if (huruf == Alphabet[i]) 
		{
			Benar = 1;
			}
	}
	return Benar;
}

int isVowel (char huruf) 
{
	int Benar = 0;
	if (isAlphabet(huruf) == 1) 
	{
		Benar = 0;
	}
	else 
	{
		if ((huruf >=66 && huruf <= 90) || (huruf >= 98 && huruf <= 122)) 
		{
			Benar = 1;	
		}
	}
	return Benar;
}

void jumlahKonsonanVokal(char * kalimat, int *konsonan, int *vokal)
{
	int indeks = 0;
	
	while ( *(kalimat+indeks) != '\0') 
	{
			if (isAlphabet(*(kalimat + indeks)) == 1) {
				*vokal += 1;
			}
			else if (isVowel(*(kalimat + indeks)) == 1)
			{
				*konsonan += 1;
			}
			indeks += 1;
			
	}
}

