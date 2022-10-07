/*#include<iostream>
#define INF 9999999;

using namespace std;

struct Node{
    int data;
    struct Node* link;
};

class Stack{

public:
  struct Node* top;
   Stack() { top = NULL; }

   ~Stack() { top = NULL; }
  bool push(int x);

int pop();

int getTop();

bool isEmpty() {return (top==NULL);};
};



bool Stack::push(int data) 
{
struct Node* temp;
temp = new Node();
if (!temp) { 
            cout<<"\nHeap Overflow";
return false;
}
temp->data = data;

temp->link = top; 
top = temp; 
return true;
}
int Stack::pop()
{
struct Node* temp;
if (top== NULL){
    cout << "\nStack Underflow"<< endl; 
    return INF;
}

else { 
      temp = top; 
      top= top->link;
      temp->link= NULL;
      int data=temp->data;

     free(temp);
     return data;
  }
}


int main(){

class Stack s;
 cout <<"\n ===Before push elements===="; 
 cout <<"\n Check empty: "<<s.isEmpty(); 
 for (int i=1;i<=100; i++){ 
 s.push(i);
 }

cout <<"\n ===After push elements====";
 cout <<"\n Check empty: "<<s.isEmpty(); 
 cout << "\n Top element is " << s.getTop();

cout <<"\n === Pop all elements===="<<endl;
 for (int i=1;i<=100; i++){ 
   cout << s.pop() <<"->";
 }
cout << "\n Top element is " << s.getTop();
 cout <<"\n ===After pop all elements===== ";
 cout <<"\n Check empty: "<<s.isEmpty();
  return 0;
}  
*/



#include<iostream>
#include<string>
using namespace std;
#define MAX 100
 struct Student{
int MSSV; 
string name;
char gender;
int month , year, day;
float math, phys, chem, avg;
};
 Student *Init(){
cout << "==================\n";
Student *sv = new Student;
cout << "Enter MSSV: \n";
cin >> sv->MSSV;
fflush(stdin);
cout << "Enter student's name: \n";
getlines(std::cin, sv->name);
cout << "Enter date of birth (dd mm yyyy): \n";
cin >> sv->day >> sv->month >> sv->year;
fflush(stdin);
cout << "Enter gender: \n";
cin >> sv->gender;
cout << "Enter score: \n";
cin >> sv->math >> sv->phys >> sv->chem;
sv->avg = (sv->math + sv->phys + sv->chem)/3;
return sv;
 }
    void Print(Student* sv){
                     
   cout << "MSSV: "<<sv->MSSV<< endl;
   cout << "Name: "<<sv->name<< endl;
   cout << "Date of birth:" << sv->day << "/" << sv->month << "/" <<sv->year << endl;
                    
   cout << "Gender:"<< sv->gender << endl;
   cout << "Score:" << "Math:"<< sv->math << "Physic: "<< sv->phys << "Chemistry:" << sv->chem  << endl;
   cout << "Average: ";
   printf("%.2f\n", sv->avg);
    }
                                                         
class Stack {
  private:

 int top=-1;
 Student* data[MAX];

 public:
 
 Stack() { top = -1; }
 ~Stack() { top = -1; }
 bool push();
 int pop();
 int getTop();
 bool isEmpty()
  {return (top < 0);};
 bool isFull()
 {return (top >= MAX-1);
};
};
             
bool Stack::push(){
Student *sv = Init();
 if (top >= (MAX - 1)){
  cout << "Overflow";
 
  return false;
 }
 else {
  data[++top] = sv;
  return true;
 }
 }
int Stack::pop()
{
if (top < 0) {
  cout <<"Underflow"; return 0;
}
 else {
   Print( data[top--]);
 }

}
int Stack::getTop()
 {
 if (top <0) {
   cout << "is Empty"; return 0;

 }
  else {
  Print( data[top]);             
  }
 }
int main(){

class Stack s;
 cout <<"\n ===Before push elements===="; 
 cout <<"\n Check empty: "<<s.isEmpty(); 
 cout <<"\n Check Full: "<<s.isFull()<<endl; 

 for (int i=1;i<=2; i++){ 
 s.push();
 }

cout <<"\n ===After push elements====";
 cout <<"\n Check empty: "<<s.isEmpty(); 
 cout <<"\n Check Full: "<<s.isFull(); 
cout <<"\n === Pop all elements===="<<endl;
 for (int i=1;i<=2; i++){ 
   cout << s.pop() <<endl;
 }
 cout <<"\n ===After pop all elements===== ";
 cout <<"\n Check empty: "<<s.isEmpty();
 cout <<"\n Check Full: "<<s.isFull(); 
  return 0;
}