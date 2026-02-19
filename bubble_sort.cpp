#include<iostream>
using namespace std;
int main()
{
    int arr[10];
    int i,temp;

    for(i=0;i<=9;i++)
    {
        cout<<"enter number "<<i<<" :";
        cin>>arr[i];
    }
    cout<<endl;

    cout<<"befor sorting :"<<endl;
    for(i=0;i<=9;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    for(int i=0;i<=8;i++)
    {
        for(int j=i+1;j<=9;j++)
        {
            if(arr[i]>arr[j])
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }

    cout<<"after sorting :"<<endl;
    for(i=0;i<=9;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl; 

    
    return 0;
}