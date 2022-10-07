#include<iostream>
using namespace std;
 

struct node
{
    int data;
    struct node *pNext;
};
typedef struct node NODE;
 
struct stack
{
    NODE *pTop; // con trỏ quản lí đầu stack
};
typedef struct stack STACK;
 

void CreateStack(STACK &s)
{
    s.pTop = NULL;
}
 

NODE *CreateNode(int x)
{
  
    NODE *p = new NODE();
    if (p == NULL)
    {
        cout << "\nKhông đủ bộ nhớ để cấp phát !";
        return NULL;
    }
  
    p->data = x; 
    p->pNext = NULL;
    return p;
}
 

bool IsEmpty(STACK s)
{
    
    if (s.pTop == NULL)
    {
        return false;
    }
    return true;
}
 

bool Push(STACK &s, NODE *p)
{
    
    if (p == NULL)
    {
        return false;
    }
    if (IsEmpty(s) == false)
    {
            s.pTop = p;
    }
    else
    {
           p->pNext = s.pTop; 
    
        s.pTop = p;
    }
      return true;
}
 
bool Pop(STACK &s, int &x) 
{
    
    if (IsEmpty(s) == false)
    {
           return false; 
    }
     NODE *p = s.pTop; 
      s.pTop = s.pTop->pNext;
     x = p->data; 
     return true; 
}
 
bool Top(STACK s, int &x) {
   
 
    if (IsEmpty(s) == false)
    {
        return false;
    }
    x = s.pTop->data;
    return true;
}
 
/* Hàm đổi cơ số 10 sang các cơ số 16, 2 */
void Chuyen_Co_So(STACK &s, int cosocandoi, int thapphan)
{
    while (thapphan != 0)
    {
        int x = thapphan % cosocandoi;
        NODE *p = CreateNode(x); 
        Push(s, p);
        thapphan /= cosocandoi;
    }
}
 
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
    CreateStack(s);
     
    int thapphan,cosocandoi;
    cout << "\n Nhap gia tri thap phan can chuyen : ";
    cin >> thapphan;
  do{
    cout << "\nNhap co so can chuyen (2, 16):  ";
      cin >> cosocandoi;
  }while(cosocandoi != 2  && cosocandoi != 16);
 
    Chuyen_Co_So(s, cosocandoi, thapphan);
    cout << "\nKet qua:\n";
    XuatStack(s);
    cout << endl;
 
  cout<<"\n-------------------------\n";
}

