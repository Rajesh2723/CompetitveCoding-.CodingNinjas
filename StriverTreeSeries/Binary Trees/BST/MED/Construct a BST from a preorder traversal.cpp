/*
Given an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree), construct the tree and return its root.



It is guaranteed that it is always possible to find a binary search tree with the given requirements for the given test cases.



Note : As there can be many possible correct answers, the compiler outputs true if the solution is correct, else false.


Examples:
Input : preorder = [8, 5, 1, 7, 10, 12]

Output : [8, 5, 10, 1, 7, null, 12]
  */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
       if(preorder.empty())return nullptr;
       TreeNode*root=new TreeNode(preorder[0]);
       stack<TreeNode*>s;
       s.push(root);
       for(int i=1;i<preorder.size();i++){
        TreeNode*node=s.top();
        TreeNode*child=new TreeNode(preorder[i]);
        //finding the right parent for the current node
        while(!s.empty() and s.top()->data<preorder[i]){
            node=s.top();
            s.pop();
        }
        if(node->data<preorder[i]){
            node->right=child;
        }else{
            node->left=child;
        }
        s.push(child);
       }
       return root;
    }
};
