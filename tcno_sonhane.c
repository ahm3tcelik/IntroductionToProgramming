#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int basamaktopla(int sayi)
{
	int t_basamak=0;
	while(sayi > 0)
	{
		t_basamak += sayi%10;
		sayi/=10;
	}
	return t_basamak;
}
int main()
{
	/*  Sistem 10 haneli her sayiyi hafizada tutamadigi icin sayiyi 2 farkli stringte tuttuk.
		array to int islemiyle tekrar sayiya cevirip gerekli matematiksel islemleri yaptık.
	*/
	char tc_num[10];
	char part1[10], part2[]="0";
	int toplam=0;
	x:
	{
		printf("Lutfen T.C Kimlik numaranizin ilk 10 hanesini giriniz.\n");
		gets(tc_num);
		if(strlen(tc_num) < 10)
		{
			printf("Maalesef eksik bir numara girdiniz.\n");
			goto x;
		}
		else if(strlen(tc_num) > 10)
		{
			printf("Maalesef fazla bir numara girdiniz.\n");
			goto x;
		}
		else
		{
			strncpy(part1,tc_num,9); // tc numarasının ilk 9 hanesini part1'e ata.
			part2[0] = tc_num[9]; // tc numarasının son hanesini part2'ye ata.
			
			toplam += basamaktopla(atoi(part2));  //  her basamagindaki sayilari topla
			toplam += basamaktopla(atoi(part1));  
		}
		printf("\n\n/****************************************\n");
		printf("T.C Kimlik numaranizin son hanesi : %d\n",toplam%10);
		printf("*****************************************/\n");
	}
}
