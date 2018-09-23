#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#define LEN 1000

int main(void)
{
	HANDLE hStdout;
	FILE *fin;
	char line[LEN];
	char word[LEN];
	char *l;
	char *w;
	int f;
	char *pt;
	WORD Color;
	hStdout = GetStdHandle (STD_OUTPUT_HANDLE);
	Color = BACKGROUND_INTENSITY | BACKGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED;
	if(!(fin = fopen("input.txt","r")))
		return 1;
	while(fgets(line,sizeof(line),fin))
	{
		l = line;
		w = word;
		*w = '\0';
		f = 0;
		while(*l)
		{
			if(*l=='\"' && ((l-1<line)||*(l-1)!='\\'))
			{
				if(f)
				{
					*w++ = *l++;
					*w = '\0';
					SetConsoleTextAttribute (hStdout, Color );	
					printf("%s",word);				
					f = 0;
					w = word;
					*w = '\0';
				}
				else
				{
					*w = '\0';
					SetConsoleTextAttribute (hStdout, 7 );
					printf("%s",word);
					f = 1;
					w = word;
					*w = '\0';
				}
			}
			*w++ = *l++;
		}
		*w = '\0';
		SetConsoleTextAttribute (hStdout, 7 );
		printf("%s",word);
	}
	getchar();
	return 0;
}
