/*
Given root of binary tree, return the Postorder traversal of the binary tree.


Examples:
Input : root = [1, 4, null, 4, 2]

Output : [4, 2, 4, 1]

Explanation :
Input : root = [1, null, 2, 3]

Output : [3, 2, 1]


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
		vector<int> postorder(TreeNode* root){
            vector<int>ans;
           TreeNode*node=root;
           stack<TreeNode*>s;
           while(true){
            if(node!=nullptr){
                s.push(node);
                ans.push_back(node->data);
                node=node->right;
           }else{
            if(s.empty()==true)break;
            node=s.top();
            s.pop();
            node=node->left;
           }
           }
           reverse(ans.begin(),ans.end());
           return ans;
		}
};
