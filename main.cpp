#include <iostream>
#include <string>
#include <fstream>
#include<locale.h>
#include<iomanip>

using namespace std;
class calisanSistemi {
public:
    string hasta_adı, hasta_soyad, doktor_adi, hasta_tc, eczane, durum, sigorta;
    int  tercih, tercih2, tercih3, tercih5, para, nöropara = 700, gözpara = 500, ciltpara = 200, pay;
    string hasta_tel, reçetekodu, hasta_yas;
    string randevutarihi, randevusaati;
};
class sekretersistemi :public calisanSistemi {
public:

};




int main() {
    sekretersistemi x;



    setlocale(LC_ALL, "Turkish");

    char cevap = 'e';








    do {



        cout << "\n--Yapılacak Sistem Girişini Seçiniz--" << endl;
        cout << endl;
        cout << endl;
        cout << "1-SEKRETER GİRİŞİ" << endl;
        cout << "2-DOKTOR GİRİŞİ" << endl;
        cout << "3-ECZANE GİRİŞİ" << endl;

        cin >> x.tercih;

        switch (x.tercih)
        {
        case 1:
            cout << "\n--Sekreter Bolumune Giris Yaptiniz--\n" << endl;
            cout << "1-Hasta kaydi yap" << endl;
            cout << "2-Hasta Sorgulama" << endl;
            cout << "3-Randevu al" << endl;


            cin >> x.tercih2;
            if (x.tercih2 == 1) {
                ofstream yazdır;
                yazdır.open("bilgiler.txt", ios::app);
                cout << "\n-------HASTA KAYIT MENUSU-------\n" << endl;

                cout << "Hastanın sigorta durumu nedir (var/yok)\n" << endl;
                cin >> x.durum;


                if (x.durum == "var") {
                    ofstream yazdır;
                    yazdır.open("sigortalı.txt", ios::app);


                    cout << "Hastanin tcsi:" << endl;
                    cin >> x.hasta_tc;
                    cout << "Hastanin adi:" << endl;
                    cin >> x.hasta_adı;
                    cout << "Hastanin soyadi:" << endl;
                    cin >> x.hasta_soyad;
                    cout << "Hastanin yasi:" << endl;
                    cin >> x.hasta_yas;
                    cout << "Hastanin tel numarasi:" << endl;
                    cin >> x.hasta_tel;
                    cout << "hastanın sigorta durumu" << endl;
                    cin >> x.sigorta;





                    yazdır << endl << "Sigortalı Hastalar\n" << endl << "hastanın tcsi: " << x.hasta_tc << endl << "hastanın tcsi: " << x.hasta_adı << endl << "hastanın soyadı: " << x.hasta_soyad << endl << "hastanın yaşı: " << x.hasta_yas << endl << "hastanın teli: " << x.hasta_tel << endl << "hastanın sigorta durumu:" << x.sigorta << endl;
                    cout << "\nHasta kaydedildi." << endl;
                    cout << "\nAna menüye dönmek istiyor musunuz? (e/h):";
                    cin >> cevap;
                    yazdır.close();


                }

                else if (x.durum == "yok") {

                    ofstream yazdır;
                    yazdır.open("sigortasız.txt", ios::app);




                    cout << "Sigortanız yok aşağıdaki seçeneklerden muayene seçeneklerinden birini seçiniz\n" << endl;
                    cout << "1-) Nöroloji için muayene ücreti ==>700 tl " << endl;
                    cout << "2-) Göz için muayene ücreti ==>500 tl " << endl;
                    cout << "3-) Cildiye için muayene ücreti ==>200 tl " << endl;
                    cin >> x.para;


                    switch (x.para)
                    {
                    case 1:

                        cout << "Nöroloji servisine" << x.nöropara << "tl yatırdınız\n" << endl;

                        break;


                    case 2:

                        cout << "Göz servisine " << x.gözpara << "tl yatırdınız\n" << endl;

                        break;


                    case 3:

                        cout << "Cildiye servisinde " << x.ciltpara << "tl yatırdınız\n" << endl;

                        break;

                    }
                    cout << "sigortanız onaylandı kayıt yaptırabilirsiniz" << endl;

                    cout << "Hastanin tcsi:" << endl;
                    cin >> x.hasta_tc;
                    cout << "Hastanin adi:" << endl;
                    cin >> x.hasta_adı;
                    cout << "Hastanin soyadi:" << endl;
                    cin >> x.hasta_soyad;
                    cout << "Hastanin yasi:" << endl;
                    cin >> x.hasta_yas;
                    cout << "Hastanin tel numarasi:" << endl;
                    cin >> x.hasta_tel;
                    cout << "hastanın sigorta durumu" << endl;
                    cin >> x.sigorta;

                    yazdır << "sigortasız hastalar" << endl;

                    yazdır << endl << "Sigorta Hastalar\n" << endl << "hastanın tcsi: " << x.hasta_tc << endl << "hastanın tcsi: " << x.hasta_adı << endl << "hastanın soyadı: " << x.hasta_soyad << endl << "hastanın yaşı: " << x.hasta_yas << endl << "hastanın teli: " << x.hasta_tel << endl << "hastanın sigorta durumu:" << x.sigorta << endl;
                    cout << "\nHasta kaydedildi." << endl;
                    cout << "\nAna menüye dönmek istiyor musunuz? (e/h):";
                    cin >> cevap;
                    yazdır.close();

                    break;


                }
            }

            if (x.tercih2 == 2) // HASTA SORGULAMA
            {
                cout << "\n------------HASTA SORGULAMA------------" << endl << endl;
                string TC;
                string ifade = "  ";
                int m = 0, n = 0;
                cout << "Hasta TC :"; cin >> TC;
                ifstream dosyaoku;
                dosyaoku.open("bilgiler.txt");
                dosyaoku.open("sigortalı.txt");
                dosyaoku.open("sigortasız.txt");
                while (!dosyaoku.eof()) {
                    dosyaoku >> x.hasta_tc >>x.hasta_adı >> x.hasta_soyad >> x.hasta_yas >> x.hasta_tel >> x.sigorta;
                    if (TC == x.hasta_tc)

                    {



                        cout << "\n---Hastanin Bilgileri--- \n" << endl;
                        cout << "TC no		:" <<x.hasta_tc << endl;
                        cout << "Adi		:" << x.hasta_adı << endl;
                        cout << "Soyadi		:" << x.hasta_soyad << endl;
                        cout << "Yasi		:" << x.hasta_yas << endl;
                        cout << "Telefonu	:" <<x.hasta_tel << endl;
                        cout << "Hastanın sigorta durumu  :"<< x.sigorta << endl;
                        m = 1;

                        ifstream oku_randevu;
                        oku_randevu.open("randevu.txt");
                        oku_randevu >> x.hasta_tc >>x.doktor_adi >> x.randevutarihi >> x.randevusaati >> x.reçetekodu >> x.sigorta;
                        break;
                        if (oku_randevu)
                        {
                            cout << "\n---Hastanin Randevu ve Muayene Bilgileri--- \n" << endl;
                            cout << "TC no	:" << x.hasta_tc << endl;
                            cout << "Doktor Adı	:" << x.doktor_adi << endl;
                            cout << "Randevu Tarihi		:" << x.randevutarihi << endl;
                            cout << "Randevu Saati		:" << x.randevusaati << endl;
                            cout << "Reçete Kodu	:" << x.reçetekodu << endl;

                        }oku_randevu.close();
                        cout << "\nAna Menüye dönmek istiyor musunuz? (e/h):";
                        cin >> cevap;


                    }
                }
                dosyaoku.close();
                break;
            }


            if (x.tercih2 == 3) {
                ofstream randevu_yaz;
                randevu_yaz.open(
                    "randevu.txt", ios::app
                );
                cout << "\n---------Randevu Alma---------\n" << endl << endl;
                cout << "\n---Hastanin Bilgileri--- \n" << endl;
                cout << "TC no		:" << x.hasta_tc << endl;
                cin >> x.hasta_tc;
                cout << "Adi		:" << x.hasta_adı << endl;
                cin >> x.hasta_adı;
                cout << "Soyadi		:" << x.hasta_soyad << endl;
                cin >> x.hasta_soyad;
                cout << "Yasi		:" << x.hasta_yas << endl;
                cin >> x.hasta_yas;
                cout << "\nRandevu istiyor musunuz? (e/h):";
                cin >> cevap;


                if (cevap == 'e') {

                    randevu_yaz.close();
                    ofstream randevu_yaz;
                    randevu_yaz.open("randevu.txt", ios::app);

                    cout << "---Lutfen bir bolum seciniz" << endl;
                    cout << "1-Nöroloji" << endl;
                    cout << "2-Cildiye" << endl;
                    cout << "3-Göz" << endl;
                    cin >> x.tercih3;
                    if (x.tercih3 == 1) {

                        cout << "---Noroloji bolumune hosgeldiniz----\n" << endl;
                        cout << "Doktor Adi	:" << endl;
                        cin >> x.doktor_adi;
                        cout << "randevu tarihini giriniz:" << endl;
                        cin >> x.randevutarihi;
                        cout << "randevu saati giriniz:" << endl;
                        cin >> x.randevusaati;
                        cout << "Randevunuz başarıyla kaydedilmiştir" << endl;
                        randevu_yaz << endl << "" << x.hasta_tc << endl << "" << x.doktor_adi
                            << endl << "" << x.randevutarihi << endl << ""
                            << x.randevusaati << endl;


                    }
                    else if (x.tercih3 == 2) {


                        cout << "---Cildiye bolumune hosgeldiniz---\n" << endl;
                        cout << "Doktor Adi	:" << endl;
                        cin >> x.doktor_adi;
                        cout << "randevu tarihini giriniz:" << endl;
                        cin >> x.randevutarihi;
                        cout << "randevu saati giriniz:" << endl;
                        cin >> x.randevusaati;
                        cout << "Randevunuz başarıyla kaydedilmiştir" << endl;
                        randevu_yaz << endl << "" << x.hasta_tc << endl << "" << x.doktor_adi
                            << endl << "" << x.randevutarihi << endl << ""
                            << x.randevusaati << endl;


                    }
                    else {
                        cout << "\n---Goz hastalıkları bolumune hosgeldiniz----\n" << endl;
                        cout << "Doktor Adi	:" << endl;
                        cin >> x.doktor_adi;
                        cout << "randevu tarihini giriniz:" << endl;
                        cin >> x.randevutarihi;
                        cout << "randevu saati giriniz:" << endl;
                        cin >> x.randevusaati;
                        cout << "Randevunuz başarıyla kaydedilmiştir" << endl;
                        randevu_yaz << endl << "" << x.hasta_tc << endl << "" << x.doktor_adi
                            << endl << "" << x.randevutarihi << endl << ""
                            << x.randevusaati << endl;

                    }
                    randevu_yaz.close();
                    cout << "\nAna Menüye dönmek istiyor musunuz? (e/h):";
                    cin >> cevap;

                }



            }





            break;
        case 2:
            cout << "\n--Doktor Bolumune Giris Yaptınız--\n" << endl;
            cout << "1-Reçete Yaz" << endl;
            cin >> x.tercih5;


            if (x.tercih5 == 1) {

                cout << "\n--Recete yazma Sistemi-- \n" << endl;
                cout << "Hasta Tc	:"; cin >> x.hasta_tc;
                ifstream dosyaoku;
                dosyaoku.open("Sigortalı.txt", ios::app);
                dosyaoku.open("Sigortasız.txt", ios::app);


                dosyaoku >> x.hasta_tc >> x.hasta_adı >> x.hasta_soyad >> x.hasta_yas >> x.hasta_tel;
                cout << "\n---Hastanin Bilgileri--- \n" << endl;
                cout << "TC no		:" << x.hasta_tc << endl;
                cout << "Adi		:" << x.hasta_adı << endl;
                cout << "Soyadi		:" << x.hasta_soyad << endl;
                cout << "Yasi		:" << x.hasta_yas << endl;
                cout << "Telefonu	:" << x.hasta_tel << endl;
                cout << "Sigorta Durumu	:"<< x.sigorta << endl;

                ifstream dosyaoku2;
                dosyaoku2.open("randevu.txt", ios::app);
                dosyaoku2 >> x.hasta_tc >> x.doktor_adi >> x.randevutarihi >> x.randevusaati >> x.reçetekodu;
                ofstream recete_yaz;
                recete_yaz.open("randevu.txt", ios::app


                );

                cout << "Recete kodu:" << endl;
                cin >> x.reçetekodu;
                cout << "--Recete basarıyla olusturulmustur--" << endl;
                cout << "\nAna Menüye dönmek istiyor musunuz? (e/h):";
                cin >> cevap;
                recete_yaz << x.reçetekodu << "\n";
                recete_yaz.close();
                dosyaoku2.close();
                break;
            }
            else {
                break;
            }
        case 3:
            cout << "---Defne Eczanesine Hoş Geldiniz--- \n" << endl;

            cout << "Lütfen Doktorunuz tarafından verilen reçete kodunu giriniz =" << endl;
            cin >> x.eczane;
            if (x.reçetekodu == x.eczane) {


                cout << "1 adet 600mg  arveles /// 3 adet 100mg theflu" << endl;

            }

        }



    } while (cevap == 'e' || cevap == 'E');


}
