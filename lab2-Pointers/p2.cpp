#include <iostream>
#include<conio.h>

using namespace std;

int main() {

   int a;
   int *pt;

   cout << "C++ Pointer Example Program : Print Pointer Address\n";
   a = 10;
   pt = &a;

   cout << "\n[a  ]:Value of A = " << a;
   cout << "\n[*pt]:Value of A = " << *pt;
   cout << "\n[&a ]:Address of A = " << &a;
   cout << "\n[pt ]:Address of A = " << pt;
   cout << "\n[&pt]:Address of pt = " << &pt;
   cout << "\n[pt ]:Value of pt = " << pt;

   return 0;
}
