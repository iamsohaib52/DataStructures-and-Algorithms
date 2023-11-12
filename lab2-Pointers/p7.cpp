#include <iostream>
#include<conio.h>

using namespace std;

int main() {
   int a;
   int *pt;

   cout << "Pointer Example C++ Program : Increment and Decrement Integer\n";
   a = 10;
   pt = &a;

   (*pt)++; //Post Increment
   cout << "\n[a  ]:Increment Value of A = " << a;

   ++(*pt); //Pre Increment
   cout << "\n[a  ]:Increment Value of A = " << a;


   (*pt)--; //Post Decrement
   cout << "\n[a  ]:Decrement Value of A = " << a;

   --(*pt); //Pre Decrement
   cout << "\n[a  ]:Decrement Value of A = " << a;

   getch();
   return 0;
}
