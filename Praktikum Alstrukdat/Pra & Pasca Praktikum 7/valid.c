#include <stdio.h>
#include "valid.h"

Stack validParantheses(char* input, int length)
{
/* Proses: Memasukkan parantheses (dari input) yang valid secara berurutan ke dalam Stack */
/* I.S. input adalah string, yang berisi parantheses baik secara acak maupun teratur, dan panjang dari string */
/* Contoh input dan hasil parantheses yang valid:
    1. () 2 -> ()
    2. []) 3 -> []
    3. {[} 3 -> --kosong--
    4. ()[]{} 6 -> ()[]{}
*/
	char before , cc;
	Stack S;
	CreateEmpty(&S);
	before = *input;
	for (int i = 1 ; i < length; i++)
	{
		cc = *(input+i);
		if ((before == '(') && (cc == ')'))
		{
			//printf("%c%c",before,cc);
			Push(&S,before);
			Push(&S,cc);
		}
		else if ((before == '{') && (cc == '}'))
		{
			//printf("%c%c",before,cc);
			Push(&S,before);
			Push(&S,cc);
		}
		else if ((before == '[') && (cc == ']'))
		{
			//printf("%c%c",before,cc);
			Push(&S,before);
			Push(&S,cc);
		}
		before = cc;
	}
	return S;
	
}
