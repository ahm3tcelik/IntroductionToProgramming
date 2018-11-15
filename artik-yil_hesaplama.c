#include <stdio.h>
#include <stdlib.h>

int main()
{
	int x;
	printf("Artik yil olup olmadigi kontrol edilecek yili giriniz.");
	scanf("%d",&x);
	if((x%4 == 0 && x%100 != 0) || x%400 == 0)
		printf("%d yili artik yildir.",x);
	else
		printf("%d yili artik yil degildir.\n",x);

	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	system("PAUSE");
	return EXIT_SUCCESS;