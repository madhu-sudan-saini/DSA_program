#include<iostream>
using namespace std;
int main()
{
    int arr[11];
    int i,value,loc;

    for(i=0;i<=9;i++)
    {
        cout<<"enter number "<<i<<" :";
        cin>>arr[i];
    }
    cout<<endl;


    cout<<"enter value to insert:";
    cin>>value;

    cout<<"enter location to insert:";
    cin>>loc;

    loc--;

    cout<<"befor insertion :"<<endl;
    for(i=0;i<=9;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    for(i=9;i>=loc;i--)
    {
        arr[i+1]=arr[i];
    }
    arr[loc]=value;

    cout<<"after insertion :"<<endl;
    for(i=0;i<=10;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}