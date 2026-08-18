
class Solution {
public:

    int solve(TreeNode* root,int &ans)
    {
        if(root==NULL)
        {
            return 0;
        }

        int left=solve(root->left,ans);
        int right=solve(root->right,ans);

        left=max(0,left);
        right=max(0,right);

        ans=max(ans,left+right+root->val);

        return  root->val+max(left,right);
    }
    int maxPathSum(TreeNode* root) {

      int ans=INT_MIN;
      solve(root,ans);
      return ans;  
    }
};
