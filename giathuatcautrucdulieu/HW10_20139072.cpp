#include<iostream>
using namespace std;
int binarySearch(int arr[], int l, int h, int element)
{
	while (l <= h) {
		
		int m = (l + h) / 2;//both=>m = l + (r - l) / 2 both=>m = (2 l + r -l)/2

		
		if (arr[m] == element)
			return m;
        
		if (arr[m] > element)
			
		h = m - 1;

		else

		l = m + 1;

	}

	return -1;
}


int main()
{
	int arr[] = { 1,2, 3, 4,5,6 ,8,10, 40 };
	int n = sizeof(arr) / sizeof(arr[0]);
	
	int num;
	cout << "Enter an Integer :";
	cin >> num;

	int result = binarySearch(arr, 0, n - 1, num);
	if(result == -1)
		cout << "The Number : (" << num << ") Was Not Found." << endl;
	else
		cout << "The Number : (" << arr[result] << ") Was Found At Index : (" << result << ")" << endl;
	
	return 0;
}


#####

#include <iostream>
using namespace std;
 
int search(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}
 

int main(void)
{
    int arr[] = { 2, 3, 4, 10, 40 };
    int x = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
   
  
    int result = search(arr, n, x);
    (result == -1)
        ? cout << "Element is not present in array"
        : cout << "Element is present at index " << result;
    return 0;
}