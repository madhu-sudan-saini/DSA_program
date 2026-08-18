class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {

        if(root == NULL)
            return 0;

        queue<pair<TreeNode*, unsigned long long>> q;

        q.push({root, 0});

        unsigned long long maxWid = 0;

        while(!q.empty())
        {
            int currsize = q.size();

            unsigned long long strIndx = q.front().second;
            unsigned long long endIndx = q.back().second;

            maxWid = max(maxWid, endIndx - strIndx + 1);

            for(int i = 0; i < currsize; i++)
            {
                auto curr = q.front();
                q.pop();

                if(curr.first->left)
                {
                    q.push({
                        curr.first->left,
                        curr.second * 2 + 1
                    });
                }

                if(curr.first->right)
                {
                    q.push({
                        curr.first->right,
                        curr.second * 2 + 2
                    });
                }
            }
        }

        return maxWid;
    }
};
