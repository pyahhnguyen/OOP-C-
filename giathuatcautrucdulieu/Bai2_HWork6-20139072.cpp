#include <iostream>
#include <cstring>
#define MAX 100
using namespace std;
struct Stack
{
    char a[MAX][MAX];
    int top;
};
void init(Stack &s)
{
    s.top = -1;
}
void push(Stack &s, char x[])
{
    strcpy(s.a[++s.top], x);
}
char* pop(Stack &s)
{
    return s.a[s.top--];
}
bool isEmpty(Stack s)
{
    return s.top < 0;
}
bool isFull(Stack s)
{
    return s.top == MAX;
}


bool checkOp(char op[])
{
    return strcmp(op, "+") == 0 || strcmp(op, "-") == 0 ||
            strcmp(op, "*") == 0 || strcmp(op, "/") == 0;

}

void cal(char s[]){
    Stack st;
    init(st);
    char *p = strtok(s, " ");
    int t = 0;
    while (p != NULL)
    {
         if (checkOp(p) == true)
         {
              int b = atoi(pop(st));
              int a = atoi(pop(st));
              if (strcmp(p, "+") == 0)
                  t= a+b;
              else if (strcmp(p, "-") == 0)
                  t= a - b;
              else if (strcmp(p, "*") == 0)
                  t = a * b;
                                     
              else if (strcmp(p, "/") == 0)
                  t= a/ b;

              char tmp[MAX];
              sprintf(tmp, "%d", t);
              push(st, tmp);
         }     
         else
         {
              push(st, p);
         }
         p = strtok(NULL, " ");
    }
    cout << "Ket qua cua bieu thuc la = "<< t << endl;
}


int main()
{
    cout<<" Nhap day ki tu bieu thuc:  2 8 + 4 * 6 + "<<endl;//"2 8 + 4 * 6 +"; // tuong uong voi ((2+8)*4)+6=46
    char s[]= "2 8 + 4 * 6 + " ;
    cal(s);
    return 0;
/*
char s[]= "  "  ;
cout<<"Nhap vao bieu thuc:"<<endl;
cin>>s;
cal(s);
return 0;
*/
}