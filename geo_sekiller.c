#include <stdio.h>

int sec()
{
	printf("Lutfen cizilecek seklin uzunlugunu giriniz : \n");
	int size; scanf("%d",&size);
	return size;
}
void ucgen(int size)
{
	/*     UCGEN

		* 		1.satir 1y
		* *		2.satir 2y
		* * * 	3.satir 3y */

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
	/* Ters Üçgen 

		*  1.satir 2b 1y
	  * *  2.satir 1b 2y
	* * *  3.satir 0b 3y  */
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
	/*   ESKENAR UCGEN 

		*    1.satır 2b 1y 
	   * *   2.satır 1b 2y
	  * * *  3.satır 0b 3y
*/
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
	/* ESKENAR DORTGEN
		
		*   2b 1y
	   * * 	1b 2y
	  * * * 0b 3y
	   * *  1b 2y
	    *   2b 3y
*/
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
		/*	 PIRAMIT 

		  	 	*      	1.satır 3b 1y
			  * * *	   	2.satır 2b 3y
			* * * * *  	3.satır 1b 5y
		  * * * * * * * 4.satır 0b 6y 	*/

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
/*	 ARTI ISARETI
		
		*	   2b 1y 2b  (size) 5 = 4b+y -> 2b = (5-y)/2	    
		*	   2b 1y 2b
    * * * * *  0b 5y 0b
		*	   2b 1y 2b
		*	   2b 1y 2b
*/
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