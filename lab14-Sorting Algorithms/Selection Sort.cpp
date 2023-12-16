#include <iostream>  
  
using namespace std;  
  
void selection(int arr[], int n)  
{  
    int i, j, small;  
      
    for (i = 0; i < n-1; i++)    // One by one move boundary of unsorted subarray  
    {  
        small = i; //minimum element in unsorted array  
          
        for (j = i+1; j < n; j++)  
        if (arr[j] < arr[small])  
            small = j;  
// Swap the minimum element with the first element  
    int temp = arr[small];  
    arr[small] = arr[i];  
    arr[i] = temp;  
    }  
}  
  
void printArr(int a[], int n) /* function to print the array */  
{  
    int i;  
    for (i = 0; i < n; i++)  
        cout<< a[i] <<" ";  
}  
  
int main()  
{  
    int a[] = { 3,2,4,5,6,1 };  

    cout<<sizeof(a[0]);
    int n = sizeof(a)/*a==5*/ / sizeof(a[0])/*1*/;  
    cout<< "Before sorting array elements are - "<<endl;  
    printArr(a, n);  
    selection(a, n);  
    cout<< "\nAfter sorting array elements are - "<<endl;    
    printArr(a, n);  
  
    return 0;  
} 
