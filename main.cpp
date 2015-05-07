#include <iostream>
#include <iomanip>
using namespace std;
#include "Stack.h"
int main ()
{
   MyStack<string> stk2(5);
   stk2.push("abc");
   stk2.push("xyzdef");
   stk2.show();
   return 0;
}

