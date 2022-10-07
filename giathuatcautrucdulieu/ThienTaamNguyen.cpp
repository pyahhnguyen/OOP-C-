#include<iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;

struct sinhvien {
	char Masv[50];
    char Ten[100];

	float Toan;
	float Ly;
	float Hoa;
};


sinhvien Nhapsv()
{
	sinhvien x;
	cin.ignore();
	cout<<" Nhap ma sinh vien ";
    gets(x.Masv);
	cout << "Nhap Ten Sinh Vien: ";
    gets(x.Ten);
	cout << "Nhap Diem Toan: ";
	while (true)
	{
		cin >> x.Toan;
		if (cin.fail() || x.Toan>10||x.Toan<0)
		{
			cin.clear();
			_flushall();
			cin.ignore();
			cout << "Nhap Lai Diem Toan: ";

		}
		else
			break;
	}
	cout << "Nhap Diem Ly: ";
	while (true)
	{
		cin >> x.Ly;
		if (cin.fail() || x.Ly>10||x.Ly<0)
		{
			cin.clear();
			_flushall();
			cin.ignore();
			cout << "Nhap Lai Diem Ly: ";

		}
		else
			break;
	}
	cout << "Nhap Diem Hoa: ";
	while (true)
	{
		cin >> x.Hoa;
		if (cin.fail() || x.Hoa>10||x.Hoa<0)
		{
			cin.clear();
			_flushall();
			cin.ignore();
			cout << "Nhap Lai Diem Hoa: ";

		}
		else
			break;
	}


	while (getchar() != '\n');/////////////////

	return x;
}


void XuatSinhVien(sinhvien x)
{
	cout << "=================================" << endl;
	cout << "Ma So Sinh Vien: " << x.Masv << "\n";
	cout << "Ten Sinh Vien: " << x.Ten << "\n";
	cout << "Diem Toan: " << x.Toan << "\n";
	cout << "Diem Ly: " << x.Ly << "\n";
	cout << "Diem Hoa: " << x.Hoa << "\n";
}

// đề bài: Nhập vào cây nhị phân các số nguyên. Xuất ra màn hình các phần tử của cây nhị phân
// khai báo cấu trúc  1 cái node
struct node
{
	sinhvien sv20139072; // dữ liệu của node ==> dữ liệu mà node sẽ lưu trữ
	struct node *pLeft; // node liên kết bên trái của cây <=> cây con trái
	struct node *pRight; // node liên kết bên phải của cây <=> cây con phải
};
typedef struct node NODE;
typedef NODE* TREE;
int compare(sinhvien x, sinhvien y)
{
	return strcmp(x.Masv, y.Masv);
}
// khởi tạo cây
void KhoiTaoCay(TREE &t)
{
	t = NULL; // cây rỗng
}

// hàm thêm phần tử x vào cây nhị phân
void ThemNodeVaoCay(TREE &t, sinhvien x)
{
	// nếu cây rỗng
	if (t == NULL)
	{
		NODE *p = new NODE; // khởi tạo 1 cái node để thêm vào cây
		p->sv20139072 = x;// thêm dữ liệu x vào data
		p->pLeft = NULL;
		p->pRight = NULL;
		t = p;// node p chính là node gốc <=> x chính là node gốc
	}
	else // cây có tồn tại phần tử
 	{
		// nếu phần tử thêm vào mà nhỏ hơn node gốc ==> thêm nó vào bên trái
		if (compare(t->sv20139072 , x) > 0) 
		{
			ThemNodeVaoCay(t->pLeft, x); // duyệt qua trái để thêm phần tử x
		}
		else if (compare(t->sv20139072 ,x) < 0 ) // nếu phần tử thêm vào mà lớn hơn node gốc ==> thêm nó vào bên phải
		{
			ThemNodeVaoCay(t->pRight, x); // duyệt qua phải để thêm phần tử x
		}
	}
}


// hàm xuất cây nhị phân theo NLR
void Duyet_NLR(TREE t)
{ 
	// nếu cây còn phần tử thì tiếp tục duyệt
	if (t != NULL)
	{
		XuatSinhVien(t-> sv20139072);
		Duyet_NLR(t->pLeft); // duyệt qua trái
		Duyet_NLR(t->pRight); // duyệt qua phải
	}
}
// hàm nhập dữ liệu
void Menu(TREE &t,sinhvien x)
{
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t =========== MENU ===========";
		cout << "\n1. Nhap du lieu";
		cout << "\n2. Xuat du lieu cay NLR";
		cout << "\n0. Ket thuc";
		cout << "\n\n\t\t ============================";

		int luachon;

		cout << "\nNhap lua chon: ";
		cin >> luachon;
		if (luachon < 0 || luachon > 2)
		{
			cout << "\nLua chon khong hop le";
			system("pause");
		}
		else if (luachon == 1)
		{
		
            Nhapsv();
		
			ThemNodeVaoCay(t,x);
		}
		else if (luachon == 2)
		{
			sinhvien x;
			cout << "\n\t\t DUYET CAY THEO NLR\n";
			
			Duyet_NLR(t);
			cout << "=================================" << endl;
			cout << "Ma So Sinh Vien: " << x.Masv << "\n";
			cout << "Ten Sinh Vien: " << x.Ten << "\n";
			cout << "Diem Toan: " << x.Toan << "\n";
			cout << "Diem Ly: " << x.Ly << "\n";
			cout << "Diem Hoa: " << x.Hoa << "\n";
			system("pause");
		}
		else
		{
			break;
		}
	}
	
}

int main()
{
	TREE t;
	sinhvien x;
	KhoiTaoCay(t);
	Menu(t,x);
	system("pause");
	return 0;
}