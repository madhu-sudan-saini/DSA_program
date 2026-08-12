class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

      vector<int> ans;

      for(int i=0;i<nums1.size();i++)
      {
        int pos= find(nums2.begin(),nums2.end(),nums1[i]) - nums2.begin();

        int greater= -1;

        for(int j=pos+1;j<nums2.size();j++)
        {
            if(nums2[j] > nums1[i])
            {
                greater = nums2[j];
                break;
            }
        }

        ans.push_back(greater);
      }

      return ans;  
    }
};
