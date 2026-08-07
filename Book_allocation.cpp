#include <iostream>
#include<vector>
using namespace std;

bool isValid(vector<int>& arr,int n,int m,int maxAllocatedPage)
{
    int stu=1,page=0;
    for(int i=0;i<n;i++)
    {

        if(arr[i] > maxAllocatedPage)
        {
            return false;
        }
        if(page + arr[i] <= maxAllocatedPage)
        {
            page=page+arr[i];
        }
        else
        {
            stu++;
            page=page+arr[i];
        }
    }
    return stu > m ? false : true;
}
int allocatBooks(vector<int>& arr,int n,int m)
{
    if(m > n)
    {
        return 0;
    }

    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i]; // find range
    }

    int ans=-1;
    int st=0,end=sum;
    while(st < end)
    {
        int mid=st+(end-st)/2;

        if(isValid(arr,n,m,mid))
        {
            ans=mid;
            end=mid-1;
        }
        else
        {
            st=mid+1;
        }
    }
    return ans;
}
int main() 
{
    vector<int> arr={2,1,3,4};
    int n=4,m=2;

    cout<<allocatBooks(arr,n,m); // T.C -> o(log n * n)
    return 0;
}
