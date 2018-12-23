#include <stdio.h>

int sec()
{
	printf("Lutfen cizilecek seklin uzunlugunu giriniz : \n");
	int size; scanf("%d",&size);
	return size;
}
void ucgen(int size)
{
	printf("\n");

	for(int i=1;i<=size;i++)
	{
		for(int k=1;k<=i;k++)
			printf("* ");
		printf("\n");
	}
}
void ters_ucgen(int size)
{
	printf("\n");
	int yildiz,bosluk;
	bosluk = size-1;
	yildiz = 1;

	for(int i=1;i<=size;i++)
	{
		for(int k=1;k<=bosluk;k++)
			printf("  ");
		for(int l=1;l<=yildiz;l++)
			printf("* ");

		printf("\n");
		bosluk--;
		yildiz++;
	}
}
void eskenar_ucgen(int size)
{
	printf("\n");
	int yildiz,bosluk;
	bosluk = size-1;
	yildiz = 1;
	for(int i=1;i<=size;i++)
	{
		for(int k=1;k<=bosluk;k++)
			printf(" ");
		for(int l=1;l<=yildiz;l++)
			printf("* ");

		yildiz++;
		bosluk--;
		printf("\n");
	}
}
void eskenar_dortgen(int size)
{
	printf("\n");
	int yildiz,bosluk;
	bosluk = size-1;
	yildiz = 1; 
	for(int i=1;i<=size;i++)
	{
		for(int j=1;j<=bosluk;j++)
			printf(" ");
		for(int k=1;k<=yildiz;k++)
			printf("* ");

		if(i >= size/2)
		{
			yildiz--;
			bosluk++;
		}
		else
		{
			yildiz++;
			bosluk--;
		}
		printf("\n");
	}

}
void piramit(int size)
{
	printf("\n");
	int yildiz,bosluk;
	bosluk = size-1;
	yildiz = 1;
	for(int i=1;i<=size;i++)
	{
	
		for(int k=1;k<=bosluk;k++)
			printf("  ");
		for(int l=1;l<=yildiz;l++)
			printf("* ");

		yildiz += 2;
		bosluk--;

		printf("\n");
	}
}
void arti(int size)
{
    printf("\n");
	int yildiz,bosluk;

	yildiz = 1;
	bosluk = (size-yildiz)/2;
	for(int i=1;i<=size;i++)
	{
		for(int k=1;k<=bosluk;k++)
			printf("  ");
		for(int l=1;l<=yildiz;l++)
			printf("* ");
		
		printf("\n");
		if(i == size/2)
		{
			yildiz = size;
			bosluk = 0;
		}
		else
		{
			yildiz = 1;
			bosluk = (size-yildiz)/2;
		}
	}
}
int main()
{
	int sekil;
	printf("Bastirmak istediginiz sekli seciniz : \n\n");
	printf("1. Ucgen\n2. Ters Ucgen\n3. Eskenar Ucgen\n4. Eskenar Dortgen\n5. Piramit\n6. Arti Isareti\n");
	scanf("%d",&sekil);
	switch(sekil)
	{
		case 1:
		{
			ucgen(sec());break;
		}
		case 2:
		{
			ters_ucgen(sec());break;
		}
		case 3:
		{
			eskenar_ucgen(sec());break;
		}
		case 4:
		{
			eskenar_dortgen(sec());break;
		}
		case 5:
		{
			piramit(sec());break;
		}
		case 6:
		{
			arti(sec());break;
		}
		default:  printf("ERR!\n");
	}
}
