/*
Given a binary tree root, find if it is height-balanced or not.



A tree is height-balanced if the difference between the heights of left and right subtrees is not more than one for all nodes of the tree. 


Examples:
Input : [3, 9, 20, null, null, 15, 7]

Output : Yes
  */
 int f(TreeNode*root){
        if(!root)return 0;
        int maxi1=f(root->left);
        if(maxi1==-1)return -1;
        int maxi2=f(root->right);
        if(maxi2==-1)return -1;
        if(abs(maxi1-maxi2)>1)return -1;
        return 1+max(maxi1,maxi2);
    }
    bool isBalanced(TreeNode *root){
        return f(root)!=-1;
    }
