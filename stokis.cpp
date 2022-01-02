//STOKIS

#include<iostream>
#include<conio.h>
#include<windows.h>
#include<cstdlib>
#include<stdio.h>
#include <string.h>

using namespace std;

struct item {
	string nama_brg[50];
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
		cout<<"\nMasukkan kode barang\t: "<<itm.kode_brg[i];
    	cout<<"\nMasukkan nama barang\t: "<<itm.nama_brg[i];
    	cout<<"\nMasukkan stok barang\t: "<<itm.stok[i]<<endl<<endl;
        j++;
       }
        getch();
      }
      
void urut(){

	int y, x, a, n, m;
	string temp[40];
		if (z>1){
				for (y=1; y<=(z-1); y++){
					a=(strcmp(itm.nama_brg[z], itm.nama_brg[y]));
					if (a<=0){
						strcpy (temp, itm.nama_brg[x]);
						for (n=(z-1); n>=y; n--){
							m=(n+1);
							strcpy (itm.nama_brg[m], itm.nama_brg[n]);
						}
						strcpy(itm.nama_brg[y], temp);
					}
				}
			}
		}
		cout<<"\nSetelah diurutkan dengan Metode Ascending: "<<endl;
		for (z=1; z<=jml; z++){
			cout<<x<<". "<<itm.nama_brg[z];
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
          cout<<"cari";
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
