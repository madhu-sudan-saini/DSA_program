class Solution {
public:

    void Inorder(TreeNode* root, vector<int>& ans)
    {
        if(root == NULL)
            return;

        Inorder(root->left, ans);
        ans.push_back(root->val);
        Inorder(root->right, ans);
    }

    void change(TreeNode* root, vector<int>& ans, int& index)
    {
        if(root == NULL)
            return;

        change(root->left, ans, index);

        root->val = ans[index];
        index++;

        change(root->right, ans, index);
    }

    void recoverTree(TreeNode* root) {

        vector<int> ans;

        Inorder(root, ans);

        sort(ans.begin(), ans.end());

        int index = 0;

        change(root, ans, index);
    }
};
