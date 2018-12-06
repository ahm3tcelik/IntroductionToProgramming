#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <unistd.h>
#include <ctype.h>

#define AUTHOR "amad;dhst"

struct hesap 
{
	char ad[32];
	char soyad[32];
	char banka_adi[16];
	int para;
	char iban[33];
	char sube[29];

};
const int komisyon = 5; // Para göndermede  %5 komisyon.
const int faiz_altin = 21; // Yillik %21 altýn faiz oraný.
const int faiz_gayrimenkul = 13; // Yillik %13 gayrimenkul faiz oraný.
const int faiz_faiz = 10; // Yillik %10 faiz.


int anasayfa(struct hesap index,struct hesap index2);

void yatirim_araclari(struct hesap index,struct hesap index2)
{
	printf("Lutfen size uygun olan yatirim aracini seciniz.\n\n");
	printf("1. Altin (Yillik %%%d Faiz Orani)\n",faiz_altin);
	printf("2. Gayrimenkul (Yillik %%%d Faiz Orani)\n",faiz_gayrimenkul);
	printf("3. Faiz (Yillik %%%d Faiz Orani)\n",faiz_faiz);
	int girilen,yil,getiri,yatirim_miktar;
	scanf("%d",&girilen);
	sleep(1);

	printf("Lutfen kac yil yatirim yapilacagini seciniz.");
	scanf("%d",&yil);
	printf("\nSimdi de ne kadar yatirim yapacaginizi seciniz.");
	scanf("%d",&yatirim_miktar);
	printf("\n%d TL'yi %d yil yatirim yaptiginiz durumda : \n",yatirim_miktar,yil);
	sleep(2);
	printf("*********************************************************\n\n");
	switch(girilen)
	//  Yatirim getirisi yuzdesi  formulu  : (Net Kar / Yatirim Maliyeti) x 100
	{
		case 1:
		{
			getiri = (yil*yatirim_miktar*faiz_altin/100)*100/20000;
			printf("Altinin size yatirim getirisi : %%%d\n",getiri);
			break;
		}
		case 2:
		{
			getiri = (yil*yatirim_miktar*faiz_gayrimenkul/100)*100/20000;
			printf("Gayrimenkulun size yatirim getirisi : %%%d\n",getiri);
			break;
		}
		case 3:
		{
			getiri = (yil*yatirim_miktar*faiz_faiz/100)*100/20000;
			printf("Altinin size yatirim getirisi : %%%d\n",getiri);
			break;
		}
		default: yatirim_araclari(index,index2);
	}
	printf("*********************************************************");
	sleep(2);
	printf("\n\nAna sayfaya donmek icin herhangi bir tusa basiniz\n\n");
	_getch();
	sleep(1);
	anasayfa(index,index2);
}

void paragonder(struct hesap index,struct hesap index2)
{
	printf("Lutfen gonderilecek paranin miktarini giriniz.\nDIKKAT! Para gonderme islemlerinde %%%d komisyon alinmaktadir.\nGuncel bakiye : [ %d TL ]\n",komisyon,index.para);
	int miktar;
	scanf("%d",&miktar);
	sleep(1);
	if(miktar <= index.para && miktar > 0)
	{
		int gonderilen;
		index.para -= miktar;
		gonderilen = miktar-miktar*komisyon/100;
		index2.para += gonderilen;
		printf("Hesabinizdan eksilen para miktari : [ %d TL ].\n",miktar);
		printf("Gonderilen net miktar : [ %d TL ]\n\n",gonderilen);
	}
	else
	{
		printf("Malesef gecerli bir miktar girmediniz veya yeterli miktarda paraniz yok.\n");
	}
	sleep(2);
	printf("Ana sayfaya donmek icin herhangi bir tusa basiniz\n\n");
	_getch();
	sleep(1);
	anasayfa(index,index2);
}

