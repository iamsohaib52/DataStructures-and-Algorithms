#include<iostream>
using namespace std;
int main(){
	int i = 10;
    int *Ptr;

    Ptr = &i;
    cout << "\nValue Of i :" << i;
    cout << "\nAddress Of i :" << i;
    cout << "\nValue Of Ptr :" << Ptr;
    cout << "\nAddress Of Ptr :" << &Ptr;
    cout << "\nPtr's Pointer Value:" << *Ptr;
    cout << "\nPtr Equal to &i :" << *(&i);
	return 0;
}
