/****************************************************************************
**					SAKARYA ÜNÝVERSÝTESÝ
**			         BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**				    BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**				          PROGRAMLAMAYA GÝRÝÞÝ DERSÝ
**
**				ÖDEV NUMARASI…...: 1
**				ÖÐRENCÝ ADI...............: Ayþe Verda Gülcemal
**				ÖÐRENCÝ NUMARASI.:g221210038
**				DERS GRUBU…………:ikinci öðretim A
****************************************************************************/



#include <iostream>
#include <cstdlib>
#include <clocale>  
#include <ctime>                // gerekli kütüphaneleri ekledik
#include <cmath>
#include <iomanip>


using namespace std;

struct date
{			
	int gun;
	int ay;                        // tarih struct yapýmýzý tanýmladýk
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
	float proje;                  // sýnýf structi altýnda isim,soyisim,numara ve sýnav elemanlarýný tanýmladýk
	float výze;
	float fýnal;
	struct date;
};

sinif ogrenciler[101];            // yüz kiþilik bir öðrenci dizisi hazýrladýk

int ortalama()
{
	int sonuc = 0;

	for (int a = 1; a < 101; a++)                       // sýnýf ortalamasýný hesaplayan fonksiyon
	{
		sonuc = ogrenciler[a].výze + sonuc;
	}
	return sonuc;
}

float standartsapma(sinif ogrenciler[101])
{
	float ort, standartsapma = 0.0, toplam = 0.0;      // standart sapmayý hesaplayan fonksiyon
	int a;

	for (a = 0;a < 101; ++a)	
	{
		toplam += ogrenciler[a].výze;
	}

	ort = toplam / 100;

	for (a = 0; a < 100; ++a)
	{
		standartsapma += pow(ogrenciler[a].výze - ort, 2);
	}

	return sqrt(standartsapma / 100);
}

void belli_notun_altýnda_kalanlar()
{
	for (int a = 1;a < 101;a++)                     // 50'nin altýndaki notlarý listeleyen fonksiyon
	{
		if (ogrenciler[a].výze <=50)
			cout << ogrenciler[a].výze << endl;
	}
}

void belli_notun_üstünde_kalanlar()
{
	for (int a = 1;a < 101;a++)                   // 80'nin üstündeki notlarý listeleyen fonksiyon
	{  
		if (ogrenciler[a].výze>=80)
			cout << ogrenciler[a].výze << endl;
	}
}

void belliaralik()
{
	for (int a = 1;a < 101;a++)                  // 35-70 arasý notlarý listeleyen fonksiyon
	{ 
		if (ogrenciler[a].výze > 35 && ogrenciler[a].výze <= 70)
			cout << ogrenciler[a].výze << endl;
	}
}

int enyuksekpuan() {

	int max = 0;
	for (int a = 0; a < 101; a++)               // sýnýftaki en yüksek puaný gösteren fonksiyon
	{
		if (ogrenciler[a].výze > max)
		{
			max = ogrenciler[a].výze;
		}
	}
	return max;
}


