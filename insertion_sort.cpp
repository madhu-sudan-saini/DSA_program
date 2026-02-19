#include<iostream>
using namespace std;

void insertionsort(int arr[],int n)
{
    for(int i=1;i<n;i++)
    {
        int curr=arr[i];
        int prev=i-1;

        while(prev >= 0 && arr[prev] > curr)
        {
            arr[prev+1]=arr[prev];
            prev--;
        }
        arr[prev+1]=curr;
    }
}
void printarr(int arr[],int n)
{
    for(int i=0;i<=n-1;i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main()
{
    int arr[5]={2,8,3,6,0};
    insertionsort(arr,5);
    printarr(arr,5);
    return 0;
}