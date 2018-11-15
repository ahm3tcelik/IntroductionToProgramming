#include <stdio.h>
#include <stdlib.h>

/* çarpa iþlemini kullanmadan iki sayýnýn çarpýmýný bulan c programý.

6 X 3 = (6+6)
		2tane
*/
int main()
{
	int x,y,sonuc=0;
	printf("Carpilacak iki sayi giriniz.");
	scanf("%d%d",&x,&y);
	for(int i=1;i<=y;i++)
	{
		sonuc = sonuc+x;
	}
	printf("Carpma isleminin sonucu : %d",sonuc);

	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	system("PAUSE");
	return EXIT_SUCCESS;
}
