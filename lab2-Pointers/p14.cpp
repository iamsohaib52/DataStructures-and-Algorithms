#include <iostream>
#include<conio.h>

using namespace std;

// Declare Add Numbers Function Using Pointer 

void add_numbers(int *value1, int *value2, int *result) {
   *result = *value1 + *value2;
}

int main() {
   // Declare Variables
   int number1, number2, result = 0;

   cout << "Pointer Example C++ Program : Passing pointers to functions In C++ \n";

   // Read User Input
   cout << "Enter value of Number # 1: ";
   cin>>number1;
   cout << "Enter value of Number # 2: ";
   cin>>number2;

   //Print Values Pass to Reference
   cout << "Before Pass to Reference :  Number # 1=" << number1 << ",  Number # 2=" << number2 << ", Result # :" << result << " \n";

   //Call add_numbers Function By Passing Reference
   add_numbers(&number1, &number2, &result);

   //Print Values Pass to Reference
   cout << "After  Pass to Reference :  Number # 1=" << number1 << ",  Number # 2=" << number2 << ", Result # :" << result << "\n";

   getch();
   return 0;
}
