#include<iostream>
using namespace std;
class Test
{
    private:
    int *ptr;

    public:
    Test(int value)
    {
        ptr=new int(value);
    }
    void show()
    {
        cout<<" value is :"<<*ptr<<endl;
    }
};
int main()
{
    Test t1(20);
    t1.show();

    Test t2=t1;//shellow copy(copy the data member of object)
    t2.show();
    return 0;
}