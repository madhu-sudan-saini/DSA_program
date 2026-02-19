#include<iostream>
using namespace std;

class Test
{
private:
    int *ptr;

public:
    Test(int value)
    {
        ptr = new int(value);
    }
    
    // Deep copy constructor
    Test(const Test &t)
    {
        ptr = new int(*t.ptr);
    }

    // Setter function
    void setValue(int value)
    {
        *ptr = value;
    }

    void show()
    {
        cout << "Value is: " << *ptr << endl;
    }

    
    ~Test()
    {
        delete ptr;
    }
};

int main()
{
    Test t1(10);
    t1.show();       

    Test t2 = t1;     
    t2.setValue(20);  
    t2.show();        

    return 0;
}
