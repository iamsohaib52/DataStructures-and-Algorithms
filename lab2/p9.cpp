#include <iostream>
#include<conio.h>

using namespace std;

int main() {

   // Declare Variables
   char str[20], *pt;

   cout << "Pointer Example C++ Program : Print String \n";
   cout << "Enter Any string [below 20 chars] : ";
   cin>>str;

   // Assign to Pointer Variable
   pt = str;

   while (*pt != '\0') {
      cout << *pt;
      pt++;
   }

   getch();
   return 0;
}
