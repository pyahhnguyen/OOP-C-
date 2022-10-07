/*


#include<iostream>
using namespace std;

struct tNode{
	int data;
	tNode *pLeft, *pRight;
};


tNode *root;

//create empty tree
void createEmptyTree(){
	root = NULL;
}

//create new node
tNode *newNode(int data){
	tNode *node = new tNode;
	if(node==NULL){//cannot allocate memory
		exit(1);
	}else{
		node->data = data;
		node->pLeft = NULL;
		node->pRight = NULL;
	}
	return node;
}
//insert new Node into tree
tNode *insertNode(tNode *node, int value){
	if(node!=NULL){
		if(node->data == value){
			return node;
		}else if(node->data > value){
			node->pLeft = insertNode(node->pLeft, value);
		}else{
			node->pRight = insertNode(node->pRight, value);
		}
	}else{
		node = newNode(value);
	}
	return node;
}

void NLR(tNode *root){
	if(root!=NULL){
		if(root!=NULL){
		  cout<<root->data<<" ";
		}
		NLR(root->pLeft);
		NLR(root->pRight);
	}
}

tNode *searchNodeByRecursion(tNode *root, int x){
	if(root != NULL ){
		if(root->data == x){
			return root;
		}
		if(root->data > x){
			return searchNodeByRecursion(root->pLeft,x);
		}else{
			return searchNodeByRecursion(root->pRight,x);
		}
	}
	return NULL;
}

tNode *searchNodeWithoutRecursion(tNode *root, int x){
	tNode *p=root;
	while(p != NULL){
		if(p->data == x){
			return p;
		}else if(p->data > x){
			p = p->pLeft;
		}else{
			p = p->pRight;
		}
	}
	return NULL;
}

tNode *minValueNode(tNode *node){
	tNode *current = node;
	while(current && current->pLeft != NULL){
		current = current->pLeft;
	}
	return current;
}

tNode *deleteNode(tNode *root, int x){
	if(root == NULL){
		return root;
	}
	if(root->data > x){
		root->pLeft = deleteNode(root->pLeft, x);
	}else if(root->data < x){
		root->pRight = deleteNode(root->pRight, x);
	}else{
		tNode *p = root;
		if(root->pLeft == NULL){
			root=root->pRight;
			delete p;
		}else if(root->pRight== NULL){
			root=root->pLeft;
			delete p;
		}else{
			tNode *temp = minValueNode(root->pRight);
			root->data = temp->data;
			root->pRight = deleteNode(root->pRight, temp->data);
		}
	}
	return root;
}

int main()
{
	//create binary search tree
	createEmptyTree();
	root = insertNode(root, 8);
	root = insertNode(root, 3);
	root = insertNode(root, 1);
	root = insertNode(root, 6);
	root = insertNode(root, 7);
	root = insertNode(root, 10);
	root = insertNode(root, 14);
	root = insertNode(root, 4);
	cout<<"traverse tree with NLR:";
	NLR(root);
	tNode *temp = searchNodeWithoutRecursion(root, 10);
	if(temp!=NULL){
		cout<<endl<<"Found x=10";
	}else{
		cout<<endl<<"Cannot found x=10";
	}
	root = deleteNode(root, 3);
	cout<<endl<<"traverse tree with NLR after delete node:";
	NLR(root);
	system("pause");
}
*/
#include<iostream>
using namespace std;


struct node
{
	int data; // dữ liệu của node ==> dữ liệu mà node sẽ lưu trữ
	struct node *pLeft; // node liên kết bên trái của cây <=> cây con trái
	struct node *pRight; // node liên kết bên phải của cây <=> cây con phải
};
typedef struct node NODE;
typedef NODE* TREE;

// khởi tạo cây
void KhoiTaoCay(TREE &t)
{
	t = NULL; // cây rỗng
}

// hàm thêm phần tử x vào cây nhị phân
void ThemNodeVaoCay(TREE &t, int x)
{
	// nếu cây rỗng
	if (t == NULL)
	{
		NODE *p = new NODE; // khởi tạo 1 cái node để thêm vào cây
		p->data = x;// thêm dữ liệu x vào data
		p->pLeft = NULL;
		p->pRight = NULL;
		t = p;// node p chính là node gốc <=> x chính là node gốc
	}
	else // cây có tồn tại phần tử
 	{
		// nếu phần tử thêm vào mà nhỏ hơn node gốc ==> thêm nó vào bên trái
		if (t->data > x)
		{
			ThemNodeVaoCay(t->pLeft, x); // duyệt qua trái để thêm phần tử x
		}
		else if (t->data < x) // nếu phần tử thêm vào mà lớn hơn node gốc ==> thêm nó vào bên phải
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
		cout << t->data << " "; // xuất dữ liệu trong node
		Duyet_NLR(t->pLeft); // duyệt qua trái
		Duyet_NLR(t->pRight); // duyệt qua phải
	}
}
NODE* TimKiem(TREE t, int x)
{ 
	// nếu cây rỗng
	if (t == NULL)
	{
		return NULL;
	}
	else
	{
		// nếu phần tử cần tìm kiếm mà nhỏ hơn node gốc thì duyệt(đệ quy) sang bên trái để tìm
		if (x < t->data)
		{
			TimKiem(t->pLeft, x);
		}
		else if (x > t->data) // duyệt sang bên phải
		{
			TimKiem(t->pRight, x);
		}
		else // <=> t->data == x
		{
			return t; // trả về node cần tìm kiếm
		}
	}

}
void XoaNode(TREE &t, int data) // data chính là giá trị của cái node cần xóa
{
	// nếu như cây đang rỗng
	if (t == NULL)
	{
		return; // kết thúc hàm
	}
	else
	{
		// nếu như data nhỏ hơn node gốc
		if (data < t->data)
		{
			XoaNode(t->pLeft, data); // duyệt sang nhánh trái của cây 
		}
		else if (data > t->data)
		{
			XoaNode(t->pRight, data); // duyệt sang nhánh phải của cây 
		}
		else // data == t->data - đã tìm ra cái node cần xóa
		{
			NODE *X = t; // node X là node thế mạng - tí nữa chúng ta sẽ xóa nó
			// nếu như nhánh trái bằng NULL <=> đây là cây có 1 con chính là con phải
			if (t->pLeft == NULL)
			{
				// duyệt sang phải của cái node cần xóa để cập nhật mối liên kết giữa node 
				// cha của node cần xóa với node con của node cần xóa
				t = t->pRight; 
			}
			else if (t->pRight == NULL)
			{
				// duyệt sang trái của cái node cần xóa để cập nhật mối liên kết giữa node 
				// cha của node cần xóa với node con của node cần xóa
				t = t->pLeft;
			}
			
			delete X; // xóa node cần xóa
		}
	}
}

// hàm nhập dữ liệu
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
		if (luachon < 0 || luachon > 2)
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