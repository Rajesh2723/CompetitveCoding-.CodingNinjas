/*
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100
  */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
         vector<int>mid;
        queue<TreeNode*>q;
        if(!root){
            return ans;
        }
        q.push(root);
        
        int x=0;
        while(!q.empty()){
           
           int level=q.size();
           for(int i=0;i<level;i++){
              TreeNode*  temp=q.front();
            q.pop();
             mid.push_back(temp->val);
           
            
            if(temp->left!=nullptr)
                q.push(temp->left);
                 if(temp->right!=nullptr)
                 q.push(temp->right);
           }
           if(x%2==0)//if current level is not odd then dont reverse output
                ans.push_back(mid);
            else
            {//if odd means reverse the output.
                reverse(mid.begin(),mid.end());
                ans.push_back(mid);
            }
            // mid.clear();
            x+=1;
            
        }
        return ans;
    }
};
