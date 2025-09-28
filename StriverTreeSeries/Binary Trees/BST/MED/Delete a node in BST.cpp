/*
Given the root node of a binary search tree (BST) and a value key. Return the root node of the BST after the deletion of the node with the given key value.



Note: As there can be many correct answers, the compiler returns true if the answer is correct, otherwise false.


Examples:
Input : root = [5, 3, 6, 2, 4, null, 7] , key = 3

Output : [5, 4, 6, 2, null, null, 7]
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

    TreeNode*findMin(TreeNode*node){
        while(node->left){
            node=node->left;
        }
        return node;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
       if(!root)return nullptr;
       if(key<root->data){
        root->left=deleteNode(root->left,key);
       }else if(key>root->data){
        root->right=deleteNode(root->right,key);
       }else{
        if(!root->right && !root->left){
            delete root;
            return nullptr;
        }
        if(!root->left){
            TreeNode*temp=root->right;
            delete root;
            return temp;
        }
        if(!root->right){
            TreeNode*temp=root->left;
            delete root;
            return temp;
        }
        TreeNode*successor=findMin(root->right);
        root->data=successor->data;
        root->right=deleteNode(root->right,successor->data);
       }
       return root;
    }
};