void parayatir(struct hesap index,struct hesap index2)
{
	printf("Hesaba aktarilacak parayi sayi olarak girip ATM'ye yatiriniz.\n");
	int miktar;
	scanf("%d",&miktar);
	printf("BEKLENIYOR!...\n");
	if(miktar > 0)
	{
		index.para += miktar;
		printf("[ %d TL ] Basariyla hesabiniza aktarilmistir.\nGuncel bakiye : [ %d TL ]\n\n",index.para);
	}
	else printf("Malesef gecerli bir miktar girmediniz veya ATM'ye para yatirmadiniz.\n");
	sleep(2);
	printf("Ana sayfaya donmek icin herhangi bir tusa basiniz\n\n");
	_getch();
	sleep(1);
	anasayfa(index,index2);
}
void paracek(struct hesap index,struct hesap index2)
{
	printf("Hesaptan cekilecek paranin miktarini sayi olarak giriniz.\nGuncel Bakiye : [ %d TL ]",index.para);
	int miktar;
	scanf("%d",&miktar);
	if(index.para < miktar && miktar <= 0)
	{
		printf("Malesef hesabinizda yeterli bakiye bulunmamaktadir.\n");
	}
	else
	{
		index.para -= miktar;
		printf("[%d TL] Basariyla cekildi.\nGuncel Bakiyeniz : %d\n\n",miktar,index.para);
	}
	sleep(2);
	printf("Ana sayfaya donmek icin herhangi bir tusa basiniz");
	_getch();
	sleep(1);
	anasayfa(index,index2);
}
void bakiyesorgula(struct hesap index,struct hesap index2)
{
	printf("************************************************************\n\n");
	printf("%s Bank Guncel Bakiyeniz : [ %d TL ]\n",index.banka_adi,index.para);
	printf("************************************************************\n\n");
	sleep(2);
	printf("Ana sayfaya donmek icin herhangi bir tusa basiniz\n\n");
	_getch();
	sleep(1);
	anasayfa(index,index2);

}
void hesapdetay(struct hesap index,struct hesap index2)
{
	printf("************************************************************\n\n");
	printf("%s Bank Hesap Detaylariniz :\n\n",index.banka_adi);
	printf("Ad - Soyad : %s %s\n",index.ad,index.soyad);
	printf("Subeniz : %s\n",index.sube);
	printf("IBAN Numaraniz : %s\n\n",index.iban);
	printf("************************************************************\n\n");
	sleep(2);
	printf("Ana sayfaya donmek icin herhangi bir tusa basiniz\n\n");
	_getch();
	sleep(1);
	anasayfa(index,index2);
}
int anasayfa(struct hesap index,struct hesap index2)
{
	printf("\n\n************************************************************\n");
	printf("%s Bank Kullanici Menusu\n\n",index.banka_adi);
	printf("1. Hesap Bilgilerimi Goster\n");
	printf("2. Bakiye Sorgulama\n");
	printf("3. Para Cekme\n");
	printf("4. Para Yatirma\n");
	printf("5. Para Gonderme (%%5 komisyon)\n");
	printf("6. Yatirim Getirisi Hesaplama\n");
	printf("7. Hesaptan Cikis Yap\n\n");
	printf("************************************************************\n");
	int secilen;
	scanf("%d",&secilen);
	switch(secilen)
	{
		case 1:
		{
			printf("\nYonlendiriliyorsunuz...\n\n");
			sleep(2);
			hesapdetay(index,index2);
			break;
		}
		case 2:
		{
			printf("\nYonlendiriliyorsunuz...\n\n");
			sleep(2);
			bakiyesorgula(index,index2);
			break;
		}
		case 3:
		{
			printf("\nYonlendiriliyorsunuz...\n\n");
			sleep(2);
			paracek(index,index2);
			break;
		}
		case 4:
		{
			printf("\nYonlendiriliyorsunuz...\n\n");
			sleep(2);
			parayatir(index,index2);
			break;
		}
		case 5:
		{
			printf("\nYonlendiriliyorsunuz...\n\n");
			sleep(2);
			paragonder(index,index2);
			break;
		}
		case 6:
		{
			printf("\nYonlendiriliyorsunuz...\n\n");
			sleep(2);
			yatirim_araclari(index,index2);
			break;	
		}
		case 7:
		{
			printf("Hesaptan cikis yapiliyor...\n");
			sleep(3);
			printf("Hesaptan Cikis Yapildi !");
			return 0;
		}
		default : anasayfa(index,index2);
	}	
}
int main()
{
	srand(time(NULL));
	hesap ben;
	hesap arkadas;

	printf("Lutfen adinizi soyadinizi giriniz : ");
	scanf("%s%s",&ben.ad,&ben.soyad);

	printf("Simdi de bankanizin adini giriniz (Ziraat,Vakif,Ak) : ");
	scanf("%s",&ben.banka_adi);

	printf("\n");
	sleep(1);
	printf("ONAYLANDI!\n");
	ben.para = rand()%8000;
	sprintf(ben.sube,"Incirli - Bakirkoy / Istanbul");
	// IBAN : 2 harf,24 rakam. Rasgele bir iban.
	sprintf(ben.iban,"TR %d %d %d %d %d %d",rand()%8999+1000,rand()%8999+1000,rand()%8999+1000,rand()%8999+1000,rand()%8999+1000,rand()%8999+1000); // Her biri 4 basamaklý rasgele sayi.
	sleep(1);
	
	printf("\n%s Bankasi Kullanici Menusune Hosgeldiniz.\n\n",ben.banka_adi);
	printf("Ana sayfaya yonlendiriliyorsunuz...\n\n");
	sleep(3);
	anasayfa(ben,arkadas);
}
