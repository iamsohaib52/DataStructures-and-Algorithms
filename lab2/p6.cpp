#include <iostream>
#include<conio.h>

using namespace std;

int main() {
   int *p1, *p2;
   int num1, num2, sum;

   cout << "Pointer Example C++ Program : Add Two Numbers \n";

   cout << "\nEnter Two Numbers for Sum : \n";
   cin>>num1;
   cin>>num2;

   p1 = &num1;
   p2 = &num2;

   sum = *p1 + *p2;

   cout << "Sum of Two Numbers : " << sum;

   getch();
   return 0;
}
