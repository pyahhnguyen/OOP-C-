
/*
#include<iostream>
using namespace std;



// Khai bao mot node
struct Node{
    int data;
    struct Node *pNext; /// con tro lien ket cac node voi nhau 
};
typedef struct Node NODE; // thay the struct Node bang NODE

// Khai bao cau truc danh sach  lien ket don 

struct list
{
    NODE *pHead;
    NODE *pTail;
};
typedef struct list LIST; 

void KhoiTao(LIST &l)
{
l.pHead = NULL;
l.pTail = NULL;
}

///Ham khoi tao mot Node
// NODE *  la mot con tro 
NODE *KhoiTaoNODE(int x)// x la data con tro
{
NODE *p = new NODE; //cap phat  vung nho cho NODE p
if (p ==  NULL){
    cout<<"\n Khong du bo nho de cap phat";
    return NULL;
}
p->data = x;
p->pNext = NULL;
return p;
}

// Ham them Node vao dau danh sach lien ket
void AddFirst(LIST &l, NODE *p)
{
    if(l.pHead = NULL)// Danhsach dang rong 
    {
       l.pHead= l.pTail=p;

    }
    else{
          p->pNext = l.pHead;// cho com tor cua node can them lien ket den node dau 
        l.pHead = p;// cap nhat laij phead chinh la node p
    }
} //NODE *p la node chuan bi duoc them vao 
void AddLast(LIST &l, NODE *p)
{
     if(l.pHead = NULL)// Danhsach dang rong 
    {
       l.pHead= l.pTail=p;

    }
    else{
        l.pTail -> pNext=p ;// cho com tro cua pTail lien let voi node p
        l.pTail = p;// cap nhat laij pTail chinh la node p
    }
}

void Duyet(LIST l) // khong an & vi khong can luu lai chi in ra thoi
{
    // for(int i=0; i<n; i++)
 for(NODE *k= l.pHead; k!= NULL; k = k->pNext)
 {
    cout << k->data << " ";
 }
}

int TimMAX(LIST l)
{
    int max = l.pHead-> data;// cho phan tu dau list max
    // bat dau duyet tu thang thu 2 de kiem tra
    for(NODE *k = l.pHead->pNext; k!=NULL; k= k->pNext)
        {
           if(max < k->data){
               max = k->data;
           }
        }
return max;
}


int main()
{
LIST l;
KhoiTao(l);// goi lai khoi tao danh sach
int n;
cout<<" \nnhap so luong node can them:";
cin>>n;
for(int i=1; i<=n;i++){
    int x;
    cout<<"\nNhap gia tri x so nguyen:";
    cin>>x;
    NODE *p = KhoiTaoNODE(x);
    AddLast(l, p);
}
cout<<"\n\n\t DANH SACH LIEN KET DON \n";

Duyet(l);
cout<<" gia tri lon nhat"<< TimMAX(l);
system("pause");
return 0;
}
*/
#include<iostream>
using namespace std;

// Bài toán: Nhập danh sách liên kết đơn các số nguyên. Tìm giá trị lớn nhất trong danh sách

// ============== KHAI BÁO CẤU TRÚC DANH SÁCH LIÊN KẾT ĐƠN CÁC SỐ NGUYÊN ==============
// khai báo cấu trúc 1 cái node
struct node
{
	int data; // dữ liệu chứa trong 1 cái node 
	struct node *pNext; // con trỏ dùng để liên kết giữa các cái node với nhau
};
typedef struct node NODE; // thay thế struct node thành NODE

// khai báo cấu trúc của danh sách liên kết đơn
struct list
{
	NODE *pHead; // node quản lí đầu danh sách
	NODE *pTail; // node quản lí cuối danh sách
};
typedef struct list LIST; // thay thế struct list thành LIST

// ============== KHỞI TẠO CẤU TRÚC DANH SÁCH LIÊN KẾT ĐƠN CÁC SỐ NGUYÊN ==============
void KhoiTao(LIST &l)
{
	// cho 2 node trỏ đến NULL - vì danh sách liên kết đơn chưa có phần tử
	l.pHead = NULL;
	l.pTail = NULL;
}

// hàm khởi tạo 1 cái node
NODE *KhoiTaoNODE(int x)
{
	NODE *p = new NODE; // cấp phát vùng nhớ cho NODE p
	if (p == NULL)
	{
		cout << "\nKhong du bo nho de cap phat !";
		return NULL;
	}
	p->data = x; // truyền giá trị x vào cho data
	p->pNext = NULL; // đầu tiên khai báo node thì node đó chưa có liên kết đến node nào hết ==> con trỏ của nó sẽ trỏ đến NULL
	return p; // trả về NODE p vừa khởi tạo
}

// hàm thêm node p vào đầu danh sách liên kết
void ThemVaoDau(LIST &l, NODE *p)
{
	/// danh sách đang rỗng
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p; // node đầu cũng chính là node cuối và là p
	}
	else
	{
		p->pNext = l.pHead; // cho con trỏ của node cần thêm là node p liên kết đến node đầu - pHead
		l.pHead = p; // cập nhật lại pHead chính là node p
	}
}

// hàm thêm node p vào cuối danh sách liên kết
void ThemVaoCuoi(LIST &l, NODE *p)
{
	/// danh sách đang rỗng
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p; // node đầu cũng chính là node cuối và là p
	}
	else
	{
		l.pTail->pNext = p; // cho con trỏ của pTail liên kết với node p
		l.pTail = p; // cập nhật lại p là node pTail
	}
}

// hàm xuất danh sách liên kết đơn
void XuatDanhSach(LIST l)
{
	// for(int i = 0; i < n; i++)
	for (NODE *k = l.pHead; k != NULL; k = k->pNext)
	{
		cout << k->data << " ";
	}
}

// hàm tìm giá trị lớn nhất trong danh sách
int TimMax(LIST l)
{
	int max = l.pHead->data; // giả sử node đầu là node lớn nhất
	// bắt đầu duyệt từ node thứ 2 để kiểm tra
	for (NODE *k = l.pHead->pNext; k != NULL; k = k ->pNext)
	{
		if (max < k->data)
		{
			max = k->data; // cập nhật lại giá trị max
		}
	}
	return max;
}

int main()
{
	LIST l;
	KhoiTao(l); // khởi tạo danh sách liên kết đơn


	int n;
	cout << "\nNhap so luong node can them: ";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cout << "\nNhap gia tri so nguyen: ";
		cin >> x;
		NODE *p = KhoiTaoNODE(x); // khởi tạo 1 cái node số nguyên
		ThemVaoCuoi(l, p); // thêm node p vào đầu danh sách liên kết đơn 
	}
	cout << "\n\n\t DANH SACH LIEN KET DON\n";
	XuatDanhSach(l);

	cout << "\n\n\t GIA TRI LON NHAT: " << TimMax(l);
	system("pause");
	return 0;
}
