class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {

        int count = 0;

        queue<pair<int, int>> q;

        for(int i = 0; i < tickets.size(); i++)
        {
            q.push({tickets[i], i});
        }

        while(!q.empty())
        {
            auto p = q.front();
            q.pop();

            int ticket = p.first;
            int index = p.second;

            ticket--;
            count++;

            // Person k has finished buying tickets
            if(index == k && ticket == 0)
            {
                return count;
            }

            if(ticket > 0)
            {
                q.push({ticket, index});
            }
        }

        return count;
    }
};
