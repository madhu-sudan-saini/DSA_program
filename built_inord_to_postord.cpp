class Solution {
public:

    TreeNode* solve(vector<int>& inorder, vector<int>& postorder,
                    int& postIndex, int inStart, int inEnd)

        if(inStart > inEnd)
        {
            return NULL;
        }


        int rootValue = postorder[postIndex];
        postIndex--;

        TreeNode* root = new TreeNode(rootValue);

        int pos = inStart;

        while(inorder[pos] != rootValue)
        {
            pos++;
        }

        root->right = solve(inorder, postorder,
                            postIndex, pos + 1, inEnd);

        root->left = solve(inorder, postorder,
                           postIndex, inStart, pos - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        int postIndex = postorder.size() - 1;

        return solve(inorder, postorder,
                     postIndex, 0, inorder.size() - 1);
    }
};
