#include <stdio.h>
#include <stdlib.h>

int main()
{
	int tc_num,toplam=0;
	printf("Lutfen T.C Kimlik numaranizin ilk 10 hanesini giriniz.\n");
	scanf("%d",&tc_num);
	printf("%d",tc_num);
  	if(tc_num > 9999999999)	 
	{
		printf("Yanlis veya fazla bir numara girdiniz.\n");
		main();
	}				 
	else if(tc_num < 1000000000) 
	{
		printf("Yanlis ya da eksik bir numara girdiniz.\n");
		main();
	}
	else
	{
		for (int i=0;i<10;i++)
		{    
        	toplam += tc_num%10;
        	tc_num /= 10;
        }
		printf("\nT.C Kimlik Numaranizin Son Basamagi : %d\n\n",toplam%10);	
	}
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	system("PAUSE");
	return EXIT_SUCCESS;
}