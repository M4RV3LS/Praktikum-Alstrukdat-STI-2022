#include <stdio.h>
#include "anagramalstrukdat.h"

/*  Menerima sebuah parameter string bertipe string
    Mengirimkan panjang sebuah string */
int stringLength (char* string){
    int count = 0;
    while(string[count] != '\0'){
        count ++ ;
    }
    return count;
    
}

/*  Menerima sebuah paramater command bertipe string
    Mengirimkan kata yang elemen of arraynya berasal dari command */
Word toKata(char* command){
    Word Output ;
    for (int i = 0 ; i < stringLength(command) ; i++){
        Output.TabWord[i] = command[i];
    }
    Output.Length = stringLength(command);
    return Output;
}

/*  Menerima dua buah parameter yaitu string1 dan string2
    Mengembalikan true apabila string2 merupakan anagram dari string1
    Mengembalikan false apabila string2 bukan merupakan anagram dari string1
    String dianggap anagram apabila disusun dari huruf yang tepat sama */
boolean isAnagram(Word string1, Word string2)
{
	if (string1.Length != string2.Length)
	{
		return 0;
	}
	int num1[26] = {0}, num2[26] = {0}, i = 0;
	while (string1.TabWord[i] != '\0')
	{
		num1[string1.TabWord[i] - 'a']++;
		i++;
	}
	i = 0;
	while (string2.TabWord[i] != '\0')
	{
		num2[string2.TabWord[i] - 'a']++;
		i++;
	}
	for (i = 0 ; i < 26; i++)
	{
		if (num1[i] != num2[i])
		{
			return 0;
		}
	}
	return 1;
}

/*  Mengembalikan jumlah frekuensi kemunculan anagram alstrukdat 
    pada argumen frek */
void anagramalstrukdat(int* frek)
{
	int count = 0;
	Word alstrukdat = toKata("alstrukdat");

	STARTWORD();
	while (!isEndWord())
	{
		if (isAnagram(alstrukdat , currentWord))
		{
			count += 1;
		}
		ADVWORD();
	}
	*frek = count;
}



