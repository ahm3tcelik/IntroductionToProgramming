#include <stdio.h>

/*	
  .	. * . .  // 2 boþluk 1 yildiz 2 boþluk
	  * . .  // 2 boþluk 1 yildiz 2 boþluk
  * * * * *  // 5 yildiz
  . . * . .  // 2 boþluk 1 yildiz 2 boþluk
  . . *	. .	 // 2 boþluk 1 yildiz 2 boþluk				
*/
int artibas(int size)
{
	int yildiz,bosluk;
	for(int i=1;i<=size;i++)
	{
		if(i == size/2+1) // Ortadaki satýr sadece yýldýzdan oluþuyor. Ortadaki satýrý bulmak için (5/2+1 = 3)
		{
			yildiz = size;  
		}
		else
			yildiz = 1;
		/*
		Yukardaki þekle bakarak :
		boþluklar ve yýldýzlarýn toplamý size'yi veriyor.
		toplam boþluk sayýsý = x, toplam yildiz sayýsý = y olsun.
		2x + y = size
		(size - y)/2 = x olur. // Bu da boþluk sayýsýný verir.
		*/
		bosluk = (size-yildiz)/2;

		for(int j=1;j<=bosluk;j++)
			printf("  ");
		for(int k=1;k<=yildiz;k++)
			printf("* ");
		printf("\n");
	}
}
int main()
{
	int size2;
	printf("+'nin buyuklugunu giriniz.\n");
	scanf("%d",&size2);
	artibas(size2);
}