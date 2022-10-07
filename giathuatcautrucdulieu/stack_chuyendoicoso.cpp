#include<iostream>
using namespace std;

/*
Đổi 1 số nguyên sang cơ số 2 8 16

*/

// khai báo 1 cái node
struct node
{
	int data;
	struct node *pNext;
};
typedef struct node NODE;
// khai báo cấu trúc của 1 cái stack
struct stack
{
	NODE *pTop; // con trỏ quản lí đầu stack
};
typedef struct stack STACK;

// hàm khởi tạo stack
void KhoiTaoStack(STACK &s)
{
	s.pTop = NULL;
}

// hàm khởi tạo 1 cái node
NODE *KhoiTaoNode(int x)
{
	NODE *p = new NODE();
	if (p == NULL)
	{
		cout << "\nKhong du bo nho de cap phat !";
		return NULL;
	}
	p->data = x; // đưa dữ liệu của biến x vào trong cái data của node p
	p->pNext = NULL;
	return p;
}

/* ================= KIỂM TRA STACK RỖNG =================*/ 
bool IsEmpty(STACK s)
{
	// nếu stack rỗng
	if (s.pTop == NULL)
	{
		return false;
	}
	return true;
}

/* ================= THÊM PHẦN TỬ VÀO ĐẦU STACK =================*/
bool Push(STACK &s, NODE *p)
{
	// node p đang rỗng
	if (p == NULL)
	{
		return false;
	}

	// nếu danh sách rỗng
	if (IsEmpty(s) == false)
	{
		s.pTop = p;// node p cũng chính là node pTop <=>chính là node đầu stack
	}
	else
	{
		p->pNext = s.pTop; // B1: cho con trỏ của node p trỏ đến node pTop
		s.pTop = p;// cập nhật lại node đầu chính là node p
	}
	return true;// thêm thành công
}

/* ================= LẤY PHẦN TỬ ĐẦU DANH SÁCH VÀ HỦY NÓ ĐI ================= */
bool Pop(STACK &s, int &x) // x chính là giá trị cần lấy ra
{
	// nếu danh sách rỗng
	if (IsEmpty(s) == false)
	{
		return false; // lấy thất bại <=> danh sách đang rỗng
	}
	NODE *p = s.pTop; // gán node đầu danh sách vào node p <=> node p chính là node mà tí nữa ta sẽ xóa nó
	s.pTop = s.pTop->pNext; // cập nhật lại node đầu 
	x = p->data; // lấy giá trị của node đầu ra gán vào biến x
	return true; // lấy phần tử thành công
}

/* ================= XEM THÔNG TIN CỦA NODE ĐẦU DANH SÁCH ================= */
bool Top(STACK s, int &x) // x chính là giá trị cần xem
{
	// nếu danh sách rỗng

	if (IsEmpty(s) == false)
	{
		return false;
	}
	x = s.pTop->data;
	return true;
}

// HÀM ĐỔI CƠ SỐ 10 SANG CƠ SỐ 2 8 16
void Chuyen_So_So(STACK &s, int cosocandoi, int hethapphan)
{
	while (hethapphan != 0)
	{
		int x = hethapphan % cosocandoi;
		NODE *p = KhoiTaoNode(x); // thêm x vào node p
		Push(s, p); // thêm node p vào stack
		hethapphan /= cosocandoi;
	}
}

// xuất danh sách stack
void XuatStack(STACK &s)
{
	while (IsEmpty(s) == true)
	{
		int x;
		Pop(s, x);
		if (x < 10)
		{
			cout << x;
		}
		else
		{
			if (x == 10)
			{
				cout << "A";
			}
			else if (x == 11)
			{
				cout << "B";
			}
			else if (x == 12)
			{
				cout << "C";
			}
			else if (x == 13)
			{
				cout << "D";
			}
			else if (x == 14)
			{
				cout << "E";
			}
			else if (x == 15)
			{
				cout << "F";
			}
			
		}
	}
}



int main()
{
	STACK s;
	KhoiTaoStack(s);
	
	int hethapphan;
	cout << "\nNhap gia tri he thap phan(10) can chuyen: ";
	cin >> hethapphan;
	int cosocandoi;
	cout << "\nNhap co so can chuyen(2, 8, 16:  ";
	cin >> cosocandoi;

	Chuyen_So_So(s, cosocandoi, hethapphan);
	cout << "\nKET QUA\n";
	XuatStack(s);
	cout << endl;

	system("pause");
	return 0;
}