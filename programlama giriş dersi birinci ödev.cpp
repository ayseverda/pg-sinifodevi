/****************************************************************************
**					SAKARYA �N�VERS�TES�
**			         B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
**				    B�LG�SAYAR M�HEND�SL��� B�L�M�
**				          PROGRAMLAMAYA G�R��� DERS�
**
**				�DEV NUMARASI�...: 1
**				��RENC� ADI...............: Ay�e Verda G�lcemal
**				��RENC� NUMARASI.:g221210038
**				DERS GRUBU����:ikinci ��retim A
****************************************************************************/



#include <iostream>
#include <cstdlib>
#include <clocale>  
#include <ctime>                // gerekli k�t�phaneleri ekledik
#include <cmath>
#include <iomanip>


using namespace std;

struct date
{			
	int gun;
	int ay;                        // tarih struct yap�m�z� tan�mlad�k
	int yil;
	
};


struct sinif
{
	string isim;
	string soyisim;
	int numara;
	float kisasinav1;
	float kisasinav2;
	float odev1;
	float odev2;
	float proje;                  // s�n�f structi alt�nda isim,soyisim,numara ve s�nav elemanlar�n� tan�mlad�k
	float v�ze;
	float f�nal;
	struct date;
};

sinif ogrenciler[101];            // y�z ki�ilik bir ��renci dizisi haz�rlad�k

int ortalama()
{
	int sonuc = 0;

	for (int a = 1; a < 101; a++)                       // s�n�f ortalamas�n� hesaplayan fonksiyon
	{
		sonuc = ogrenciler[a].v�ze + sonuc;
	}
	return sonuc;
}

float standartsapma(sinif ogrenciler[101])
{
	float ort, standartsapma = 0.0, toplam = 0.0;      // standart sapmay� hesaplayan fonksiyon
	int a;

	for (a = 0;a < 101; ++a)	
	{
		toplam += ogrenciler[a].v�ze;
	}

	ort = toplam / 100;

	for (a = 0; a < 100; ++a)
	{
		standartsapma += pow(ogrenciler[a].v�ze - ort, 2);
	}

	return sqrt(standartsapma / 100);
}

void belli_notun_alt�nda_kalanlar()
{
	for (int a = 1;a < 101;a++)                     // 50'nin alt�ndaki notlar� listeleyen fonksiyon
	{
		if (ogrenciler[a].v�ze <=50)
			cout << ogrenciler[a].v�ze << endl;
	}
}

void belli_notun_�st�nde_kalanlar()
{
	for (int a = 1;a < 101;a++)                   // 80'nin �st�ndeki notlar� listeleyen fonksiyon
	{  
		if (ogrenciler[a].v�ze>=80)
			cout << ogrenciler[a].v�ze << endl;
	}
}

void belliaralik()
{
	for (int a = 1;a < 101;a++)                  // 35-70 aras� notlar� listeleyen fonksiyon
	{ 
		if (ogrenciler[a].v�ze > 35 && ogrenciler[a].v�ze <= 70)
			cout << ogrenciler[a].v�ze << endl;
	}
}

int enyuksekpuan() {

	int max = 0;
	for (int a = 0; a < 101; a++)               // s�n�ftaki en y�ksek puan� g�steren fonksiyon
	{
		if (ogrenciler[a].v�ze > max)
		{
			max = ogrenciler[a].v�ze;
		}
	}
	return max;
}


int endusukpuan()
{
	for (int a = 0; a < 101; a++)               //s�n�ftaki en d���k puan� g�steren fonksiyon
	{
		int min =ogrenciler[0].v�ze;

		if (ogrenciler[a].v�ze< min)
		{
			min = ogrenciler[a].v�ze;	
		}
		return min;

	}
}
void notuharfecevir(int a)                   // al�nan notu harfe �eviren ve do�rulugunu kontrol eden fonksiyon
{
	if (90 <= a && a <= 100)
		cout << "A+";

	else if (80 <= a && a < 90)
		cout << "A";

	else if (70 <= a && a < 80)
		cout << "B+";
	
	else if (60 <= a && a <70)
		cout << "B";

	else if (50 <= a && a < 60)
		cout << "C";

	else if (40 <= a && a < 50)
		cout << "D";

	else if (30 <= a && a < 40)
		cout << "E";

	else if (20 <= a && a <30)
		cout << "F";

	else if (0 <= a && a < 20)
		cout << "F-";
	else
		cout << "aralik disinda bir not girildi" << endl;
}


