#include <iostream>
#include<conio.h>

using namespace std;

int main() {

   //Pointer Variable Declaration for Integer Data Type 
   int* pt;
   int var;

   cout << "C++ Pointer Example for Reference operator (&) and Dereference operator (*)\n";

   var = 1;

   cout << "Address of var 			:" << &var << "\n";
   cout << "Value   of var 			:" << var << "\n\n";

   //& takes the address of var , Here now pt == &var, so *pt == var
   pt = &var;

   cout << "Address of Pointer pt 	:" << pt << "\n";
   cout << "Content of Pointer pt 	:" << *pt << "\n\n";

   var = 2;

   cout << "Address of Pointer pt 	:" << pt << "\n";
   cout << "Content of Pointer pt 	:" << *pt << "\n\n";

   //Assign Values using dereference operator
   *pt = 3;

   cout << "Address of var			:" << &var << "\n";
   cout << "Value   of var			:" << var << "\n\n";

   getch();
   return 0;

}
