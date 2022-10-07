#include<stdio.h>
#include<iostream>
#include <vector>
using namespace std;



void nhap(int A[],int n){ 
    printf("\n Nhapn="); 
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("\nNhapa[%d]=",i+1);
        scanf("%d",&a[i]);
    }
}


void SelectionSort ( int A [ ] , int n )// Sắp xếp mảng A[0 . . n-1 ] theo thứ tự tăng dần
{
    for ( int current = 0 ; current < n - 1 ; current++ )
     Swap( A[ current ] , A [ GetMin ( A, current, n-1 ) ] ) ;
}

 

int GetMin ( int A [ ] , int start , int end )// Tìm chỉ số của phần tử có giá trị nhỏ nhất trong mảng// A [start] . . A [end].

{
    int indexOfMin = start ;
    for ( int i = start + 1 ; i <= end ; i++ )
       if ( A [ i ] < A [ indexOfMin ] )
         indexOfMin = i ;
         return indexOfMin;}

void InsertionSort(int A[ ], int n){
    int i, j; 
    int temp; 

    for (j=1; j < n; j++) {
    temp = A[j]; // chèn A[j] vào chuỗi A[0], …, A[j-1]
    i = j-1; 
    while (i >=0 && A[i] > temp) {
        A[i+1] = A[i];
        i = i -1; 
        }
        A[i+1] = temp;}
    }
    void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
     int L[n1], R[n2];
 
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
    
        int m = l+(r-l)/2;
 
      
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
 
        merge(arr, l, m, r);
    }
}


