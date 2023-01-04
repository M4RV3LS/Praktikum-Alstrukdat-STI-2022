#include <stdio.h>
#include "mesinkata.h"
#include "mesinkarakterv2.h"

int main()
{
	int geser;
	START();
	ADVWORD();
    // while (currentChar == BLANK)
    // {
	// 	printf(" ");
    //     ADV();
    // }
    // if (currentChar == MARK)
    // {
    //     EndWord = true;
    // }
    // else
    // {
    //     EndWord = false;
    //     CopyWord();
    // }
	if (!isEndWord())
	{
		geser = currentWord.Length;
		while(!isEndWord())
		{
			for (int i = 0 ; i < currentWord.Length ; i++)
			{
				currentWord.TabWord[i] += geser % 26;
				if (currentWord.TabWord[i] > 90)
				{
					currentWord.TabWord[i] -= 26;
					printf("%c", currentWord.TabWord[i]);
				}
				else
				{
					printf("%c", currentWord.TabWord[i]);
				}
			}
			ADVWORD();
			if (!isEndWord())
			{
				printf(" ");
			}
		}
	}
	printf(".\n");
	return 0;	
}
