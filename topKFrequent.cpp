class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        vector<int> ans;

        map<int,int> freq;

        for(int i=0;i<nums.size();i++)
        {
            freq[nums[i]]++;
        }

        priority_queue<pair<int,int>> pq;

        for(auto& val : freq)
        {
            pq.push({val.second,val.first});
        }

        for(int i=0;i<k && !pq.empty();i++)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
