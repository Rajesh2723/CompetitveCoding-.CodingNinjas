/*
Given a root of Binary Tree, perform the boundary traversal of the tree. 



The boundary traversal is the process of visiting the boundary nodes of the binary tree in the anticlockwise direction, starting from the root.



The boundary of a binary tree is the concatenation of the root, the left boundary, the leaves ordered from left-to-right, and the reverse order of the right boundary.

The left boundary is the set of nodes defined by the following:



The root node's left child is in the left boundary. If the root does not have a left child, then the left boundary is empty.


If a node in the left boundary and has a left child, then the left child is in the left boundary.


If a node is in the left boundary, has no left child, but has a right child, then the right child is in the left boundary.


The leftmost leaf is not in the left boundary.


The right boundary is similar to the left boundary, except it is the right side of the root's right subtree. Again, the leaf is not part of the right boundary, and the right boundary is empty if the root does not have a right child.


Examples:
Input : root = [1, 2, 3, 4, 5, 6, 7, null, null, 8, 9]

Output : [1, 2, 4, 8, 9, 6, 7, 3]

Explanation :



Input : root = [1, 2, null, 4, 9, 6, 5, 3, null, null, null, null, null, 7, 8]

Output : [1, 2, 4, 6, 5, 7, 8]

Explanation :


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

class Solution{
public:
    vector <int> boundary(TreeNode* root){
    	vector<int>res;
        if(!root)return res;
        if(!isLeaf(root))res.push_back(root->data);
        addLeft(root,res);
        addLeaf(root,res);
        addRight(root,res);
        return res;
    }
    void addLeft(TreeNode*root,vector<int>&res){
        TreeNode*cur=root->left;
        while(cur){
            if(!isLeaf(cur))
            res.push_back(cur->data);
            if(cur->left)
            cur=cur->left;
            else{
                cur=cur->right;
            }
        }
    }
    bool isLeaf(TreeNode* node) {
        return (!node->left && !node->right);
    }
    void addLeaf(TreeNode*root,vector<int>&res){
       if(isLeaf(root))
       {res.push_back(root->data);
       return;
       }
       if(root->left)addLeaf(root->left,res);
       if(root->right)addLeaf(root->right,res);

    }
     void addRight(TreeNode* root, vector<int>& res) {
        TreeNode* cur = root->right;
        vector<int> tmp;
        while (cur) {
            if (!isLeaf(cur)) tmp.push_back(cur->data);
            if (cur->right) cur = cur->right;
            else cur = cur->left;
        }
        // reverse before adding
        for (int i = tmp.size() - 1; i >= 0; i--) {
            res.push_back(tmp[i]);
        }
    }

};
