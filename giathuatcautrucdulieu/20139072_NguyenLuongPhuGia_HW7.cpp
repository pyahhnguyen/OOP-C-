#include<iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

struct sinhvien {
	char MSSV[50];
	char Name[50];
	char Date_of_bird[20];//"dd mm yyyy"
	char Noisinh[50];
	char Gt[5];
	double Toan;
	double Ly;
	double Hoa;
    double Dtb;
    char XL;
};
//ham nhap thon tin sinh vien

void XuatSinhVien(sinhvien x)
{
	cout << "=================================" << endl;
	cout << setw(10) << left << "MSSV";		
	cout << setw(50) << left << "Name";	
	cout << setw(20) << left << "DOB" ;	
	cout << setw(10) << left << "Sex";		
	cout << setw(10) << left << "Toan";	
	cout << setw(10) << left << "Ly" ;
	cout << setw(10) << left << "Hoa";	
	cout << setw(20) << left << "Xeploai"<<endl ;
	cout << setfill('-');		
	cout << setw(130) << "-" << endl;	
	cout << setfill(' ');
	cout << setw(10) << left << x.MSSV;		
	cout << setw(50) << left << x.Name;	
	cout << setw(20) << left << x.Date_of_bird ;	
	cout << setw(10) << left << x.Gt;		
	cout << setw(10) << left << x.Toan;	
	cout << setw(10) << left << x.Ly ;
	cout << setw(10) << left << x.Hoa;	
	cout << setw(20) << left << x.XL<<endl ;

}



void calculate(sinhvien x)
{
	x.Dtb=(x.Toan + x.Ly + x.Hoa)/3.0;
	if(x.Dtb>=9.0)
		x.XL ='A+ ';
	else if(x.Dtb>=8.0)
		x.XL='A';
	else if(x.Dtb>=7.5)
		x.XL='A-';
	else if(x.Dtb>=7.0)
		x.XL='B+';
    else if(x.Dtb>=6.5)
		x.XL='B';
	else if(x.Dtb>=6.0)
		x.XL='B-';
	else if(x.Dtb>=5.5)
		x.XL='C+';
	else if(x.Dtb>=50)
		x.XL='C';
	else
		x.XL='F';
}
 

struct tNode{
	sinhvien sv2013972;
	tNode *pLeft, *pRight;
};
typedef struct tNode tNode;
typedef tNode* TREE;


int compare(sinhvien x, sinhvien y)
{
	return strcmp(x.MSSV, y.MSSV);
}

//create empty tree
void createEmptyTree(TREE &t){
	t = NULL;
}

//create new node

	

void insertNode(TREE &t, sinhvien x)
{
	// nếu cây rỗng
	if (t == NULL)
	{
		tNode *p = new tNode; 
		p-> sv2013972 = x;
		p->pLeft = NULL;
		p->pRight = NULL;
		t = p;
	}
	else 
 	{
		
		if (compare(t->sv2013972 , x) > 0) 
		{
			insertNode(t->pLeft, x); 
		}
		else if (compare(t->sv2013972 ,x) < 0 ) 
		{
			insertNode(t->pRight, x); 
		}
	}
}
tNode* TimKiem(TREE t, sinhvien x)
{ 
	
	if (t == NULL)
	{
		return NULL;
	}
	else
	{
		if (compare(t->sv2013972 , x) > 0)
		{
			TimKiem(t->pLeft, x);
		}
		else if (compare(t->sv2013972 ,x) < 0)
		{
			TimKiem(t->pRight, x);
		}
		else 
		{
			return t; 
		}
	}

}
void XoaNode(TREE &t, sinhvien data) 
{
	if (t == NULL)
	{
		return; // k?t thúc hàm
	}

	else
	{
		if (compare(t->sv2013972 , data) > 0)
		{
			XoaNode(t->pLeft, data);
		}
		else if (compare(t->sv2013972 ,data) < 0)
		{
			XoaNode(t->pRight, data); 
		}
		else 
		{
			tNode *X = t; 
			if (t->pLeft == NULL)
			{
				t = t->pRight; 
			}
			else if (t->pRight == NULL)
			{
			
				t = t->pLeft;
			}
			
			delete X; 
		}
	}
}
istream& operator >> ( istream& filein, sinhvien x )
{
  filein >> x.MSSV;
   filein >> x.Name;
    filein >> x.Date_of_bird;
	 filein >> x.Noisinh;
	  filein >> x.Gt;
	   filein >> x.Toan;
	    filein >> x.Ly;
		 filein >> x.Hoa;
		  filein >> x.XL;

  return filein;
}

