#include<iostream>
#include<string>
#include <time.h>
#include <math.h>
int max(int num1, int num2){
    return (num1 > num2 ) ? num1 : num2;
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
    rect operator*(int n) {
      rect b(0,0);
      b.h=h*n;
      b.w=w*n;
      b.update();
      return b;
    }
    rect operator*(rect a) {
      rect b(0,0);
      b.h=h*a.h;
      b.w=w*a.w;
      b.update();
      return b;
    }
rect operator+(rect a) {
  rect b(0,0);
  b.h=h+a.h;
  b.w=w+a.w;
  b.update();
  return b;
}
rect operator-(rect a) {
  rect b(0,0);
  b.h=max(h-a.h, 0);
  b.w=max (w-a.w, 0);
  b.update();
  return b;
}
bool operator==(rect a) {
  return h*w==a.h*a.w;
}
bool operator!=(rect a) {
  return (h!=a.h)||(w!=a.w);
}
bool operator>=(rect a) {
  return h*w >= a.h*a.w;
}
bool operator<(rect a) {
  return h*w < a.h*a.w;
}
rect operator^(rect a) {
  rect b(0,0);
 b.h=pow(h, a.h);
  b.w=pow(w, a.w);
  b.update();
  return b;
}
int geth(){return h;}
int getw(){return w;}
int geta(){return area;}
int getd(){return perimeter;}
void seth(int a){
  h=a;
  update();
}
void setw(int a){
  w=a;
  update();
}
void set (int a, int b){
  h=a;
  w=b;
  update();
}
} rect;

int main (){
 rect r1(2,3), r2(4,6),r3=r1+r2,r4=r1-r2, r5=r1*r2, r6=r1*2;

printf("So sanh R1==R2?=> %s \n",r1==r2?"True": "False");
printf("Hinh chu nhat R1 la [%d, %d],area=%d, perimeter=%d\n",r1.geth(),r1.getw(),r1.geta(),r1.getd());
printf("Hinh chu nhat R2 la [%d, %d],area=%d, perimeter=%d\n",r2.geth(),r2.getw(),r2.geta(),r2.getd());
printf("Hinh chu nhat R3=r1+r2 la [%d, %d],area=%d, perimeter=%d\n",r3.geth(),r3.getw(),r3.geta(),r3.getd());
printf("Hinh chu nhat R4=r1-r2 la [%d, %d],area=%d, perimeter=%d\n",r4.geth(), r4.getw(),r4.geta(), r4.getd());
printf("Hinh chu nhat R5=r1*r2 la [%d, %d],area=%d, perimeter=%d\n",r5.geth(),r5.getw(),r5.geta(),r5.getd());
printf("Hinh chu nhat R6=r1*2 la [%d, %d],area=%d, perimeter=%d\n",r6.geth(), r6.getw(),r6.geta(), r6.getd());
printf("So sanh R6==R2?=> %s \n",r6==r2?"True":"False");
printf("So sanh R6>=R1?=> %s \n", r6>=r1?"True":"False");
printf("So sanh R6<R1?=> %s \n", r6<r1?"True":"False");
rect r7=r2^r1;
printf("Hinh chu nhat R7=r2^r1 la [%d, %d]area=%d, perimeter=%d\n",r7.geth(),r7.getw(),r7.geta(),r7.getd());
r1. set(2,2);
r7=r2^r1;
printf("Hinh chu nhat R7=r2^r1 la [%d, %d],area=%d, perimeter=%d\n",r7.geth(),r7.getw(),r7.geta(),r7.getd());
r7. seth(10);
r7. setw(20);
printf("Hinh chu nhat R7 sau khi set lai la [%d, %d],area=%d, perimeter=%d\n",r7.geth(),r7.getw(),r7.geta(),r7.getd());
}