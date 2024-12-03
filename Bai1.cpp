#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <iomanip>

using namespace std;

struct NV
{
	char MaNV[10];
	char HoTen[30];
	char SDT[20];
	int Luong;
	

};
int Menu()
{
	int chon;
	cout<<"\t --------------MENU----------------\n";
	cout<<"\t 0. Thoat \n";
	cout<<"\t 1. Doc danh sach nhan vien \n";
	cout<<"\t 2. Xuat danh sach nhan vien \n";
	cout<<"\t 3. Tim nhan vien co ma nhan vien \n";
	cout<<"\t 4. Sap xep danh sach nhan vien tang dan theo luong \n";
	cout<<"\t 5. Sap xep danh sach nhan vien giam dan theo luong, neu cung luong thi tang theo ho ten \n";
	cout<<"\t -------------------------------- \n";
	cout<<"\t MOI BAN CHON ";
	cin>>chon;
	cout<<"   \n";
	return chon;
}
void DocDSNV(NV a[], int &n)
{
	int igr;
	FILE *f =fopen("DSNV.txt", "r");
	fscanf(f,"%d",&n);
	for(int i=0;i<n;i++)
	{
		fscanf(f,"%d",&igr);
		fgets(a[i].MaNV,10,f);
		a[i].MaNV[strlen(a[i].MaNV)-1]='\0';
		fgets(a[i].HoTen,30,f);
		a[i].HoTen[strlen(a[i].HoTen)-1]='\0';
		fgets(a[i].SDT,20,f);
		a[i].SDT[strlen(a[i].SDT)-1]='\0';
		fscanf(f,"%d",&a[i].Luong);		
	}
}
void XuatMang(NV a[], int n)
{
	int stt=1;
	cout<<setw(5)<<"STT"<<setw(10)<<"MaNV"<<setw(20)<<"HoTen"<<setw(15)<<"Luong"<<setw(15)<<"SDT \n";
	cout<<"----------------------------------------------------------------------------------------------------------------\n";
	for(int i=0;i<n;i++)
	cout<<setw(5)<<stt++<<setw(10)<<a[i].MaNV<<setw(20)<<a[i].HoTen<<setw(15)<<a[i].Luong<<setw(15)<<a[i].SDT<<endl;
}
void TimKiem(NV a[], int n)
{
	char MaNV[10];
	int TimNV=0;
	int stt=1;
	cout<<"Nhap ma so nhan vien can tim: ";
	cin>>MaNV;
	cout<<"   \n";
	for(int i=0;i<n;i++)
	{
		if(strcmp(MaNV, a[i].MaNV)==0)
			{
				cout<<setw(5)<<"STT"<<setw(10)<<"MaNV"<<setw(20)<<"HoTen"<<setw(15)<<"Luong"<<setw(15)<<"SDT \n";
				cout<<"----------------------------------------------------------------------------------------------------------------\n";
				cout<<setw(5)<<stt++<<setw(10)<<a[i].MaNV<<setw(20)<<a[i].HoTen<<setw(15)<<a[i].Luong<<setw(15)<<a[i].SDT<<endl;
				TimNV=1;
			}
	}if(TimNV==0)
		{
			cout<<"Khong co nhan vien nao co ma nhan vien nay!!! ";
		}
}
void SapxepNV_TangTheoLuong(NV a[],int n)
{
	for(int i=0;i<n-1;i++)
	for(int j=i+1;j<n;j++)
	if(a[i].Luong>a[j].Luong)
	swap(a[i],a[j]);
}
void SapxepNV_GiamTheoLuong_TangTheoTen(NV a[],int n)
{
	for(int i=0;i<n-1;i++)
	for(int j=i+1;j<n;j++)
		if(a[i].Luong<a[j].Luong)
		swap(a[i],a[j]);
			else if(a[i].Luong<a[j].Luong && a[i].HoTen>a[j].HoTen)
			swap(a[i],a[j]);
}
int main()
{
	int chon,n;
	NV a[100];
	do{
		chon=Menu();
		 if(chon==1)
		{
			DocDSNV(a,n);
		}
		else if(chon==2)
		{
			XuatMang(a,n);
		}
		else if(chon==3)
		{
			TimKiem(a,n);
		}
		else if(chon==4)
		{
			cout<<"Luong sau khi duoc sap xep tang dan: \n";
			SapxepNV_TangTheoLuong(a,n);
			XuatMang(a,n);
		}
		else if(chon==5)
		{
			cout<<"Luong sau khi duoc sap xep giam dan neu cung luong thi tang theo ten : \n";
			SapxepNV_GiamTheoLuong_TangTheoTen(a,n);
			XuatMang(a,n);
		}
		
	}while(chon!=0);
	return 0;
}
