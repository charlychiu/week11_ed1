#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

template <typename T>
class MyStack {
  private: // information(data) hidding(encapsulation)
    T* aDisk;
    int  capacity;
    int  top;
    char name;
  public: // interface: public method(member function)
    void pop();
    void push(T e);
    T  first();
    int  size();
    MyStack();
    MyStack(int n);
    void init(int n);
    ~MyStack();
    MyStack(const MyStack& stk);
    MyStack& operator=(const MyStack& stk);
    bool operator==(const MyStack& stk);
    bool operator>(const MyStack& stk);
    bool operator!=(const MyStack& stk);
    bool operator>=(const MyStack& stk);
    bool operator<(const MyStack& stk);
    bool operator<=(const MyStack& stk);
    void show();
};
template <typename T>
void MyStack<T>::pop() {
    if ( top <= 0) return;
    aDisk[top] = T();
    --top;
}
template <typename T>
void MyStack<T>::push(T e) {
    if ( top+1>=capacity )
       {
         T* aTmp = new T[2*capacity];
         for ( int i=0; i<capacity; ++i )
             { aTmp[i] = aDisk[i];
             }
         delete [] aDisk;
         aDisk = aTmp;
         capacity *=2;
        }
    ++top;
    aDisk[top] = e;
}
template <typename T>
T MyStack<T>::first() {
    return aDisk[top];
}
template <typename T>
int MyStack<T>::size() {
    return top+1;
}
template <typename T>
MyStack<T>::MyStack() {
    aDisk = NULL;
    top = -1;
    capacity = 0;
}
template <typename T>
MyStack<T>::MyStack (int n) {
     aDisk = NULL;
     init(n);
}
template <typename T>
void MyStack<T>::init(int n) {
     top = -1;
     capacity = n;
     delete [] aDisk;
     aDisk = new T[n];
     for ( int i=0; i<n; ++i )
         { aDisk[i] = T();
         }
}

template <typename T>
MyStack<T>::~MyStack() {
     delete [] aDisk;
}
template <typename T>
MyStack<T>::MyStack(const MyStack& stk) {
     top = stk.top;
     name = stk.name;
     capacity = stk.capacity;
     aDisk = new T[capacity];
     for ( int i=0; i<capacity; ++i)
         { aDisk[i] = stk.aDisk[i];
         }
}
template <typename T>
MyStack<T>& MyStack<T>::operator=(const MyStack& stk) {
     top = stk.top;
     name = stk.name;
     capacity = stk.capacity;
     delete [] aDisk;
     aDisk = new T[capacity];
     for ( int i=0; i<capacity; ++i)
         { aDisk[i] = stk.aDisk[i];
         }
     return *this;
}
template <typename T>
bool MyStack<T>::operator==(const MyStack& stk){
   for ( int i=0; i<capacity; ++i)
       { if ( aDisk[i]!=stk.aDisk[i] )
            { return false;
            }
       }
   return true;
}
template <typename T>
bool MyStack<T>::operator>(const MyStack& stk){
    for ( int i=0;i<capacity; ++i)
        { if ( aDisk[i]!=stk.aDisk[i])
            { return aDisk[i]>stk.aDisk[i];
            }
        }
    return false;
}
template <typename T>
bool MyStack<T>::operator!=(const MyStack& stk){
   return !operator==(stk);
}
template <typename T>
bool MyStack<T>::operator>=(const MyStack& stk){
   return (operator>(stk) || operator==(stk));
}
template <typename T>
bool MyStack<T>::operator<(const MyStack& stk){
   return !operator>=(stk);
}
template <typename T>
bool MyStack<T>::operator<=(const MyStack& stk){
   return !operator>(stk);
}
template <typename T>
void MyStack<T>::show() {
     cout << "capacity" << capacity << endl;
     for ( int i=0; i<=top; ++i )
         { cout << "[" << aDisk[i] << "]";
         }
}
#endif // STACK_H_INCLUDED
