#include <iostream>
#include <iomanip>
using namespace std;
#include "Stack.h"
int main ()
{
    MyStack<int> stk1(4);
   for (int i=0; i<50; ++i)
       {
        stk1.push(i+1);
        stk1.show();
        cout << endl;
       }

   cout << endl << "--------------" << endl;

   MyStack<string> stk2(5);
   stk2.push("abc");
   stk2.push("xyzdef");
   stk2.show();
   return 0;
}

