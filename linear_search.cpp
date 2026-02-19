#include<iostream>
using namespace std;
int main()
{
    int arr[10];
    int value,i ,loc=-1;

    for(i=0;i<=9;i++)
    {
        cout<<"enter number "<<i<<" :";
        cin>>arr[i];
    }
    cout<<endl;

    cout<<"enter value to find :";
    cin>>value;

    for(i=0;i<=9;i++)
    {
        if(arr[i]==value)
        {
            loc=i+1;
            break;
        }
    }

    if(loc==-1)
    {
        cout<<"element not found";
    }
    else
    {
        cout<<"element found at position :"<<loc<<endl;
    }

    
    return 0;
}