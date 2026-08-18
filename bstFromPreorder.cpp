class Solution {
public:

    TreeNode* solve(vector<int>& preorder, int s, int e)
    {
        if(s > e)
            return NULL;

        // First element is root
        TreeNode* root = new TreeNode(preorder[s]);

        int i = s + 1;

        // Find first element greater than root
        while(i <= e && preorder[i] < root->val)
        {
            i++;
        }


        root->left = solve(preorder, s + 1, i - 1);

        root->right = solve(preorder, i, e);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder)
    {
        return solve(preorder, 0, preorder.size() - 1);
    }
};
