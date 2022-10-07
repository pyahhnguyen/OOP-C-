#include <iostream>
#include <cstdlib> // for srand() and rand()
#include <ctime> // for time()
using namespace std;

// định nghĩa số phần tử mảng
#define ROW 100
#define COL 100

// khai báo prototype
void nhapMang(int mt[][COL], int &m, int &n);
void xuatMang(int mt[][COL], int m, int n);

int main()
{
	int mt[ROW][COL]; // mảng myArray có MAX phần tử
	int nRow, nCol; // số phần tử dòng và cột được sử dụng

	// nhập xuất mảng tự động
	nhapMang(mt, nRow, nCol);
	xuatMang(mt, nRow, nCol);


	return 0;
}

// hàm nhập mảng
void nhapMang(int mt[][COL], int &m, int &n)
{
	// khởi tạo số ngẫu nhiên
	srand(time(NULL));

	cout << "Nhap so dong : ";
	cin >> m;
	cout << "Nhap so cot : ";
	cin >> n;

	// khởi tạo mảng ngẫu nhiên từ [0][0] đến [m-1][n-1].
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			mt[i][j] = rand() % 100;
		}
	}
}

// hàm xuất mảng
void xuatMang(int mt[][COL], int m, int n)
{
	// xuất từng phần tử cho mảng
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << mt[i][j] << "\t";
		}
		cout << endl;
	}
}
