#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<windows.h>
#include<cstdlib>
#include <string.h>

using namespace std;

struct item {
	char nama_brg[50][50];
	string kode_brg[20];
	int stok[20];
}itm;

int z;

//sampai di fitur tambah ini
void tambah(){
	system("cls");
	int pilih, jml_tambah;
	string kode;
	int total_stok=0;
	
	cout<<"1. Tambah barang baru";
	cout<<"\n2. Isi stok barang lama";
	cout<<"\n\nPilih nomor\t: ";
	cin>>pilih;
	
	switch(pilih){
	case 1:
		cout<<"\nMasukkan kode barang\t: ";
    	cin>>itm.kode_brg[z];
    	cout<<"Masukkan nama barang\t: ";
    	cin>>itm.nama_brg[z];
    	cout<<"Masukkan stok barang\t: ";
    	cin>>itm.stok[z];
    	z++;
    	break;
	
	case 2:
		cout<<"\nMasukkan kode barang\t: ";
    	cin>>kode;
    	
    	for(int j=0;j<z;j++)
    	{
    		if (itm.kode_brg[j]==kode)
      		{
        		cout<<"\nNama barang\t\t: "<<itm.nama_brg[j];
        		cout<<"\nStok barang saat ini\t: "<<itm.stok[j];
        		cout<<"\n\nJumlah barang yang ingin ditambahkan\t:";
        		cin>>jml_tambah;
        		total_stok+=itm.stok[j];
        		itm.stok[j] = total_stok + jml_tambah;
        		cout<<"\nPenambahan stok berhasil";
        		getch();
      		} 
			else 
			{
				cout<<"Kode yang Anda masukkan salah";
				getch();
			}
    	}
    	break;
    	
	default : 
	cout<<"\nPilihan tidak ada\nMasukan pilihan sesuai dengan daftar"<<endl;
	getch();
    break;
	}
}

void ambil(){
	char a;
	string i;
	int j;
	int jml_ambil;
	int total_stok=0;
	system("cls");
	
	cout<<"\nMasukkan kode barang\t: ";
    cin>>i;
    for(j=0;j<z;j++)
    {
    	if (itm.kode_brg[j]==i)
      	{
        	if(itm.stok[j]==0)
        	{
          		cout<<"\nMaaf barang kosong.";
          		cout<<"\nApakah mau ambil barang yang lain? y\\n"<<endl;
          		cin>>a;
          		if (a=='y')
          		{
        			cout<<"\nMasukkan kode barang\t: ";
        			cin>>i;
        			j=-1;
          		}
          		else if (a=='Y')
          		{
        			cout<<"\nMasukkan kode barang:";
        			cin>>i;
        			j=-1;
          		}
          		else
          		{
        			if (total_stok!=0)
        			{
          				cout<<"\nStok barang yang ada\t: ";
          				cout<<total_stok<<"item"<<"\nTerimakasih :) .";
        			}
        			break;
        		}
        	}
        	else
        	{
        		cout<<"\nNama barang\t\t: "<<itm.nama_brg[j];
        		cout<<"\nStok barang saat ini\t: "<<itm.stok[j];
        		cout<<"\n\nJumlah barang yang ingin di ambil\t:";
        		cin>>jml_ambil;
        		total_stok+=itm.stok[j];
        		itm.stok[j] = total_stok - jml_ambil;
        		cout<<"\nApakah mau ambil barang yang lain? y\\n"<<endl;
        		cin>>a;
        		if (a=='y')
        		{
        			cout<<"\nMasukkan kode barang\t: ";
        			cin>>i;
        			j=-1;
          		}
        		else if (a=='Y')
        		{
        			cout<<"\nMasukkan kode barang\t: ";
        			cin>>i;
        			j=-1;
          		}
          		else
          		{  
			  		system("cls");
			  		cout<<"Pegambilan Barang Berhasil\n";
        			cout<<"\nStok barang "<<itm.nama_brg[j]<<" saat ini adalah "<<itm.stok[j];
        			cout<<"\nTerimakasih :)";
        			break;
          		}
        	}
      	}
    }
    getch();
}

