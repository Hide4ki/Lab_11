#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#define LEN 1000
#define SCOLOR 7

int main(void)
{
	HANDLE hStdout;
	FILE *fin;
	char line[LEN];
	char word[LEN];
	char *l;
	char *w;
	int k;
	int f;
	int pop_y;
	WORD Color;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	Color = BACKGROUND_INTENSITY | BACKGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED;
	if(!(fin = fopen("input.txt","r"))) 
		return 1;
	while(fgets(line,sizeof(line),fin))
	{
		l = line;
		w = word;
		f = 0;
		while(*l)
		{
			pop_y = 0;
			if(*l=='\"')
			{
				k = 0;
				while(l-k-1 >= line && *(l-k-1) == '\\') k++;
				if(!(k&1))
				{
					if(f)
					{
						*w++ = *l++;
						*w = '\0';
						SetConsoleTextAttribute(hStdout, Color );	
						printf("%s",word);				
						f = 0;
						pop_y = 1;
						w = word;
					}
					else
					{
						*w = '\0';
						SetConsoleTextAttribute(hStdout, SCOLOR );
						printf("%s",word);
						f = 1;
						w = word;
					}
				}
			}
			if(!pop_y)*w++ = *l++;
		}
		*w = '\0';
		SetConsoleTextAttribute(hStdout, SCOLOR );
		printf("%s",word);
	}
	getchar();
	return 0;
}
