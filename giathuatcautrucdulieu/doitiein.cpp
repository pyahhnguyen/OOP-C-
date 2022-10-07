#include<stdio.h>
#include<conio.h>
#define MAX 5


int main(void){
    int itien[MAX]={50,25,10,5,1};
    int i, isotien, ito;
    printf("Nhap vao so tien:");
    scanf("%d",&isotien);
    for(i=0;i<MAX;i++){
        ito=isotien/itien[i];
        printf("%4d to %2d dong\n",ito,itien[i]);
        isotien=isotien%itien[i];
    }
    getch();

}