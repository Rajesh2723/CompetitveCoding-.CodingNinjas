/*
Given a root of binary search tree and a key(node) value, find the floor and ceil value for that particular key value.



Floor Value Node: Node with the greatest data lesser than or equal to the key value. 


Ceil Value Node: Node with the smallest data larger than or equal to the key value.


If a particular floor or ceil value is not present then output -1.


Examples:
Input : root = [8, 4, 12, 2, 6, 10, 14] , key = 11

Output : [10, 12]
  */
/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution{	
	public:
		vector<int> floorCeilOfBST(TreeNode* root,int key){
			int floorValue=-1,ceilValue=-1;
            TreeNode*node=root;
            while(node){
                if(node->data==key){
                    floorValue=ceilValue=node->data;
                    break;
                }else if(node->data>key){
                    ceilValue=node->data;
                    node=node->left;
                }else{
                    floorValue=node->data;
                    node=node->right;
                }
            }
            return {floorValue,ceilValue};
		}
};
