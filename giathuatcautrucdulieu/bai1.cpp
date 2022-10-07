
#include<iostream> 
#include<string>
#include <time.h> 
using namespace std;
int max(int num1, int num2){

return (num1 >num2) ? num1 : num2;
}

typedef struct rect{

private:
int h=0;
int w=0;
int area=0;
int perimeter=0;
void update(){
area=h*w;
perimeter= (h+w)*2;

} 
public:
rect(int n1=0, int n2=0) {

h=n1;
w=n2;
 update();
 }
void operator*(int n) {
h=h*n;
w=w*n; 
update();

}

rect operator*(rect a) {

rect b(0,0);
 b.h=h*a.h;
b.w=w*a.w;
b.update();}
return b;

rect operator+(rect a) {
rect b(0,0);
b.h=h+a.h;
b.w-w+a.w;
b.update();
return b;
rect operator-(rect a) {
rect b(0,0);
b.h=max(h-a.h,e);
b.w=max(w-a.w,e);
b.update();
return b;
bool operator==(rect a) {
return h*w==a.h*a.w;
int geth(){return h;}
int getw(){return w;}
int geta(){return area;}
int getd(){return perimeter;}
) rect;




int main (){
rect ri(2,3), r2(4,6),r3=r1+r2, r4=r1-r2,r5=r1*r2;
printf("So sanh R1==R2?=> %s \n",r1==r2?"True":"False");
printf("Hinh chu nhat R1 la [%d, %d],
area-%d, perimeter-%d\n",r1.geth(),r1.getw(),r1.geta(),rl.getd());
printf("Hinh chu nhat R2 la [Xd, Xd],
area-Xd, perimeter-%d\n",r2.geth(),r2.getw(),r2.geta(),r2.getd());
printf("Hinh chu nhat R3 la [%d, %d],
area-%d, perimeter-%d\n",r3.geth(),r3.getw(),r3.geta(),r3.getd());
printf("Hinh chu nhat R4 la [%d, %d],
area-Xd, perimeter-%d\n",r4.geth(),r4.getw(),r4.geta(),r4.getd());
printf("Hinh chu nhat R5 la [%d, %d],area-%d, perimeter=%d\n",r5.geth(),r5.getw(),r5.geta(),r5.getd());
  rl*2;
  printf("So sanh R1==R2?=> %s \n",r1==r2?"True":"False");
  printf("Hinh chu nhat R1 la [Xd, %d],area-%d, perimeter-%d\n",r1.geth(),rl.getw(),r1.geta(),rl.getd());