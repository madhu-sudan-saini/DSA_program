
class Solution {
public:

    TreeNode* built(vector<int>& nums , int s,int e)
    {
        if(s > e)
        {
            return NULL;
        }

        int mid = s+(e-s)/2;

        TreeNode* root=new TreeNode(nums[mid]);

        root->left = built(nums,s,mid-1);
        root->right = built(nums,mid+1,e);

        return root;

    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return built(nums,0,nums.size()-1);
    }
};
