#include <stdio.h>

/* KLU Yazılım Mühendisliği 1.Sınıf 1.Dönem (2018) Ödevi

4x4’lük iki tamsayı matrisin elemanları, program çalışmaya başladıktan sonra kullanıcıdan girdi olarak
alınacaktır.
1. Matrisler içinde eş konumda bulunan elemanlardan birbirleriyle aynı olanlar, ayrı bir dizi içinde
kaydedilecektir. (Örneğin, her iki matrisin de (2,1) konumunda bulunan elemanları 4 ise bu
eleman oluşturulan diziye eklenecektir.)
2. Ortak elemanları barındıran dizi büyükten küçüğe doğru sıralanıp ekranda gösterilecektir.
3. Matrislerin elemanlarının ortalamaları, her bir matris için ayrı ayrı hesaplanıp, ortak elemanların
bulunduğu dizinin ortalaması ile karşılaştırılacak ve büyük, küçük ya da eşit olma durumları
ekranda gösterilecektir.
4. Ortak elemanların olduğu dizide asal sayılar varsa bunlar bulunarak ekranda gösterilecektir. 
*/

int matris_1[4][4] =
{
	{28,9,16,15},
	{18,2,8,44},
	{5,29,2,5},
	{-5,7,0,43}
};
int matris_2[4][4] =
{
	{4,45,10,24},
	{18,29,15,7},
	{11,17,2,5},
	{-5,7,0,3}
};
int esitler[16],uzunluk=0;
void scan_matris_1(void)
{
	printf("Lutfen 1. matrisin degerlerini giriniz :\n");
	for(int str=0;str<4;str++)
	{
		for(int stn=0;stn<4;stn++)
		{
			int temp;
			scanf("%d",&temp);
			matris_1[str][stn] = temp; 
		}
	}
}
void scan_matris_2(void)
{
	printf("Lutfen 2. matrisin degerlerini giriniz :\n");
	for(int str=0;str<4;str++)
	{
		for(int stn=0;stn<4;stn++)
		{
			int temp;
			scanf("%d",&temp);
			matris_2[str][stn] = temp; 
		}
	}
}
void check_same(int matris_1[4][4],int matris_2[4][4])
{
	for(int str=0;str<4;str++)
	{
		for(int stn=0;stn<4;stn++)
		{
			if(matris_1[str][stn] == matris_2[str][stn])
			{
				esitler[uzunluk] = matris_1[str][stn];
				uzunluk++;
			}
		}
	}

}
void sort_esitler(int esitler[],int uzunluk) // selection sort
{
	int maks;
	for(int i=0;i<uzunluk;i++)
	{
		maks = i; // i'ninci degeri sec.
		for(int j=i+1;j<uzunluk;j++)
		{
			if(esitler[j] > esitler[maks]) // j indisinin değeri minimum indisindeki değerden küçükse  
				maks = j;
		} 
		//  swap islemi
		int temp = esitler[i];
		esitler[i] = esitler[maks];
		esitler[maks] = temp;
	}
	printf("Iki matrisin ayni konumundaki ortak elemanlari :%s",uzunluk==0?" Maalesef ortak bir eleman bulunmamaktadir.":"");
	for(int i=0;i<uzunluk;i++)
		printf("%d ",esitler[i]);
	printf("\n\n");
}
int matris_ort_hesapla(int matris[4][4])
{
	int plus=0;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
			plus += matris[i][j];
	}
	return plus/16;
}
int ort_hesapla(int esitler[],int uzunluk)
{
	int plus=0;
	for(int i=0;i<uzunluk;i++)
		plus+=esitler[i];
	return plus/uzunluk;
}
void asalyazdir(int esitler[],int uzunluk)
{
	printf("\nAsal Sayilar :");
	int asal=0,asalvar=0;
	for(int i=0;i<uzunluk;i++)
	{
		for(int j=esitler[i]/2;j>=2;j--)
		{
			if(esitler[i]%j == 0)
			{
				asal = 0;
				break;
			}
			else asal=1;
		}
		if((asal || esitler[i] == 2) && esitler[i] > 1 )
		{
			asalvar = 1;
			printf(" %d",esitler[i]);
		}
	}
	printf("%s",!asalvar?" Malesef asal sayi bulunmamaktadir.":".",asal);
}
int main()
{
	int matris1_ort,matris2_ort,esitler_ort;
	//scan_matris_1(); // 1. matrisi kullanicidan al.
	//scan_matris_2(); // 2. matrisi kullanicidan al.
	check_same(matris_1,matris_2); // İki matrisin aynı konumundaki ortak elemanlarini esitler dizisine ekle.
	sort_esitler(esitler,uzunluk);  // esitler dizisini sırala. (diziadi,boyutu) (Selection Sort)
	matris1_ort = matris_ort_hesapla(matris_1);
	matris2_ort = matris_ort_hesapla(matris_2);
	esitler_ort = uzunluk<1 ?0:ort_hesapla(esitler,uzunluk); // Ortak eleman bulmazsa programin cokmesini engelleme.

	printf("1. Matrisin elemanlari ortalamasi, ortak elemanlarin bulundugu dizinin ortalamasi");

	if(matris1_ort == esitler_ort)
		printf(" ile esittir. (%d & %d)\n",matris1_ort,esitler_ort);
	else
		printf("%s (%d & %d)\n",matris1_ort>esitler_ort?"ndan buyuktur.":"ndan kucuktur.",matris1_ort,esitler_ort);

	printf("2. Matrisin elemanlari ortalamasi, ortak elemanlarin bulundugu dizinin ortalamasi");

	if(matris2_ort == esitler_ort)
		printf(" ile esittir. (%d & %d)\n",matris2_ort,esitler_ort);
	else
		printf("%s (%d & %d)\n",matris2_ort>esitler_ort?"ndan buyuktur.":"ndan kucuktur.",matris2_ort,esitler_ort);

	asalyazdir(esitler,uzunluk);
}
