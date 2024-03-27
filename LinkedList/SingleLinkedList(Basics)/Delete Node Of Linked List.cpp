/*
Problem statement
You are given the head of a linked list ‘list’ of size ‘N’.



Your task is to delete the linked list's last node and return the linked list's head.



Example:
Input: ‘N’ = 4, ‘list’ = 4 -> 2 -> 5 -> 1

Output: 4 2 5

Explanation: 
After deleting the last node, the Linked List is 4 -> 2 -> 5.
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
4
4 2 5 1
Sample Output 1 :
4 2 5
Explanation Of Sample Input 1:
Input: ‘N' = 4, ‘list’ = 4 -> 2 -> 5 -> 1

Output: 4 2 5

Explanation: 
After deleting the last node, the Linked List is 4 -> 2 -> 5.
Sample Input 2:
5
4 3 2 1 5
Sample Output 2:
4 3 2 1
Explanation Of Sample Input 2:
Input: ‘N’ = 5, ‘list’ = 4 -> 3 -> 2 -> 1 -> 5

Output: 4 3 2 1

Explanation: 
After deleting the last node, the Linked List is 4 -> 3 -> 2 -> 1.


Expected Time Complexity:
Try solving this in O(N).


Constraints:
2 <= 'N' <= 10^4
0 <= list elements <= 10^5

Time Limit: 1 sec
  */
/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node *deleteLast(Node *list){
    Node *temp=list;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    delete temp->next;
    temp->next=NULL;
    
    return list;
    
}
