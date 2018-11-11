#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL,"Turkish");
	printf("Beyler Selamün Aleyküm");
	/* 
	
	(save with encoding Turkish Windows-1254)
	CMD'de Türkçe karakter görünmesi için : 
	{
		(Windows+R) Çalýþtýr/regedit/HKEY_CURRENT_USER/Console/ : Yeni DWORD32Bit Deðer "CodePage"
		Deðer : 359 , Onaltýlýk.
	}*/
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	system("PAUSE");
	return EXIT_SUCCESS;
}