void tampil()
{
    int i, j=1;
    system("cls");

       for(i=0;i<z;i++)
      {
		  cout<<"\nKode barang\t: "<<itm.kode_brg[i];
    	cout<<"\nNama barang\t: "<<itm.nama_brg[i];
    	cout<<"\nStok barang\t: "<<itm.stok[i]<<endl<<endl;
        j++;
       }
        getch();
      }

void cari(){
    int a, i, j,count;
    string cari;
    cout<<"Masukkan nama barang yang dicari: ";
    cin>>cari;

     //count+=z;
    for(i=0;i<z;i++)
      if(itm.nama_brg[i] == cari){
		 cout<<"Data ditemukan"<<endl;
		 cout<<"\nDetail barang:";
		 cout<<"\nKode barang\t: "<<itm.kode_brg[i];
       	cout<<"\nNama barang\t: "<<itm.nama_brg[i];
    	cout<<"\nStok barang\t: "<<itm.stok[i]<<endl<<endl;
      }
    getch();
  }

void urut(){
  	int i,j;
	char temp[20];
		
		cout<<"Sebelum Urut: "; 
		tampil();
		
		 cout<<"Data sblm urut:"<<z<<endl;
		 for (i=0;i<z;i++){
		 	cout<<i+1<<"."<<itm.nama_brg[i]<<endl;
		 }
		cout<<"\nData diurutkan secara Ascending"<<endl;
		for(i=1; i<z; i++)
		{
			for(j=1; j<z; j++)
			{
				if(strcmp(itm.nama_brg[j-1], itm.nama_brg[j])>0)
				{
					strcpy(temp, itm.nama_brg[j-1]);
					strcpy(itm.nama_brg[j-1], itm.nama_brg[j]);
					strcpy(itm.nama_brg[j], temp);
				}
			}
		}
		cout<<"No."<<"\tNama"<<"\t\tStok"<<"\t\tKode"<<endl;
		for(i=0; i<z; i++)
		{
			cout<<i+1<<".| "<< itm.nama_brg[i] <<"\t|\t"<<itm.stok[i]<<"\t|\t"<<itm.kode_brg[i]<<endl;
		}
		
		cout<<"\nData diurutkan secara Descending"<<endl;
		for(i=1; i<z; i++)
		{
			for(j=1; j<z; j++)
			{
				if(strcmp(itm.nama_brg[j-1], itm.nama_brg[j])<0)
				{
					strcpy(temp, itm.nama_brg[j-1]);
					strcpy(itm.nama_brg[j-1], itm.nama_brg[j]);
					strcpy(itm.nama_brg[j], temp);
				}
			}
		}
		cout<<"No."<<"\tNama"<<"\t\tStok"<<"\t\tKode"<<endl;
		for(i=0; i<z; i++)
		{
			cout <<i+1<<".| "<< itm.nama_brg[i]<<"\t|\t"<<itm.stok[i]<<"\t|\t"<<itm.kode_brg[i]<<endl;
		}	
		getch();
 }
   
   
int main (){
    int i;
    system("cls");

    while(1)
    {
      cout<<"\nSelamat Datang di Stokis"<<endl;
      cout<<"\n1: Tambah data barang";
      cout<<"\n2: Tampil data barang";
      cout<<"\n3: Ambil barang";
      cout<<"\n4: Cari data barang";
      cout<<"\n5: Urutkan data barang";
      cout<<"\n6: Keluar"<<endl;
      cout<<"\n\n Pilih nomor\t: ";
      cin>>i;

      switch(i)
      {
        case 1:
        {
          tambah();
          break;
        }
        case 2:
        {
          tampil();
          break;
        }
        case 3:
        {
          ambil();
          break;
        }
        case 4:
        {
          cari();
          break;
        }

           case 5:
        {
          urut();
          break;
        }
         case 6:
        {
      	exit(0);
          break;
        }
      }
      if (i==6)
        break;
      	system("cls");
    }
    getch();
    return 0;
}
