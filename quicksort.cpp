#include<iostream>
using namespace std;
int partition(int arr[],int start,int end)
{
	int idx=start-1,pivot=arr[end];
	for(int j=start;j<end;j++)
	{
		if(arr[j]<=pivot)
		{
			idx++;
			swap(arr[j],arr[idx]);
		}
	}
	idx++;
	swap(arr[end],arr[idx]);
	return idx;
}
void quicksort(int arr[],int start,int end)
{
		if(start<end)
		{
			int pivIdx=partition(arr,start,end);
			quicksort(arr,start,pivIdx-1);//left quicksort
			quicksort(arr,pivIdx+1,end);//rigth quicksort
		}
}
int main()
{
	int arr[]={12,31,35,8,32,17};
	int size=sizeof(arr)/sizeof(int);
	quicksort(arr,0,size-1);
	for(int i=0;i<6;i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}