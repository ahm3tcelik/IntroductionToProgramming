/* Girilen sayýnýn asal oluo olmadýðýný kontrol eden kod. */ 

#include <stdio.h>
#include <stdlib.h>

int asal(int);
main()
{
	int x;
	printf("Lutfen bir sayi giriiniz.");	
	scanf("%d",&x);
	asal(x);
}
int asal(int x)
{
	int asal=true;
	for(int i=x-1;i>1;i--)
	{
		if(x%i == 0) 
		{
			asal=false;
			break;
		}
	}
	if(asal || x == 2) 
	{
		printf("Girilen sayi asaldir.");
	}
	else if(!asal) printf("Girilen sayi asal degildir.");

	printf("\n==================================\n");
	system("PAUSE");
	return EXIT_SUCCESS;
}