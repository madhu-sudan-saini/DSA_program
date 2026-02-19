#include<iostream>
using namespace std;

class Base
{
  public:
  
  virtual void show()
  {
    cout<<"base class called"<<endl;
  }
};

class Derived : public Base
{
  public:
  void display()
  {
    cout<<"derived class called "<<endl;
  }
};

int main()
{
  Base* b=new Derived;  //upcasting
  
  Derived* d=dynamic_cast<Derived*>(b); //downcasting
  
  if(d != NULL)
  {
    cout<<"cast is sucessfully"<<endl;
    d->display();
  }
  else
  {
    cout<<"cast is unsucessfully"<<endl;
  }
  
  return 0;
}