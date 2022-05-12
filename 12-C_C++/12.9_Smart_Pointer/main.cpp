/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <string>
#include <memory>

template <class T>
class SmartPointer{
  T* ptr;
  int *ref;
  
  public:
  SmartPointer(T* p = nullptr){
     if(p != nullptr){
        ptr = p;
        ref = new int(1);
        printf("Created refcount = %d\n", (*this->ref));
     }
  }
  
  SmartPointer(const SmartPointer& rhs){
      this->ptr = rhs.ptr;
      this->ref = rhs.ref;
      ++(*this->ref);
      printf("Copy constructed refcount = %d\n", (*this->ref));
  }
  
  SmartPointer& operator=(const SmartPointer& rhs){
      
      if(this->ptr == rhs.ptr){
          printf("Self assignment\n");
          return *this;
      }
      if(this->ptr != nullptr){
          if(--(*(this->ref)) == 0){
              delete this->ptr;
              delete this->ref;
          }
          this->ptr = rhs.ptr;
          this->ref = rhs.ref;
          ++(*this->ref);
          printf("Assinged refcount = %d\n", (*this->ref));
      }else{
          this->ptr = rhs.ptr;
          this->ref = rhs.ref;
      }
      return *this;
  }
    
    ~SmartPointer(){
        printf("Dctor called\n");
        if(--(*(this->ref)) == 0){
          delete this->ptr;
          delete this->ref;
          printf("Deleted pointer\n");
        }
    }    
};


int main()
{
    int* iter = new int(10);
    int* start = new int(20);
    SmartPointer<int> sp(iter);
    SmartPointer<int> sp2(sp);
    SmartPointer<int> sp3(start);
    sp3 = sp3;
    return 0;
}
