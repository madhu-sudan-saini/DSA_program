class Solution {
public:

    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int &preIndx,int Insrt,int InEnd)
    {
        if(Insrt > InEnd)
        {
            return NULL;
        }

        int rootValue=preorder[preIndx];
        preIndx++;

        TreeNode* root=new TreeNode(rootValue);

        int pos=Insrt;

        while(inorder[pos] != rootValue)
        {
            pos++;
        }

        root->left=solve(preorder,inorder,preIndx,Insrt,pos-1);
        root->right=solve(preorder,inorder,preIndx,pos+1,InEnd);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

           int preIndx=0; 
        return solve(preorder,inorder,preIndx,0,inorder.size()-1);
    }
};
