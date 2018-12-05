#include <stdio.h>

/*

. . * . .  // 2 boşluk 1 yıldız 2 boşluk            *
. . * . .  // 2 boşluk 1 yıldız 2 boşluk	    *									
* * * * *  // 0 yıldız 5 boşluk 0 boşluk 	* * * * *									
. . * . .  // 2 boşluk 1 yıldız 2 boşluk	    *									
. . * .  . // 2 boşluk 1 yıldız 2 boşluk	    *								


*/
int artibas(int size)
{
	int yildiz,bosluk;
	for(int i=1;i<=size;i++)
	{
		if(i == size/2+1) // Ortadaki satır sadece yildizdan oluşuyor. Ortadaki satırı bulmak için (5/2+1 = 3)
		{
			yildiz = size;  
		}
		else
			yildiz = 1;
		/*
		Yukarıdaki şekle bakarak :
		boşluk ve yıldızların toplamı size'yi veriyor.
		toplam boşluk sayısı = x, toplam yıldız sayısı = y olsun.
		2x + y = size
		(size - y)/2 = x olur. // Bu da bu da boşluk sayısını verir.
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
	printf("+'nin buyuklugunu giriniz.\n",scanf("%d",&size2));
	artibas(size2);
}
