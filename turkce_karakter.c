#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL,"Turkish");
	printf("Beyler Selam�n Aleyk�m");
	/* 
	
	(save with encoding Turkish Windows-1254)
	CMD'de T�rk�e karakter g�r�nmesi i�in : 
	{
		(Windows+R) �al��t�r/regedit/HKEY_CURRENT_USER/Console/ : Yeni DWORD32Bit De�er "CodePage"
		De�er : 359 , Onalt�l�k.
	}*/
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	system("PAUSE");
	return EXIT_SUCCESS;
}