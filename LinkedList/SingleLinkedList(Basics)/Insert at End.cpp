/*
Problem statement
There exists a linked list of size 'n' with nodes containing integer values. You are given an integer, which you have to insert at the end of the list.



Note : You have to return the head of the linked list after insertion.



EXAMPLE:
Input :
‘k’ = 5
list = [1, 2, 3, 4]
Output: [1, 2, 3, 4, 5]

The 5th node, which is '5' has been inserted behind '4' which was the end of the list.
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
4 28
51 54 23 31 
Sample Output 1:
51 54 23 31 28 
Explanation Of Sample Input 1 :
The 5th node, which is '28' has been inserted behind '31' which was the end of the list.
Sample Input 2 :
5 27
24 76 65 54 40 
Sample Output 2 :
24 76 65 54 40 27 
Constraints :
1 <= 'n' <= 10^4
1 <= 'a[i]',k <= 10^9 where a[i] are the values in list and k is the value being added.

Time Limit: 1 sec
Expected Complexity :
Time Complexity : O(N)
Space Complexity : O(1)
  */
/************************************************************

    Following is the linkedList class structure:

    class Node {
    public:
        int data;
        Node *next;

        Node(int val) {
            this->data = val;
            next = NULL;
        }
    };

************************************************************/

Node* insertEnd(Node* head, int k) {
    Node*last=new Node(k);
  if(head==NULL){
      return last;
  }
    Node*tail=head;
     
    while(tail->next!=NULL){
        tail=tail->next;
    }
   
    tail->next=last;
    // last->next=NULL;
     return head;
}
