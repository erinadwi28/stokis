#include<iostream>
#include<conio.h>
#include<windows.h>
#include<cstdlib>
#include <stdio.h>
#include <string.h>

using namespace std;

struct item {
	char nama_brg[50][50];
	char kode_brg[20];
	int stok[20];
}itm;

int z;
	
void tambah(){
	  cout<<"\nMasukkan kode barang\t: ";
    cin>>itm.kode_brg[z];
    cout<<"Masukkan nama barang\t: ";
    cin>>itm.nama_brg[z];
    cout<<"Masukkan stok barang\t: ";
    cin>>itm.stok[z];
    z++;
}

void ambil(){
	char a;
	int i,j;
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
        cout<<"Bye...bye...";
        break;
          }
        }
        else
        {
          cout<<"Nama barang\t: "<<itm.nama_brg[j];
          cout<<"\nStok barang\t: "<<itm.stok[j]<<"item"<<endl;
          total_stok+=itm.stok[j];
          itm.stok[j]=0;
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
          {  system("cls");
        cout<<"\nStok barang\t: ";
        cout<<total_stok<<"item."<<"\nTerimakasih.";
        break;
          }
        }
      }
    }
    getch();
}

 void tampil()
     {
       int i,j=1;
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
		 cout<<"Data ditemukan"<<z;	 
      }
    getch();
  }

  void urut(){
  	int jml, pilih, x, y, a, m, n;
	char temp[40];
		
		cout<<"Sebelum Urut: "; tampil();
			if (z>1){
				for (y=1; y<=(z-1); y++){
					a=(strcmp(itm.nama_brg[z], itm.nama_brg[y]));
					if (a<=0){
						strcpy (temp, itm.nama_brg[z]);
						for (n=(z-1); n>=y; n--){
							m=(n+1);
							strcpy (itm.nama_brg[m], itm.nama_brg[n]);
						}
						strcpy(itm.nama_brg[y], temp);
					}
				}
			}
		cout<<"\nSetelah diurutkan dengan Metode Ascending: "<<endl;
		for (x=0; x<z; x++){
			cout<<x<<". "<<itm.nama_brg[x];
			cout<<endl;
		}
		cout<<endl;
		
		getch();
 }
      
int main ()

   {
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
