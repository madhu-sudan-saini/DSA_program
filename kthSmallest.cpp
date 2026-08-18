class Solution {


    void Inorder(TreeNode* root,vector<int>& v)
    {

        if(root==NULL)
        {
            return;
        }

        Inorder(root->left,v);
        v.push_back(root->val);
        Inorder(root->right,v);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        
        vector<int> v;

        Inorder(root,v);

        return v[k-1];
 
    }
};
