#include <iostream>
#include<conio.h>

using namespace std;

int main() {

   int var;
   //Pointer Variable Declaration for Integer Data Type 
   int *pt;

   //Double Pointer Variable Declaration with Double Dereference operator (**)
   int **dp;

   cout << "Pointer Example C++ Program : Pointer to Pointer or Double Pointer  \n";

   var = 100;

   cout << "Address of var 			[&var ]	:" << &var << "\n";
   cout << "Value   of var 			[var ]	:" << var << "\n\n";

   //& takes the address of var , Here now pt == &var, so *pt == var
   pt = &var;

   cout << "Address of Pointer 		[pt  ] 	:" << pt << "\n";
   cout << "Value of Pointer 		[*pt ] 	:" << *pt << "\n\n";

   //& takes the address of pt , Here now dp == &pt, so *pt == pt and **dp==var
   dp = &pt;

   cout << "Address of Double Pointer 	[dp  ] 	:" << dp << "\n";
   cout << "Value of Double Pointer 		[*dp ] 	:" << *dp << "\n\n";
   cout << "Double Pointer Value 		[**dp] 	:" << **dp << "\n";

   getch();
   return 0;

}
