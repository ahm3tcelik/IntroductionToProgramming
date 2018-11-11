#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(NULL));
	printf("*******************************************\n");
	printf("*                                         *\n");
	printf("*             TAHMIN OYUNU                *\n");
	printf("*  Lutfen sayi araligini giriniz..        *\n");
	printf("* Örn: 20 = (0-20) arasını seçer.         *\n");
	printf("*                                         *\n");
	printf("*******************************************\n");      
	int aralik,hak=0,sayi,x=999,adim=0;
	scanf("%d",&aralik);
	int gecici=aralik;
	while(gecici > 0)
	{
		gecici/=2;
		hak++;
	}
	printf("%d Adet deneme hakkina sahipsiniz.\n",hak);         
	printf("*******************************************\n");
	printf("*                                         *\n");
	printf("*                TAHMIN OYUNU             *\n");
	printf("           Rasgele Sayi 0- %d Arasinda     \n",aralik);
	printf("*                                         *\n");
	printf("*******************************************\n");                
	sayi = rand()%aralik; // 0-aralik arasında rasgele bir sayı seç.
	while(!(x == sayi))
	{
		scanf("%d",&x);

		if(x == sayi)
		{
			printf("DOÐRU!!!\n");
			printf("Tebrikler %d Adimda dogru sonuca ulastiniz.",adim+1);
			break;
		}
		else if(x > sayi)
		{	
			printf("Daha KÜÇÜK\n"); 
			adim++;
		}
		else if(x < sayi)
		{
			printf("Daha BÜYÜK\n");
			adim++;
		}
		if(adim > hak)
		{
			printf("Malesef tum hakkiniz doldu. Dogru Sayi: { %d }",x);
			break;
		}	
	}
	printf("\n==================================\n");
	system("PAUSE");
	return EXIT_SUCCESS;
}