#include <stdio.h>
#include <conio.h>
 
typedef struct
{
float real; // phan thuc
float image; // phan ao
 
}COMPLEX;
 
void ImportCOMPLEX(COMPLEX *comp, const char name);
COMPLEX CalCOMPLEX(COMPLEX compA, COMPLEX compB, const char op);
void ShowCOMPLEX(COMPLEX comp, const char name);
 
 
int main()
{
COMPLEX compA, compB, compC;
int sel;
char c;
// Nhap 2 so phuc A,B
ImportCOMPLEX(&compA, 'A');
ImportCOMPLEX(&compB, 'B');
 
ShowCOMPLEX(compA, 'A');
ShowCOMPLEX(compB, 'B');
do
{
printf("\n\n1. Cong 2 so phuc: C = A+B");
printf("\n2. Tru 2 so phuc: C = A-B");
printf("\n3. Nhan 2 so phuc: C = A*B");
printf("\n4. Chia 2 so phuc: C = A/B");
printf("\nBan chon: ");
scanf("%d", &sel);
 
switch(sel)
{
case 1:
compC = CalCOMPLEX(compA, compB, '+');
ShowCOMPLEX(compC,'C');
break;
case 2:
compC = CalCOMPLEX(compA, compB, '-');
ShowCOMPLEX(compC, 'C');
break;
case 3:
compC = CalCOMPLEX(compA, compB, '*');
ShowCOMPLEX(compC, 'C');
break;
case 4:
compC = CalCOMPLEX(compA, compB, '/');
ShowCOMPLEX(compC, 'C');
break;
}
printf("\nBan co muon tiep tuc ko: (y/n)?");
fflush(stdin);
c = getchar();
}
while( c == 'y' || c == 'Y');
getch();
}
 
// Ham nhap so phuc
void ImportCOMPLEX(COMPLEX *complex, const char name)
{
printf("\n=============So phuc %c================", name);
printf("\nPhan thuc: ");
scanf("%f", &complex->real);
printf("\nPhan ao: ");
scanf("%f", &complex->image);
}
 
// Ham tinh toan so phuc
COMPLEX CalCOMPLEX(COMPLEX compA, COMPLEX compB, const char op)
{
COMPLEX compC;
switch(op)
{
case '+': // A+B
compC.real = compA.real + compB.real;
compC.image = compA.image + compB.image;
break;
case '-': // A-B
compC.real = compA.real - compB.real;
compC.image = compA.image - compB.image;
break;
case '*': // A*B
compC.real = compA.real*compB.real - compA.image*compB.image;
compC.image = compA.real*compB.image + compA.image*compB.real;
break;
case '/': // A/B
compC.real = (float)(compA.real*compB.real + compA.image*compB.image)/
(compB.real*compB.real + compB.image*compB.image);
compC.image = (float)(compA.image*compB.real - compA.real*compB.image)/
(compB.real*compB.real + compB.image*compB.image);
break;
default:
printf("\nToan tu khong hop le");
}
return compC;
}
 
// Ham hien thi so phuc
void ShowCOMPLEX(COMPLEX complex, const char name)
{
if(complex.image > 0)
printf("\nSo phuc %c: %0.2f + %0.2fi", name, complex.real, complex.image);
else if(complex.image == 0)
printf("\nSo phuc %c: %0.2f", name, complex.real);
else
printf("\nSo phuc %c: %0.2f - %0.2fi", name, complex.real, (-1)*complex.image);
}
