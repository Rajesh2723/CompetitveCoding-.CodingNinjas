/*
Given root of binary tree, return the preorder traversal of the binary tree.


Examples:
Input : root = [1, 4, null, 4 2]

Output : [1, 4, 4, 2]

Explanation :



Input : root = [1]

Output : [1]

Explanation : Only root node is present.
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
		vector<int> preorder(TreeNode* root){
	       vector<int>ans;
           TreeNode*node=root;
           stack<TreeNode*>s;
           while(true){
            if(node!=nullptr){
                s.push(node);
                ans.push_back(node->data);
                node=node->left;
           }else{
            if(s.empty()==true)break;
            node=s.top();
            s.pop();
            node=node->right;
           }
           }
           return ans;
		}
};
