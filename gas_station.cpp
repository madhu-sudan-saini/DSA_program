#include <iostream>
#include<vector>
using namespace std;

int gasStation(vector<int>& gas,vector<int>& cost)
{
    int totalGas=0;
    int totalCost=0;
    for(int i=0;i<gas.size();i++)
    {
        totalGas+=gas[i];
        totalCost+=cost[i];
    }

    if(totalGas < totalCost)
    {
        return -1;
    }

    int start=-1;
    int currGas=0;

    for(int i=0;i<gas.size();i++)
    {
        currGas+=gas[i]-cost[i];

        if(currGas < 0 )
        {
            start++;
            currGas=0;
        }
    }

    return start+1;
}

int main() 
{
    vector<int> gas={1,2,3,4,5};
    vector<int> cost={3,4,5,1,2};

    cout<<gasStation(gas,cost);

    return 0;
}
