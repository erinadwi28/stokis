#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<windows.h>
#include<cstdlib>

using namespace std;

struct item {
	string nama_brg[50];
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
		cout<<"\nMasukkan kode barang\t: "<<itm.kode_brg[i];
    	cout<<"\nMasukkan nama barang\t: "<<itm.nama_brg[i];
    	cout<<"\nMasukkan stok barang\t: "<<itm.stok[i]<<endl<<endl;
        j++;
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
      	cout<<"\n5: Urutkan data barang sesuai abjad";
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
          		cout<<"cari";
          		break;
        	}
           	case 5:
        	{
          		cout<<"urutkan";
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
