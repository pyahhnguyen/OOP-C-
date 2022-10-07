#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
struct sinhvien {
    int masv;
    char tensv[20];
    char lop[20];
    int namsinh;
    float toan;
    float ly;
    float hoa;
    float dtk;
    char gt[5];

};
typedef struct sinhvien SV;
struct node{
    SV data;
    node * next;
};
typedef struct node NODE;
struct list{
    NODE *pHead;
    NODE *pTail;
};
typedef struct list List;
void KhoiTao(List &ds){
    ds.pHead = NULL;
    ds.pTail = NULL;
}
int KiemTraRong(List ds){
    if (ds.pHead == NULL){
        return 1;
    }
    return 0;
}
NODE* TaoNode(SV x) {
    NODE *p;
    p = new NODE;
    if (p==NULL) {
        printf("KHONG DU BO NHO");
        return NULL;
    }
    p->data=x;
    p->next=NULL;
    return p;
}
void ChenCuoi (List &ds, NODE *p){
    if (ds.pHead==NULL) {
        ds.pHead=p;
        ds.pTail=p;
    }
    else {
        ds.pTail->next=p;
        ds.pTail=p;
    }
}

void Nhap(List &ds, int n){
    printf("NHAP THONG TIN SINH VIEN\n");
    for(int i = 0; i < n; i++){
        SV x;
        printf ("Nhap ma sinh vien : ");fflush(stdin);
        scanf("%d",&x.masv);
        printf ("Nhap ten sinh vien : ");
        gets(x.tensv);
        printf("Nhap vao ngay sinh sv 'dd mm yy'");fflush(stdin);
        scanf("%d",&x.namsinh);
        printf("Nhap vao lop: ");fflush(stdin);
        gets(x.lop);
        printf ("Nhap diem toan : ");fflush(stdin);
        scanf("%f",&x.toan);
        printf ("Nhap diem ly : ");fflush(stdin);
        scanf("%f",&x.ly);
        printf ("Nhap diem hoa : ");fflush(stdin);
        scanf("%f",&x.hoa);
        printf ("Nhap gioi tinh : ");fflush(stdin);
        gets(x.gt);
        
        printf ( "Diem tong ket : ");fflush(stdin);
        scanf("%f",&x.dtk);
        printf ("\n \n");
        NODE *p = new NODE;
        p = TaoNode(x);
        ChenCuoi(ds,p);
    }
}
void Xuat(List ds){
    for(NODE *p = ds.pHead; p!= NULL; p=p->next){
        printf("%d\t %s\t %d\t %s\t %f\t %f\t %f\t %s\t %f\t \n", 
        p->data.masv, p->data.tensv,p->data.namsinh, p->data.lop,p->data.toan,p->data.ly,p->data.hoa,p->data.gt, p->data.dtk);
    }
}


int main(){
    List ds;
    int n;
    printf("NHAP N: ");
    scanf("%d",&n);
    KhoiTao(ds);
    Nhap(ds,n);
    printf("\nDANH SACH SINH VIEN\n");
    Xuat(ds);
}

   

/*
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
struct SinhVien
{
    int ma;
    char ten[150];
    char gender
};

struct Node
{
    SinhVien *data;
    Node *pNext;
};
struct SingleList
{
    Node *pHead;
};

void Initialize(SingleList *&list)
{
    list=new SingleList;
    list->pHead=NULL;
}

SinhVien *NhapSinhVien()
{
    SinhVien *sv=new SinhVien;
    cout<<"Nhap MSSV:";
    cin>>sv->ma;
    cin.ignore();
    cout<<"Nhap ho va ten:";
    gets(sv->ten);
    cout<<"Nhap gioi tinh";
    cin>>sv->gender;
    return sv;
}

Node *CreateNode(SinhVien *sv)
{
    Node *pNode=new Node;
    if(pNode!=NULL)
    {
        pNode->data=sv;
        pNode->pNext=NULL;
    }
    else
    {
        cout<<"cap phat bo nho that bai!!!";
    }
    return pNode;
}


void PrintList(SingleList *list)
{
    Node *pTmp=list->pHead;
    if(pTmp==NULL)
    {
        cout<<"Danh sach rong";
        return;
    }
    while(pTmp!=NULL)
    {
        SinhVien *sv=pTmp->data;
        cout<<sv->ma<<"\t"<<sv->ten<<"\n"<<sv->gender<<"\n";
        pTmp=pTmp->pNext;
    }
}

*/


