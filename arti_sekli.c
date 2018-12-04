#include <stdio.h>

/*	
  .	. * . .  // 2 bo�luk 1 yildiz 2 bo�luk
	  * . .  // 2 bo�luk 1 yildiz 2 bo�luk
  * * * * *  // 5 yildiz
  . . * . .  // 2 bo�luk 1 yildiz 2 bo�luk
  . . *	. .	 // 2 bo�luk 1 yildiz 2 bo�luk				
*/
int artibas(int size)
{
	int yildiz,bosluk;
	for(int i=1;i<=size;i++)
	{
		if(i == size/2+1) // Ortadaki sat�r sadece y�ld�zdan olu�uyor. Ortadaki sat�r� bulmak i�in (5/2+1 = 3)
		{
			yildiz = size;  
		}
		else
			yildiz = 1;
		/*
		Yukardaki �ekle bakarak :
		bo�luklar ve y�ld�zlar�n toplam� size'yi veriyor.
		toplam bo�luk say�s� = x, toplam yildiz say�s� = y olsun.
		2x + y = size
		(size - y)/2 = x olur. // Bu da bo�luk say�s�n� verir.
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