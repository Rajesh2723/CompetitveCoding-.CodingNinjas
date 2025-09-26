/*
Return the number of nodes in a binary tree given its root.



Every level in a complete binary tree possibly with the exception of the final one is fully filled, and every node in the final level is as far to the left as it can be. At the last level h, it can have 1 to 2h nodes inclusive.


Examples:
Input : root = [1, 2, 3, 4, 5, 6]

Output : 6

Explanation :



Input : root = [1, 2, 3, 4, 5, 6, 7, 8, 9]

Output : 9

*/
class Solution {
public:
    int countNodes(TreeNode* root) { 
        int numberOfNodes=0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode*node=q.front();
                q.pop();
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
                numberOfNodes++;
            }
        }
        return numberOfNodes;
    }
};
