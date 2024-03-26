/*
Problem statement
You are given a singly linked list of length ’n’ . Your task is to delete the head of a linked list.



For Example:-
Input: 5 -> 8 -> 3 -> 7 -> 9

Output: 8 -> 3 -> 7 -> 9

Explanation: The head of the given list is at 5. After deletion of head, new list is 8 -> 3 -> 7 -> 9.


Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:-
4
3 1 8 7
Sample Output 1:-
1 8 7
Explanation of sample input 1:-
Given list: 3 -> 1 -> 8 -> 7
Head of the given list is at 3. 
After deletion, updated list is 1 -> 8 ->7
Sample Input 2:-
3
1 3 5
Sample Output 2:-
3 5
Constraints:-
1 <= ‘n’ <= 10^5
1 <= 'data' <= 10^9

where 'data' is the values of node in a linked list.
Time Limit: 1 sec
  */
/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node * deleteHead(Node *head) {

     head=head->next;
     return head;
}
