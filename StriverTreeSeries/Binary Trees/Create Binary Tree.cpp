/*
Problem statement
Given an array 'arr' that contains 7 integers representing the values of nodes in a binary tree. This represents level order. The first element of the array represents the value of the root node.



Your objective is to construct a binary tree using the remaining 6 elements of the array, creating nodes for each of these values and return root node.



For example:
arr = [11, 22, 3, 54, 15, 23, 21]
The 7 node binary tree is represented below.

Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
1 2 3 4 5 6 7
Sample Output 1:
1
Explanation Of Sample Input 1:
The 7 node binary tree is represented below.

Sample Input 2:
11 22 3 54 15 23 21
Sample Output 2:
11
Constraints:
arr.length = 7
1<=arr[i]<=100
Time Limit: 1 sec
  */
/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *left, *right;
    Node()
    {
        this->data = 0;
        left = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->left = NULL;
        this->right = NULL;
    }
    Node(int data, Node* left, Node* right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};
*/

Node* createTree(vector<int>&arr){

   

    Node* root = new Node(arr[0]);

    root->left = new Node(arr[1]);

    root->right= new Node(arr[2]);

    root->left->left = new Node(arr[3]);

    root->left->right = new Node(arr[4]);

    root->right->left = new Node(arr[5]);

    root->right->right= new Node(arr[6]);

 

    return root;

}