void Doc_File(TREE &t, ifstream &filein)
{
	int n;
	filein >> n;
	for (int i = 1; i <= n; i++)
	{
		sinhvien x;
		filein >>  x;
		insertNode(t, x);
	}
}
void Doc_File_1(TREE &t, ifstream &filein)
{
	while (true)
	{
		sinhvien  x;
		filein >> x;
		insertNode(t, x);
		char c;
		filein >> c;
		if (filein.eof() == true)
		{
			break;
		}
	}
}

void Duyet_NLR(TREE t)
{ 
	
	if (t != NULL)
	{
		XuatSinhVien(t->sv2013972);
		Duyet_NLR(t->pLeft); 
		Duyet_NLR(t->pRight); 
	}
}
void Menu(TREE &t)
{
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t =========== MENU ===========";
		cout << "\n1. Nhap du lieu";
		cout << "\n2. Xuat du lieu cay NLR";
		cout << "\n3.Tim kiem ";
		cout << "\n4.Xoa phan tu";
		cout<< "\n5.Doc file :";
		cout << "\n0. Ket thuc";
		cout << "\n\n\t\t ============================";

		int luachon;

		cout << "\nNhap lua chon: ";
		cin >> luachon;
		if (luachon < 0 || luachon > 4)
		{
			cout << "\nLua chon khong hop le";
			system("pause");
		}
		else if (luachon == 1)
		{
			sinhvien x;
			cout<<"Nhap ma so sinh vien:   \n";
			cin.ignore();
			cin.getline(x.MSSV,50);
			cout<<"Nhap ten sinh vien:    \n";
			cin.ignore();
			cin.getline(x.Name,50);
			cout<<"Nhap vao ngay sinh:  \n";
			cin.ignore();
			cin.getline(x.Date_of_bird,20);
			cout<<"Nhap vao noi sinh:  \n";
			cin.ignore();
			cin.getline(x.Noisinh,50);
			cout<<"Nhap vao gioi tinh:  \n";
			cin.ignore();
			cin.getline(x.Gt,5);
			cout << "Nhap vao diem toan:  \n";
			cin>>x.Toan;
			cout<< "Nhap vao diem ly:     \n";
			cin>>x.Ly;
			cout<< "Nhap vao diem hoa:    \n";
			cin>>x.Hoa;
			calculate(x);
		    /* 
			ofstream outFile;
			outFile.open("SVList.txt");
			outFile.write(reinterpret_cast<char *> (&x), sizeof(sinhvien));
			outFile.close();
        */
		    insertNode(t, x);
		}
		else if (luachon == 2)
		{
			cout << "\n\t\t DUYET CAY THEO NLR\n";
			Duyet_NLR(t);
			system("pause");
		}
		
		else if(luachon == 3)
		{
			sinhvien x;
            cout<< "\nTim kiem phan tu tim kiem: ";
			
			tNode *p = TimKiem(t, x);
			
			system("pause");

		}

        else if(luachon == 4)
		{
			sinhvien x;
			XoaNode(t, x);
		}
		else
		{
			break;
		}
	}
	
}


int main()
{
	
	sinhvien x;
	ifstream filein;
	TREE t;
	createEmptyTree(t);
	
	filein.open("DSsinhvien.txt", ios_base::in);
	Doc_File_1(t, filein);
	
	/*
	ifstream filein;
	filein.open("INPUT.TXT", ios_base::in);
	Doc_File(t, filein);*/
	

	Menu(t);
	system("pause");
	return 0;
	
}