int endusukpuan()
{
	for (int a = 0; a < 101; a++)               //sýnýftaki en düþük puaný gösteren fonksiyon
	{
		int min =ogrenciler[0].výze;

		if (ogrenciler[a].výze< min)
		{
			min = ogrenciler[a].výze;	
		}
		return min;

	}
}
void notuharfecevir(int a)                   // alýnan notu harfe çeviren ve doðrulugunu kontrol eden fonksiyon
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
	// öðrenci isimlerini tanýmladýk 

	string ogrencilerin_soyisimleri[30] = { "derin","deniz","pinar","yesil","cemal","cemil","kerim","aksoy","ersoy","doðan"
	,"dogus","derya","özcan","kumru","þahin","yalin","besir","guzel","kutlu","doruk","akife","cihan","cicek","batur",
	"beyaz","birol","cakar","ercan","akman","aksel"};
	// öðrenci soyisimlerini tanýmladýk
	srand(time(NULL));


	for (int j = 1; j < 101; j++)
	{
		for (int i = 1; i < 101; i++) // yazdýðýmýz 30 ismi random olarak 100 kiþiye atadýk
		{
			ogrenciler[i].isim = ogrencilerin_isimleri[rand() % 30];
			ogrenciler[i].soyisim = ogrencilerin_soyisimleri[rand() % 30];
		}

		if (j > 0 && j < 11) // öðrencilerinin %10'unun final puaný 0-40 arasýnda olacak þekilde atadýk
		{
			ogrenciler[j].fýnal = rand() % 40;
		}

		if (j > 10 && j < 61) // öðrencilerin %50’sinin final puaný 40-70 arasýnda olacak þekilde atadýk
		{
			ogrenciler[j].fýnal = rand() % 30 + 40;
		}

		if (j > 60 && j < 76) // öðrencilerin %15’inin final notunu 70 ile 80 arasýnda olacak biçimde atadýk
		{
			ogrenciler[j].fýnal = rand() % 10 + 70;
		}

		if (j > 75 && j < 101) //öðrencilerin %25’inin final notunu 80 ile 100 arasýnda olacak biçimde atadýk
		{
			ogrenciler[j].fýnal = rand() % 20 + 80;
		}

	}


	for (int j = 1; j < 101; j++)
	{

		if (j > 0 && j < 11) 
		{
			ogrenciler[j].výze = rand() % 40;      // öðrencilerinin %10'unun vize puaný 0-40 arasýnda olacak þekilde atadýk
		}

		if (j > 10 && j < 61)
		{
			ogrenciler[j].výze = rand() % 30 + 40; // öðrencilerin %50’sinin vize puaný 40-70 arasýnda olacak þekilde atadýk
		}

		if (j > 60 && j < 76)
		{
			ogrenciler[j].výze = rand() % 10 + 70; // öðrencilerin %15’inin vize notunu 70 ile 80 arasýnda olacak biçimde atadýk
		}

		if (j > 75 && j < 101)
		{
			ogrenciler[j].výze = rand() % 20 + 80; //öðrencilerin %25’inin vize notunu 80 ile 100 arasýnda olacak biçimde atadýk
		} 
	}

	for (int j = 1; j < 101; j++)
	{
        if (j > 0 && j < 11)
		{
			ogrenciler[j].kisasinav1 = rand() % 40; // öðrencilerinin %10'unun 1.kisa sinav puaný 0-40 arasýnda olacak þekilde atadýk
		}

		if (j > 10 && j < 61)
		{
			ogrenciler[j].kisasinav1 = rand() % 30 + 40; // öðrencilerin %50’sinin 1.kisa sinav puaný 40-70 arasýnda olacak þekilde atadýk
		}

		if (j > 60 && j < 76)
		{
			ogrenciler[j].kisasinav1 = rand() % 10 + 70; // öðrencilerin %15’inin 1.kisa sinav notunu 70-80 arasýnda olacak biçimde atadýk
		}

		if (j > 75 && j < 101)
		{
			ogrenciler[j].kisasinav1 = rand() % 20 + 80; //öðrencilerin %25’inin 1.kisa sinav notunu 80-100 arasýnda olacak biçimde atadýk
		}

	}

	for (int j = 1; j < 101; j++)
	{

		if (j > 0 && j < 11)
		{
			ogrenciler[j].kisasinav2 = rand() % 40; //öðrencilerinin % 10'unun 2.kisa sinav puaný 0-40 arasýnda olacak þekilde atadýk
		}

		if (j > 10 && j < 61)
		{
			ogrenciler[j].kisasinav2 = rand() % 30 + 40; // öðrencilerin %50’sinin 2.kisa sinav puaný 40-70 arasýnda olacak þekilde atadýk
		}

		if (j > 60 && j < 76)
		{
			ogrenciler[j].kisasinav2 = rand() % 10 + 70; //öðrencilerin %15’inin 2.kisa sinav notunu 70-80 arasýnda olacak biçimde atadýk
		}

		if (j > 75 && j < 101)
		{
			ogrenciler[j].kisasinav2 = rand() % 20 + 80; //öðrencilerin %25’inin 2.kisa sinav notunu 80-100 arasýnda olacak biçimde atadýk
		}

	}
	for (int j = 1; j < 101; j++)
	{

		if (j > 0 && j < 11)
		{
			ogrenciler[j].odev1 = rand() % 40; //öðrencilerinin % 10'unun 1.ödev puaný 0-40 arasýnda olacak þekilde atadýk
		}

		if (j > 10 && j < 61)
		{
			ogrenciler[j].odev1 = rand() % 30 + 40;  // öðrencilerin %50’sinin 1.ödev puaný 40-70 arasýnda olacak þekilde atadýk
		}

		if (j > 60 && j < 76)
		{
			ogrenciler[j].odev1 = rand() % 10 + 70;  //öðrencilerin %15’inin 1.ödev notunu 70-80 arasýnda olacak biçimde atadýk
		}

		if (j > 75 && j < 101)
		{
			ogrenciler[j].odev1 = rand() % 20 + 80; //öðrencilerin %25’inin 1.ödev notunu 80-100 arasýnda olacak biçimde atadýk
		}

	}

	for (int j = 1; j < 101; j++)
	{

		if (j > 0 && j < 11)
		{
			ogrenciler[j].odev2 = rand() % 40; //öðrencilerinin % 10'unun 2.ödev puaný 0-40 arasýnda olacak þekilde atadýk

		}

		if (j > 10 && j < 61)
		{
			ogrenciler[j].odev2 = rand() % 30 + 40; // öðrencilerin %50’sinin 2.ödev puaný 40-70 arasýnda olacak þekilde atadýk

		}
		if (j > 60 && j < 76)
		{
			ogrenciler[j].odev2 = rand() % 10 + 70; //öðrencilerin %15’inin 2.ödev notunu 70-80 arasýnda olacak biçimde atadýk

		}

		if (j > 75 && j < 101)
		{
			ogrenciler[j].odev2 = rand() % 20 + 80; //öðrencilerin %25’inin 2.ödev notunu 80-100 arasýnda olacak biçimde atadýk

		}

	}

	
	int secenek{}, menü{};
	cout << "ogrencilerin rastgele girilmesi için 1'i kendiniz girmek için 2'yi tuslayiniz" << endl;
	cin >> secenek;

	switch (secenek)
	{
	case 1:                    // ilk seçenek ile isim-soyisim elemanlarýný rastgele atayarak 100 random öðrenci yazdýrdýk

	for (int a = 1; a < 101; a++)
	{
		cout << ogrenciler[a].isim << setw(8) << ogrenciler[a].soyisim << endl;
		
}
	break;

	case 2:                   // ikinci seçenek ile manuel olarak 100 öðrenci ve notlarýný giriyoruz


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
				cin >> ogrenciler[a].výze;

				if (!(ogrenciler[a].výze <= 100 && ogrenciler[a].výze >= 0))
				{
					cout << "gecersiz not girdiniz,tekrar deneyiniz" << endl;
				}

			} while (!(ogrenciler[a].výze <= 100 && ogrenciler[a].výze >= 0));


			do
			{
				cout << a << ".Ogrencinin ilk kýsa sýnav notunu giriniz : ";                  // notlarý giriyoruz aralýðýný kontrol ediyor
				cin >> ogrenciler[a].kisasinav1;

				if (!(ogrenciler[a].kisasinav1 <= 100 && ogrenciler[a].kisasinav1 >= 0))
				{
					cout << "gecersiz not girdiniz,tekrar deneyiniz" << endl;
				}

			} while (!(ogrenciler[a].kisasinav1 <= 100 && ogrenciler[a].kisasinav1 >= 0));



			do
			{
				cout << a << ".Ogrencinin ikinci kýsa sýnav notunu giriniz : ";
				cin >> ogrenciler[a].kisasinav2;

				if (!(ogrenciler[a].kisasinav2 <= 100 && ogrenciler[a].kisasinav2 >= 0))
				{
					cout << "gecersiz not girdiniz,tekrar deneyiniz" << endl;
				}

			} while (!(ogrenciler[a].kisasinav2 <= 100 && ogrenciler[a].kisasinav2 >= 0));



			do
			{
				cout << a << ".Ogrencinin ilk kýsa odev notunu giriniz : ";
				cin >> ogrenciler[a].odev1;

				if (!(ogrenciler[a].odev1 <= 100 && ogrenciler[a].odev1 >= 0))
				{
					cout << "gecersiz not girdiniz,tekrar deneyiniz" << endl;
				}

			} while (!(ogrenciler[a].odev1 <= 100 && ogrenciler[a].odev1 >= 0));


			do
			{
				cout << a << ".Ogrencinin ikinci kýsa odev notunu giriniz : ";
				cin >> ogrenciler[a].odev2;

				if (!(ogrenciler[a].odev2 <= 100 && ogrenciler[a].odev2 >= 0))
				{
					cout << "gecersiz not girdiniz,tekrar deneyiniz" << endl;
				}

			} while (!(ogrenciler[a].odev2 <= 100 && ogrenciler[a].odev2 >= 0));


			do
			{
				cout << a << ".Ogrencinin final notunu giriniz : ";
				cin >> ogrenciler[a].fýnal;

				if (!(ogrenciler[a].fýnal <= 100 && ogrenciler[a].fýnal >= 0))
				{
					cout << "gecersiz not girdiniz,tekrar deneyiniz" << endl;
				}

			} while (!(ogrenciler[a].fýnal <= 100 && ogrenciler[a].fýnal >= 0));



			do
			{
				cout << a << ".Ogrencinin proje notunu giriniz : ";
				cin >> ogrenciler[a].proje;

				if (!(ogrenciler[a].proje <= 100 && ogrenciler[a].proje >= 0))
				{
					cout << "gecersiz not girdiniz,tekrar deneyiniz" << endl;
				}

			} while (!(ogrenciler[a].proje <= 100 && ogrenciler[a].proje >= 0));
		

			float yilicinotu = (ogrenciler[a].výze * 0.5)                         // yýl içi notunu hesapladýk
				+ (ogrenciler[a].kisasinav1 * 0.07)
				+ (ogrenciler[a].kisasinav2 * 0.07)
				+ (ogrenciler[a].odev1 * 0.10)
				+ (ogrenciler[a].odev2 * 0.10)
				+ (ogrenciler[a].proje * 0.16);

			float basarinotu = (yilicinotu * 0.55) + (ogrenciler[a].fýnal * 0.45); // baþarý notunu hesapladýk

			cout << a << ". yýl içi notu : " << yilicinotu << endl;
			cout << a << ". baþarý notu : " << basarinotu;
			cout << endl << endl;
		}
	}


	cout << endl << endl << endl;


	cout << "menüden istediðiniz seçeneði seçiniz: " << endl;
	cout << "(1).isimleri 20'li gruplar halinde yazdýr" << endl;
	cout << "(2).sýnýfýn en  yüksek vize puanýný yazdýr" << endl;
	cout << "(3).sýnýfýn en düþük vize puanýný yazdýr" << endl;
	cout << "(4).sýnýfýn vize puaný ortalamasýný yazdýr" << endl;
	cout << "(5).sýnýfýn vize puanýnýn standart sapmasýný yazdýr" << endl;
	cout << "(6).vize puaný 35 ve 70 arasýndaki notlarý listele." << endl;
	cout << "(7).vize puaný 50 altýndaki notlar listele. " << endl;
	cout << "(8).vize puaný 80 üstündeki notlar listele." << endl;
	cin >> menü;



	switch (menü) {
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
				cout << "diðer 20 kiþiyi yazdýrmak için d'yi çýkmak için c'yi tuþlayýnýz";
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
				cout << "listenin sonu lütfen q'ya basýn";
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
		cout << "sinifin en düsük puani : " << endusukpuan();
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
		belli_notun_altýnda_kalanlar();
		break;
	case 8:
		belli_notun_üstünde_kalanlar();
		break;
	default:
		cout << "1-8 arasý bir seçenek girmeniz gerekmektedir";
	}
}