#include<iostream>
#include<string>
using namespace std;


class Ogrenci{
	private:
		string tc;
		string ad;
		string soyad;
		int yas;
		string DersAdi;
		int ortalama;
	public:
		void setTc(string tc) {this->tc=tc;}
		void setAd(string ad) {this->ad=ad;}
		void setSoyad(string soyad) {this->soyad=soyad;}
		void setYas(int yas) {this->yas=yas;}
		void setDersAdi(string DersAdi) {this->DersAdi=DersAdi;}
		void setOrtalama(int ortalama) {this->ortalama=ortalama;}
		
		string getTc(){return tc;}
		string getAd(){return ad;}
		string getSoyad(){return soyad;}
		int getYas(){return yas;}
		string getDersAdi(){return DersAdi;}
		int getOrtalama(){return ortalama;}
		
		void listele(Ogrenci[]);    //Prototip olarak �nce buraya yazd�k. listele metodu Ogrenci class�ndan nesneler dizisi alacak.
	
	
	
};

void Ogrenci :: listele(Ogrenci ogr[]){		   //Ogrenci class�n�n i�indeki listele metorundan Ogrenci cals�ndan ogr s�n�flar� olu�tur.


	for(int i=0;i<3;i++){
		cout<<i+1<<". OGRENCI BILGILERI"<<endl;
		cout<<"TC:"<<ogr[i].getTc()<<endl;
		cout<<"Ad:"<<ogr[i].getAd()<<endl;
		cout<<"SoyAd"<<ogr[i].getSoyad()<<endl;
		cout<<"Yas:"<<ogr[i].getYas()<<endl;
		cout<<"DersAdi:"<<ogr[i].getDersAdi()<<endl;
		cout<<"Ortalama:"<<ogr[i].getOrtalama()<<endl;
	}
}           

void Siralama(Ogrenci ogr[]){
	Ogrenci temp;
	for(int i=0;i<3;i++){
		
			for(int j=0;j<2;j++){
				if(ogr[j].getAd().compare(ogr[j+1].getAd())>0){ //�sme G�re Kar��la�t�racak Hangisini harfi daha a��r diye yani daha b�y�k A dan Z ye de�er art�yor. soldaki sa�dan-
					temp=ogr[j];                                   //- K���k ise -1 b�y�k ise +1 veriyor
					ogr[j]=ogr[j+1];
					ogr[j+1]=temp;
				}
			}
	}
	cout<<"SIRALI HAL�:"<<endl;
	for(int i=0;i<3;i++){
		cout<<"TC:"<<ogr[i].getTc()<<endl;
		cout<<"Ad:"<<ogr[i].getAd()<<endl;
		cout<<"SoyAd"<<ogr[i].getSoyad()<<endl;
		cout<<"Yas:"<<ogr[i].getYas()<<endl;
		cout<<"DersAdi:"<<ogr[i].getDersAdi()<<endl;
		cout<<"Ortalama:"<<ogr[i].getOrtalama()<<endl;
	}
}

void EnYuksekOrtalama(Ogrenci ogr[]){
	
	int ortalama=0;
	Ogrenci temp;	
	cout<<"EN YUKSEK ORTALAMALI OGRENCI:"<<endl;
	for(int i=0;i<3;i++){
		if(ortalama<ogr[i].getOrtalama()){
			temp=ogr[i];                         //Y�ksek olan ��renciyi tempe aktard�k heme altta da y�ksek olan temp oldu�u i�in tempi yazd�rd�k
			ortalama=ogr[i].getOrtalama();
			
		}
	}
	cout<<"TC:"<<temp.getTc()<<endl;
	cout<<"Ad:"<<temp.getAd()<<endl;
	cout<<"SoyAd"<<temp.getSoyad()<<endl;
	cout<<"Yas:"<<temp.getYas()<<endl;
	cout<<"DersAdi:"<<temp.getDersAdi()<<endl;
	cout<<"Ortalama:"<<temp.getOrtalama()<<endl;	
}

void Ara(Ogrenci ogr[]){
	
	string isim;
	cout<<"Aradiginiz ogrencinin ismini giriniz";cin>>isim;
	Ogrenci temp;
	
	for(int i=0;i<3;i++){
		if(ogr[i].getAd().compare(isim)==0){ //Aranan isimle birebir �rt��ecek adam laz�m. e�ittir s�f�r yani bire bir ayn�
			temp=ogr[i];			
		}
	}
		cout<<"TC:"<<temp.getTc()<<endl;
		cout<<"Ad:"<<temp.getAd()<<endl;
		cout<<"SoyAd"<<temp.getSoyad()<<endl;
		cout<<"Yas:"<<temp.getYas()<<endl;
		cout<<"DersAdi:"<<temp.getDersAdi()<<endl;
		cout<<"Ortalama:"<<temp.getOrtalama()<<endl;
}

int main(){
	
	string tc;
	string ad;
	string soyad;
	int yas;
	string DersAdi;
	int ortalama;
	Ogrenci ogr[3];

	
	
	for(int i=0;i<3;i++){
		
		cout<<i+1<<". ogrenci bilgilerini giriniz."<<endl;
		cout<<"TC:";cin>>tc;
		cout<<"Ad:";cin>>ad;
		cout<<"Soyad:";cin>>soyad;
		cout<<"Yas:";cin>>yas;
		cout<<"DersAdi:";cin>>DersAdi;
		cout<<"Ortalama:";cin>>ortalama;
		ogr[i].setTc(tc);
		ogr[i].setAd(ad);
		ogr[i].setSoyad(soyad);
		ogr[i].setYas(yas);
		ogr[i].setDersAdi(DersAdi);
		ogr[i].setOrtalama(ortalama);
	}
	ogr[0].listele(ogr);  //ogr'yi nesne dizisi olarak olu�turmu�tuk. Nesne ile �a��raca��m�z i�in ogr i�ine rasgele olarak 0 yazd�k
	cout<<"listeleme Tamamlanm��t�r."<<endl;
	Siralama(ogr); //class i�erisinde prototipi yok tamamen ba��ms�z bir fonksiyon �a��rmak i�in rastgele bir nesneye ihtiya� yok
	EnYuksekOrtalama(ogr);
	Ara(ogr);
	return 0;
}
