/*
Given the root node of a binary search tree (BST) and a value val to insert into the tree. Return the root node of the BST after the insertion.



It is guaranteed that the new value does not exist in the original BST. Note that the compiler output shows true if the node is added correctly, else false.


Examples:
Input : root = [4, 2, 7, 1, 3] , val = 5

Output : [4, 2, 7, 1, 3, 5]

Explanation :

Below is image where the node 5 is inserted
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root)return new TreeNode(val);
        TreeNode*node=root;
        while(true){
             if(node->data>val){
                if(node->left==nullptr){
                    node->left=new TreeNode(val);
                    break;
                }
                node=node->left;
                
             }else {
                if(node->right==nullptr){
                    node->right=new TreeNode(val);
                    break;
                }
                node=node->right;
                
             }
                
        }
        return root;
    }
};
