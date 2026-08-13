class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

      int start=0,gasSum=0,costSum=0;
      int currGas=0 ;

      for(int i=0;i<gas.size();i++)
      {
        gasSum+=gas[i];
        costSum+=cost[i];
      } 

      if(gasSum < costSum)
      {
        return -1;
      }

      for(int i=0;i<gas.size();i++)
      {
        currGas+=gas[i]-cost[i];

        if(currGas < 0)
        {
            currGas=0;
            start=i+1;
        }
      }
      return start;
    }
};
