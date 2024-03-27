/*
Problem statement
You have been given a linked list of integers. Your task is to write a function that deletes a node from a given position, 'POS'.

Note :
Assume that the Indexing for the linked list always starts from 0.

If the position is greater than or equal to the length of the linked list, you should return the same linked list without any change.
Illustration :
The following images depict how the deletion has been performed.
Image-I :


Image-II :


Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1 :
3 4 5 2 6 1 9 -1
3
Sample Output 1 :
3 4 5 6 1 9
Explanation of Sample Output 1 :
The data in the node with index 3 is 2 which has been removed.
Sample Input 2 :
3 4 5 2 6 1 9 -1
0
Sample Output 2 :
4 5 2 6 1 9
Constraints :
0 <= N <= 10^5
POS >= 0

Time Limit: 1sec
Expected Complexity :
Time Complexity  : O(N)
Space Complexity  : O(1)
  */
/****************************************************************
 
    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/

Node *deleteNode(Node *head, int pos)
{
    if (head == NULL) // Check if the list is empty
        return NULL;

    if (pos == 0) // Special case: deleting the head node
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head; // Return the new head
    }

    Node *current = head;
    int count = 0;

    // Traverse to the node just before the position to be deleted
    while (count < pos - 1 && current->next != NULL)
    {
        current = current->next;
        count++;
    }

    // Check if position is valid
    if (current->next == NULL || current->next->next == NULL)
        return head; // Position out of bounds or next node to delete doesn't exist

    Node *temp = current->next; // Node to be deleted
    current->next = temp->next; // Update the link
    delete temp; // Delete the node
    return head; // Return head of modified list
}
