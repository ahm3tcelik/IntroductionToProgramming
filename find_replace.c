#include <stdio.h>
#include <string.h>

const char* degistir(char text[],int size,char find,char replace)
{
	for(int i=0;i<size;i++)
	{
		if(text[i] == find)
		{
			text[i] = replace;
		}
	}
	return text;
}
int main(int argc, char const *argv[])
{
	char yazi[32];
	printf("Lutfen harfleri degistirilecek yaziyi girin.\n");
	gets(yazi);
	char find,replace;
	printf("Lutfen degistirilecek harfleri girin. orn (ab) \n");

	scanf("%c%c",&find,&replace);

	printf("%s",degistir(yazi,strlen(yazi),find,replace));

	return 0;
}
