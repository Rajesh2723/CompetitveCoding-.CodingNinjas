/*
Given the root node of a binary search tree (BST) and an integer key. Return the Inorder predecessor and successor of the given key from the provided BST.



Note: key will always present in given BST.



If predecessor or successor is missing then return -1.


Examples:
Input : root = [5, 2, 10, 1, 4, 7, 12] , key = 10

Output : [7, 12]
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
        void inorderTraversal(TreeNode*node,int key,vector<int>&allValuesInorder){
            if(!node)return ;
            inorderTraversal(node->left,key,allValuesInorder);
            allValuesInorder.push_back(node->data);
            inorderTraversal(node->right,key,allValuesInorder);
        }

		vector<int> succPredBST(TreeNode* root,int key){
			 if(!root)return {-1,-1};
             vector<int>ans;
             vector<int>allValuesInorder;
             inorderTraversal(root,key,allValuesInorder);
             int predecessor,successor=-1;
             for(int i=0;i<allValuesInorder.size();i++){
                if(key==allValuesInorder[i]){
                    if(i-1>0)predecessor=i-1;
                   if(i+1<allValuesInorder.size()) successor=i+1;
                }
             }
            if(predecessor>0 and  predecessor<allValuesInorder.size()){
                ans.push_back(allValuesInorder[predecessor]);
            }else{
                ans.push_back(-1);
            }
            if(successor>=0 and  successor<allValuesInorder.size()){
                ans.push_back(allValuesInorder[successor]);
            }else{
                ans.push_back(-1);
            }
            return ans;
		}
};
