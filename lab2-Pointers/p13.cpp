#include <iostream>
#include<conio.h>

using namespace std;

#define MAX_SIZE 5

int main() {

   // Declare Variables
   int var[] = {10, 20, 30, 40, 50};
   int i = 0, sum = 0;

   //Pointer Variable Declaration for Integer Data Type 
   int *pt;

   cout << "Pointer Example C++ Program : Sum of Integer Pointer and Array \n";

   //& takes the address of var , Here now pt == &var, so *pt == var
   pt = &var[0];

   while (i < MAX_SIZE) {
      i++;

      // Calculate sum using pointer
      sum = sum + *pt;

      // pt++ is increasing Address value based on Data Type
      pt++;
   }

   cout << "Sum of Array : " << sum;

   getch();
   return 0;
}
