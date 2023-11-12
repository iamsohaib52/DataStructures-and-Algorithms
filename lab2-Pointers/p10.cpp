#include <iostream>
#include<conio.h>

using namespace std;

int main() {

   // Declare Variables
   char str[20], *pt;
   int i = 0, c = 0;

   cout << "Pointer Example C++ Program : Count vowels String \n";
   cout << "Enter Any string (small letters) [below 20 chars] : ";
   cin>>str;

   // Assign to Pointer Variable
   pt = str;
   while (*pt != '\0') {
      if (*pt == 'a' || *pt == 'e' || *pt == 'i' || *pt == 'o' || *pt == 'u')
         c++;
      i++;
      pt++;
   }

   cout << "\nLength of String : " << i;
   cout << "\nVowels Count In the String : " << c;
   cout << "\nConstant Count in the String : " << (i - c);

   getch();
   return 0;
}
