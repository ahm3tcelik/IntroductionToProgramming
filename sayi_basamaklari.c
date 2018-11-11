#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(NULL)); // Program her baþlatýldýðýnda farklý bir sayý seçmesini saðlar.
	int sayi=rand() + 1; // 1 - ... arasý rasgele bir sayý seçer.
	int temp=sayi, toplam=0, basamak_sayisi=0;
	while(temp > 0)
	{
		toplam+= temp%10;
		temp/=10;
		basamak_sayisi++;
	}
	printf("Rasgele secilen sayi  : %d\n",sayi);
	printf("Basamak sayisi  : %d\n",basamak_sayisi);
	printf("Basamaklari toplami : %d\n",toplam);
	
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	system("PAUSE");
	return EXIT_SUCCESS;
}