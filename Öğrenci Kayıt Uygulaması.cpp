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
		
		void listele(Ogrenci[]);    //Prototip olarak önce buraya yazdýk. listele metodu Ogrenci classýndan nesneler dizisi alacak.
	
	
	
};

void Ogrenci :: listele(Ogrenci ogr[]){		   //Ogrenci classýnýn içindeki listele metorundan Ogrenci calsýndan ogr sýnýflarý oluþtur.


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
				if(ogr[j].getAd().compare(ogr[j+1].getAd())>0){ //Ýsme Göre Karþýlaþtýracak Hangisini harfi daha aðýr diye yani daha büyük A dan Z ye deðer artýyor. soldaki saðdan-
					temp=ogr[j];                                   //- Küçük ise -1 büyük ise +1 veriyor
					ogr[j]=ogr[j+1];
					ogr[j+1]=temp;
				}
			}
	}
	cout<<"SIRALI HALÝ:"<<endl;
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
			temp=ogr[i];                         //Yüksek olan öðrenciyi tempe aktardýk heme altta da yüksek olan temp olduðu için tempi yazdýrdýk
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
		if(ogr[i].getAd().compare(isim)==0){ //Aranan isimle birebir örtüþecek adam lazým. eþittir sýfýr yani bire bir ayný
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
	ogr[0].listele(ogr);  //ogr'yi nesne dizisi olarak oluþturmuþtuk. Nesne ile çaðýracaðýmýz için ogr içine rasgele olarak 0 yazdýk
	cout<<"listeleme Tamamlanmýþtýr."<<endl;
	Siralama(ogr); //class içerisinde prototipi yok tamamen baðýmsýz bir fonksiyon çaðýrmak için rastgele bir nesneye ihtiyaç yok
	EnYuksekOrtalama(ogr);
	Ara(ogr);
	return 0;
}
