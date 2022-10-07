#include<iostream>
using namespace std;
#define MAX 100
class Stack {
int top=-1;
public:
int data[MAX];
Stack() { top = -1; }
~Stack() { top = -1; }
bool push(int x);
int pop();
int getTop();
bool isEmpty()
{return (top < 0);};
bool isFull()
{return (top >= MAX-1);
};
};
bool Stack::push(int x) 
{ 
if (top >= (MAX - 1)){ 
cout << "Overflow"; 
return false; 
} 
else { 
data[++top] = x; 
return true; 
} 
} 
int Stack::pop() 
{ 
if (top < 0) { 
cout <<"Underflow"; return 0; 
} 
else { 
return data[top--]; ; 
} 
} 
int Stack::getTop() 
{ 
if (top < 0) { 
cout << "is Empty"; return 0; 
} 
else { 
return data[top]; 
} 
}
int main()
{
class Stack s;
cout <<"\n ===Before push elements====";
cout <<"\n Check empty: "<<s.isEmpty();
cout <<"\n Check full: "<<s.isFull()<<endl;
for (int i=1;i<=MAX;i++){
s.push(i);
}
cout <<"\n ===After push elements====";
cout <<"\n Check empty: "<<s.isEmpty();
cout <<"\n Check full: "<<s.isFull();
cout <<"\n === Pop all elements===="<<endl;
for (int i=1;i<=MAX;i++){
cout << s.pop() <<"->";
}
cout <<"\n ===After pop all elements====";
cout <<"\n Check empty: "<<s.isEmpty();
cout <<"\n Check full: "<<s.isFull()<<endl;
return 0;
}
