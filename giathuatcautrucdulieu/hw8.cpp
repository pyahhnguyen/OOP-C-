#include<iostream>
using namespace std;


struct node
{
	int data; // d? li?u c?a node ==> d? li?u mà node s? luu tr?
	struct node *pLeft; // node liên k?t bên trái c?a cây <=> cây con trái
	struct node *pRight; // node liên k?t bên ph?i c?a cây <=> cây con ph?i
};
typedef struct node NODE;
typedef NODE* TREE;

// kh?i t?o cây
void KhoiTaoCay(TREE &t)
{
	t = NULL; // cây r?ng
}

// hàm thêm ph?n t? x vào cây nh? phân
void ThemNodeVaoCay(TREE &t, int x)
{
	// n?u cây r?ng
	if (t == NULL)
	{
		NODE *p = new NODE; // kh?i t?o 1 cái node d? thêm vào cây
		p->data = x;// thêm d? li?u x vào data
		p->pLeft = NULL;
		p->pRight = NULL;
		t = p;// node p chính là node g?c <=> x chính là node g?c
	}
	else // cây có t?n t?i ph?n t?
 	{
		// n?u ph?n t? thêm vào mà nh? hon node g?c ==> thêm nó vào bên trái
		if (t->data > x)
		{
			ThemNodeVaoCay(t->pLeft, x); // duy?t qua trái d? thêm ph?n t? x
		}
		else if (t->data < x) // n?u ph?n t? thêm vào mà l?n hon node g?c ==> thêm nó vào bên ph?i
		{
			ThemNodeVaoCay(t->pRight, x); // duy?t qua ph?i d? thêm ph?n t? x
		}
	}
}

// hàm xu?t cây nh? phân theo NLR
void Duyet_NLR(TREE t)
{ 
	// n?u cây còn ph?n t? thì ti?p t?c duy?t
	if (t != NULL)
	{
		cout << t->data << " "; // xu?t d? li?u trong node
		Duyet_NLR(t->pLeft); // duy?t qua trái
		Duyet_NLR(t->pRight); // duy?t qua ph?i
	}
}
NODE* TimKiem(TREE t, int x)
{ 
	// n?u cây r?ng
	if (t == NULL)
	{
		return NULL;
	}
	else
	{
		// n?u ph?n t? c?n tìm ki?m mà nh? hon node g?c thì duy?t(d? quy) sang bên trái d? tìm
		if (x < t->data)
		{
			TimKiem(t->pLeft, x);
		}
		else if (x > t->data) // duy?t sang bên ph?i
		{
			TimKiem(t->pRight, x);
		}
		else // <=> t->data == x
		{
			return t; // tr? v? node c?n tìm ki?m
		}
	}

}
void XoaNode(TREE &t, int data) // data chính là giá tr? c?a cái node c?n xóa
{
	// n?u nhu cây dang r?ng
	if (t == NULL)
	{
		return; // k?t thúc hàm
	}
	else
	{
		// n?u nhu data nh? hon node g?c
		if (data < t->data)
		{
			XoaNode(t->pLeft, data); // duy?t sang nhánh trái c?a cây 
		}
		else if (data > t->data)
		{
			XoaNode(t->pRight, data); // duy?t sang nhánh ph?i c?a cây 
		}
		else // data == t->data - dã tìm ra cái node c?n xóa
		{
			NODE *X = t; // node X là node th? m?ng - tí n?a chúng ta s? xóa nó
			// n?u nhu nhánh trái b?ng NULL <=> dây là cây có 1 con chính là con ph?i
			if (t->pLeft == NULL)
			{
				// duy?t sang ph?i c?a cái node c?n xóa d? c?p nh?t m?i liên k?t gi?a node 
				// cha c?a node c?n xóa v?i node con c?a node c?n xóa
				t = t->pRight; 
			}
			else if (t->pRight == NULL)
			{
				// duy?t sang trái c?a cái node c?n xóa d? c?p nh?t m?i liên k?t gi?a node 
				// cha c?a node c?n xóa v?i node con c?a node c?n xóa
				t = t->pLeft;
			}
			
			delete X; // xóa node c?n xóa
		}
	}
}

// hàm nh?p d? li?u
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
			int x;
			cout << "\nNhap so nguyen x: ";
			cin >> x;
			ThemNodeVaoCay(t, x);
		}
		else if (luachon == 2)
		{
			cout << "\n\t\t DUYET CAY THEO NLR\n";
			Duyet_NLR(t);
			system("pause");
		}
		
		else if(luachon == 3)
		{
			int x;
            cout<< "\nTim kiem phan tu tim kiem: ";
			cin>>x;
			NODE *p = TimKiem(t, x);
			if (p == NULL)
			{
				cout << "\nPhan tu " << x << " khong ton tai trong cay";
			}
			else
			{
				cout << "\nPhan tu " << x << " co ton tai trong cay";
			}
			system("pause");

		}

        else if(luachon == 4)
		{
			int x;
			cout << "\nNhap gia tri can xoa: ";
			cin >> x;
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
	TREE t;
	KhoiTaoCay(t);
	Menu(t);

	system("pause");
	return 0;
}
