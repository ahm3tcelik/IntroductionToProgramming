/* %d sayisindan %d sayisina gerekli matematiksel islemleri yaparak ulasmaya calisiniz.\nToplama (+) ve Cikarma (-) islemi icin %d hakkiniz vardir! */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(NULL));
	int baslangic = rand();
	int son = rand();
	char islem;
	int adim=0,hak=3;
	printf("%d sayisindan %d sayisina gerekli matematiksel islemleri yaparak ulasmaya calisiniz.\nToplama (+) ve Cikarma (-) islemi icin %d hakkiniz vardir!\n",baslangic,son,hak);

	islem_menu:
	{
		int nev,gereken=son;
		printf("Sayi Giriniz : ");
		scanf("%d",&nev);
		if(nev == 0)
		{
			printf("Lutfen 0'dan farkli bir sayi giriniz.\n");
			goto islem_menu;
		}
		printf("\nIslem Seciniz : \n");
		printf("1. '+'\n2. '-'\n3. 'X'\n4. '/'\n");
		scanf("%d",&islem);
		switch(islem)
		{
			case 1: 
			{
				if(hak>0)
				{
					baslangic+=nev;
					adim++;
					hak--;
					break;
				}
				else
				{
					printf("Malesef toplama-cikarma islemi yapma hakkiniz kalmadi.\nCarpma veya Bolme kullanmayi deneyiniz.\n");
					goto islem_menu;
					break;
				}

			}
			case 2: 
			{
				if(hak>0)
				{
					baslangic-=nev;
					adim++;
					hak--;
					break;
				}
				else
				{
					printf("Malesef toplama-cikarma islemi yapma hakkiniz kalmadi.\nCarpma veya Bolme kullanmayi deneyiniz.\n");
					printf("Suanki Sayi : %d, Ulasmaniz gereken : %d\n",baslangic,son);
					goto islem_menu;
					break;
				}
			}
			case 3: baslangic= baslangic*nev;adim++;break;
			case 4: baslangic/=nev;adim++;break;
			default: goto islem_menu;break;
		}
	}
	if(baslangic == son)		
	{
		printf("\nTEBRIKLER!!!!!!!!!\n");
		printf("Dogru islemleri yaparak sonuca [ %d ] adimda ulastiniz!",adim);
		printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		system("PAUSE");
		return EXIT_SUCCESS;
	}
	else 
	{
		printf("Suanki Sayi : %d, Ulasmaniz gereken : %d\n",baslangic,son);
		goto islem_menu;
	}	
}