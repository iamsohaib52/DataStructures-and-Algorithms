#include <iostream>
#include<conio.h>

using namespace std;

int main() {

   // Declare Variables
   int a = 10;
   int *pa = &a;

   char b = 'x';
   char *pb = &b;

   float c = 10.01;
   float *pc = &c;

   double d = 10.01;
   double *pd = &d;

   long e = 10.01;
   long *pe = &e;

   cout << "Pointer C++ Example Program : Print Size of Different types Using sizeof\n";

   cout << "\n[sizeof(a)   ]: = " << sizeof (a);
   cout << "\n[sizeof(*pa) ]: = " << sizeof (*pa);

   cout << "\n[sizeof(b)   ]: = " << sizeof (b);
   cout << "\n[sizeof(*pb) ]: = " << sizeof (*pb);

   cout << "\n[sizeof(c)   ]: = " << sizeof (c);
   cout << "\n[sizeof(*pc) ]: = " << sizeof (*pc);

   cout << "\n[sizeof(d)   ]: = " << sizeof (d);
   cout << "\n[sizeof(*pd) ]: = " << sizeof (*pd);

   cout << "\n[sizeof(e)   ]: = " << sizeof (e);
   cout << "\n[sizeof(*pe) ]: = " << sizeof (*pe);

   return 0;
}