int main(int argc, char** argv) {

	setlocale(LC_ALL, "Turkish"); 
	
	string ogrencilerin_isimleri[30] = { "ayse","irem","esma","buse","sera","musa","sena","vera","bera","onur","rana"
		,"irem","emre","ekin","gaye","alya","ayca","emel","dila","azra","tuba","lara","idil","nisa","sema","banu",
		"ecem","ezgi","esra","duru"};
	// ��renci isimlerini tan�mlad�k 

	string ogrencilerin_soyisimleri[30] = { "derin","deniz","pinar","yesil","cemal","cemil","kerim","aksoy","ersoy","do�an"
	,"dogus","derya","�zcan","kumru","�ahin","yalin","besir","guzel","kutlu","doruk","akife","cihan","cicek","batur",
	"beyaz","birol","cakar","ercan","akman","aksel"};
	// ��renci soyisimlerini tan�mlad�k
	srand(time(NULL));


	for (int j = 1; j < 101; j++)
	{
		for (int i = 1; i < 101; i++) // yazd���m�z 30 ismi random olarak 100 ki�iye atad�k
		{
			ogrenciler[i].isim = ogrencilerin_isimleri[rand() % 30];
			ogrenciler[i].soyisim = ogrencilerin_soyisimleri[rand() % 30];
		}

		if (j > 0 && j < 11) // ��rencilerinin %10'unun final puan� 0-40 aras�nda olacak �ekilde atad�k
		{
			ogrenciler[j].f�nal = rand() % 40;
		}

		if (j > 10 && j < 61) // ��rencilerin %50�sinin final puan� 40-70 aras�nda olacak �ekilde atad�k
		{
			ogrenciler[j].f�nal = rand() % 30 + 40;
		}

		if (j > 60 && j < 76) // ��rencilerin %15�inin final notunu 70 ile 80 aras�nda olacak bi�imde atad�k
		{
			ogrenciler[j].f�nal = rand() % 10 + 70;
		}

		if (j > 75 && j < 101) //��rencilerin %25�inin final notunu 80 ile 100 aras�nda olacak bi�imde atad�k
		{
			ogrenciler[j].f�nal = rand() % 20 + 80;
		}

	}


	for (int j = 1; j < 101; j++)
	{

		if (j > 0 && j < 11) 
		{
			ogrenciler[j].v�ze = rand() % 40;      // ��rencilerinin %10'unun vize puan� 0-40 aras�nda olacak �ekilde atad�k
		}

		if (j > 10 && j < 61)
		{
			ogrenciler[j].v�ze = rand() % 30 + 40; // ��rencilerin %50�sinin vize puan� 40-70 aras�nda olacak �ekilde atad�k
		}

		if (j > 60 && j < 76)
		{
			ogrenciler[j].v�ze = rand() % 10 + 70; // ��rencilerin %15�inin vize notunu 70 ile 80 aras�nda olacak bi�imde atad�k
		}

		if (j > 75 && j < 101)
		{
			ogrenciler[j].v�ze = rand() % 20 + 80; //��rencilerin %25�inin vize notunu 80 ile 100 aras�nda olacak bi�imde atad�k
		} 
	}

	for (int j = 1; j < 101; j++)
	{
        if (j > 0 && j < 11)
		{
			ogrenciler[j].kisasinav1 = rand() % 40; // ��rencilerinin %10'unun 1.kisa sinav puan� 0-40 aras�nda olacak �ekilde atad�k
		}

		if (j > 10 && j < 61)
		{
			ogrenciler[j].kisasinav1 = rand() % 30 + 40; // ��rencilerin %50�sinin 1.kisa sinav puan� 40-70 aras�nda olacak �ekilde atad�k
		}

		if (j > 60 && j < 76)
		{
			ogrenciler[j].kisasinav1 = rand() % 10 + 70; // ��rencilerin %15�inin 1.kisa sinav notunu 70-80 aras�nda olacak bi�imde atad�k
		}

		if (j > 75 && j < 101)
		{
			ogrenciler[j].kisasinav1 = rand() % 20 + 80; //��rencilerin %25�inin 1.kisa sinav notunu 80-100 aras�nda olacak bi�imde atad�k
		}

	}

	for (int j = 1; j < 101; j++)
	{

		if (j > 0 && j < 11)
		{
			ogrenciler[j].kisasinav2 = rand() % 40; //��rencilerinin % 10'unun 2.kisa sinav puan� 0-40 aras�nda olacak �ekilde atad�k
		}

		if (j > 10 && j < 61)
		{
			ogrenciler[j].kisasinav2 = rand() % 30 + 40; // ��rencilerin %50�sinin 2.kisa sinav puan� 40-70 aras�nda olacak �ekilde atad�k
		}

		if (j > 60 && j < 76)
		{
			ogrenciler[j].kisasinav2 = rand() % 10 + 70; //��rencilerin %15�inin 2.kisa sinav notunu 70-80 aras�nda olacak bi�imde atad�k
		}

		if (j > 75 && j < 101)
		{
			ogrenciler[j].kisasinav2 = rand() % 20 + 80; //��rencilerin %25�inin 2.kisa sinav notunu 80-100 aras�nda olacak bi�imde atad�k
		}

	}
	for (int j = 1; j < 101; j++)
	{

		if (j > 0 && j < 11)
		{
			ogrenciler[j].odev1 = rand() % 40; //��rencilerinin % 10'unun 1.�dev puan� 0-40 aras�nda olacak �ekilde atad�k
		}

		if (j > 10 && j < 61)
		{
			ogrenciler[j].odev1 = rand() % 30 + 40;  // ��rencilerin %50�sinin 1.�dev puan� 40-70 aras�nda olacak �ekilde atad�k
		}

		if (j > 60 && j < 76)
		{
			ogrenciler[j].odev1 = rand() % 10 + 70;  //��rencilerin %15�inin 1.�dev notunu 70-80 aras�nda olacak bi�imde atad�k
		}

		if (j > 75 && j < 101)
		{
			ogrenciler[j].odev1 = rand() % 20 + 80; //��rencilerin %25�inin 1.�dev notunu 80-100 aras�nda olacak bi�imde atad�k
		}

	}

	for (int j = 1; j < 101; j++)
	{

		if (j > 0 && j < 11)
		{
			ogrenciler[j].odev2 = rand() % 40; //��rencilerinin % 10'unun 2.�dev puan� 0-40 aras�nda olacak �ekilde atad�k

		}

		if (j > 10 && j < 61)
		{
			ogrenciler[j].odev2 = rand() % 30 + 40; // ��rencilerin %50�sinin 2.�dev puan� 40-70 aras�nda olacak �ekilde atad�k

		}
		if (j > 60 && j < 76)
		{
			ogrenciler[j].odev2 = rand() % 10 + 70; //��rencilerin %15�inin 2.�dev notunu 70-80 aras�nda olacak bi�imde atad�k

		}

		if (j > 75 && j < 101)
		{
			ogrenciler[j].odev2 = rand() % 20 + 80; //��rencilerin %25�inin 2.�dev notunu 80-100 aras�nda olacak bi�imde atad�k

		}

	}

	
	int secenek{}, men�{};
	cout << "ogrencilerin rastgele girilmesi i�in 1'i kendiniz girmek i�in 2'yi tuslayiniz" << endl;
	cin >> secenek;

	switch (secenek)
	{
	case 1:                    // ilk se�enek ile isim-soyisim elemanlar�n� rastgele atayarak 100 random ��renci yazd�rd�k

	for (int a = 1; a < 101; a++)
	{
		cout << ogrenciler[a].isim << setw(8) << ogrenciler[a].soyisim << endl;
		
}
	break;

	case 2:                   // ikinci se�enek ile manuel olarak 100 ��renci ve notlar�n� giriyoruz


		for (int a = 1; a < 101; a++)
		{
			cout << a << ".Ogrencinin adi :  ";
			cin >> ogrenciler[a].isim;


			cout << a << ".Ogrencinin soyadi : ";           
			cin >> ogrenciler[a].soyisim;


			cout << a << ".Ogrencinin numarasi : ";
			cin >> ogrenciler[a].numara;

			do
			{
				cout << a << ".Ogrencinin vize notu : ";
				cin >> ogrenciler[a].v�ze;

				if (!(ogrenciler[a].v�ze <= 100 && ogrenciler[a].v�ze >= 0))
				{
					cout << "gecersiz not girdiniz,tekrar deneyiniz" << endl;
				}

			} while (!(ogrenciler[a].v�ze <= 100 && ogrenciler[a].v�ze >= 0));


			do
			{
				cout << a << ".Ogrencinin ilk k�sa s�nav notunu giriniz : ";                  // notlar� giriyoruz aral���n� kontrol ediyor
				cin >> ogrenciler[a].kisasinav1;

				if (!(ogrenciler[a].kisasinav1 <= 100 && ogrenciler[a].kisasinav1 >= 0))
				{
					cout << "gecersiz not girdiniz,tekrar deneyiniz" << endl;
				}

			} while (!(ogrenciler[a].kisasinav1 <= 100 && ogrenciler[a].kisasinav1 >= 0));



			do
			{
				cout << a << ".Ogrencinin ikinci k�sa s�nav notunu giriniz : ";
				cin >> ogrenciler[a].kisasinav2;

				if (!(ogrenciler[a].kisasinav2 <= 100 && ogrenciler[a].kisasinav2 >= 0))
				{
					cout << "gecersiz not girdiniz,tekrar deneyiniz" << endl;
				}

			} while (!(ogrenciler[a].kisasinav2 <= 100 && ogrenciler[a].kisasinav2 >= 0));



			do
			{
				cout << a << ".Ogrencinin ilk k�sa odev notunu giriniz : ";
				cin >> ogrenciler[a].odev1;

				if (!(ogrenciler[a].odev1 <= 100 && ogrenciler[a].odev1 >= 0))
				{
					cout << "gecersiz not girdiniz,tekrar deneyiniz" << endl;
				}

			} while (!(ogrenciler[a].odev1 <= 100 && ogrenciler[a].odev1 >= 0));


			do
			{
				cout << a << ".Ogrencinin ikinci k�sa odev notunu giriniz : ";
				cin >> ogrenciler[a].odev2;

				if (!(ogrenciler[a].odev2 <= 100 && ogrenciler[a].odev2 >= 0))
				{
					cout << "gecersiz not girdiniz,tekrar deneyiniz" << endl;
				}

			} while (!(ogrenciler[a].odev2 <= 100 && ogrenciler[a].odev2 >= 0));


			do
			{
				cout << a << ".Ogrencinin final notunu giriniz : ";
				cin >> ogrenciler[a].f�nal;

				if (!(ogrenciler[a].f�nal <= 100 && ogrenciler[a].f�nal >= 0))
				{
					cout << "gecersiz not girdiniz,tekrar deneyiniz" << endl;
				}

			} while (!(ogrenciler[a].f�nal <= 100 && ogrenciler[a].f�nal >= 0));



			do
			{
				cout << a << ".Ogrencinin proje notunu giriniz : ";
				cin >> ogrenciler[a].proje;

				if (!(ogrenciler[a].proje <= 100 && ogrenciler[a].proje >= 0))
				{
					cout << "gecersiz not girdiniz,tekrar deneyiniz" << endl;
				}

			} while (!(ogrenciler[a].proje <= 100 && ogrenciler[a].proje >= 0));
		

			float yilicinotu = (ogrenciler[a].v�ze * 0.5)                         // y�l i�i notunu hesaplad�k
				+ (ogrenciler[a].kisasinav1 * 0.07)
				+ (ogrenciler[a].kisasinav2 * 0.07)
				+ (ogrenciler[a].odev1 * 0.10)
				+ (ogrenciler[a].odev2 * 0.10)
				+ (ogrenciler[a].proje * 0.16);

			float basarinotu = (yilicinotu * 0.55) + (ogrenciler[a].f�nal * 0.45); // ba�ar� notunu hesaplad�k

			cout << a << ". y�l i�i notu : " << yilicinotu << endl;
			cout << a << ". ba�ar� notu : " << basarinotu;
			cout << endl << endl;
		}
	}


	cout << endl << endl << endl;


	cout << "men�den istedi�iniz se�ene�i se�iniz: " << endl;
	cout << "(1).isimleri 20'li gruplar halinde yazd�r" << endl;
	cout << "(2).s�n�f�n en  y�ksek vize puan�n� yazd�r" << endl;
	cout << "(3).s�n�f�n en d���k vize puan�n� yazd�r" << endl;
	cout << "(4).s�n�f�n vize puan� ortalamas�n� yazd�r" << endl;
	cout << "(5).s�n�f�n vize puan�n�n standart sapmas�n� yazd�r" << endl;
	cout << "(6).vize puan� 35 ve 70 aras�ndaki notlar� listele." << endl;
	cout << "(7).vize puan� 50 alt�ndaki notlar listele. " << endl;
	cout << "(8).vize puan� 80 �st�ndeki notlar listele." << endl;
	cin >> men�;



	switch (men�) {
	case 1:
	{
		char secenek;
		int a = 1;
		int b = 20;

		do
		{
			for (int i = a; i < b; i++)
			{
				cout << i << " " << ogrenciler[i].isim << setw(10) << ogrenciler[i].soyisim << endl;
			}

			if (a < 80)
			{
				cout << "di�er 20 ki�iyi yazd�rmak i�in d'yi ��kmak i�in c'yi tu�lay�n�z";
				cin >> secenek;
				if (secenek == 'd')
				{
					system("CLS");
					a += 20;
					b += 20;

				}

			}
			else
			{
				cout << "listenin sonu l�tfen q'ya bas�n";
				cin >> secenek;
				a = 0;
				b = 20;
			}
		} while (secenek != 'c');
	}
	break;
	case 2:
		cout << "sinifin en yuksek puani : " <<enyuksekpuan();
		break;
	case 3:
		cout << "sinifin en d�s�k puani : " << endusukpuan();
		break;
	case 4:
		cout << "sinifin ortalamasi : " << ortalama() / 100;
		break;
	case 5:
		cout << "standart sapma : " << standartsapma(ogrenciler);
		break;
	case 6:
		belliaralik();
		break;
	case 7:
		belli_notun_alt�nda_kalanlar();
		break;
	case 8:
		belli_notun_�st�nde_kalanlar();
		break;
	default:
		cout << "1-8 aras� bir se�enek girmeniz gerekmektedir";
	}
}