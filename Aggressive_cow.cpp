#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isPossible(vector<int>& arr , int N ,int C,int minAlloweddist)
{
   int Cow=1,laststallpos=arr[0];

   for(int i=1;i<N;i++)
   {
    if(arr[i]-laststallpos >= minAlloweddist )
    {
        Cow++;
        laststallpos=arr[i];
    }

    if(Cow==C)
    {
        return true;
    }
   }
   return false;
}
int getDistance(vector<int>& arr , int N ,int Cow)
{

    sort(arr.begin(),arr.end());
    int st=1, end=arr[N-1] - arr[0] , ans=-1;

    while(st <= end)
    {
        int mid=st + (end- st)/2;

        if(isPossible(arr,N,Cow,mid))
        {
            st=mid+1;
            ans=mid;
        }
        else
        {
            end=mid-1;
        }
    }
    return ans;
}
int main() 
{
    int N=5,Cow=3;
    vector<int> arr={1,2,8,4,9};

    cout<<getDistance(arr,N,Cow);
    return 0;
}
