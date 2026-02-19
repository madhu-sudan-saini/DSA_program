#include<iostream>
using namespace std;


void selectionsort(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        int minIndex=i;

        for(int j=i+1;j<n;j++)
        {
            if(arr[j] <arr[minIndex])
            {
                minIndex=j;
            }
        }

        swap(arr[minIndex],arr[i]);
    }
}

void printarr(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main()
{
    int arr[6]={1,6,2,5,9,8};
    
    selectionsort(arr,6);
    printarr(arr,6);


    return 0;
}