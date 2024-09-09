/*
Given the head of a singly linked list, reverse the list, and return the reversed list.

 

Example 1:


Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
Example 2:


Input: head = [1,2]
Output: [2,1]
Example 3:

Input: head = []
Output: []
 

Constraints:

The number of nodes in the list is the range [0, 5000].
-5000 <= Node.val <= 5000
 

Follow up: A linked list can be reversed either iteratively or recursively. Could you implement both?
  */
#include<bits/stdc++.h>
using namespace std;

struct Node{
    public:
    int data;
    Node*next;  //data members
    
    Node(int data1){
        data=data1;
        next=nullptr;
    }

    Node(int data1,Node *next1){ //constructor
        data=data1;
        next=next1;
    }


};
Node *ReverseLL(Node *head){
    stack<int>st;
    Node *temp=head;
    while(temp!=NULL){
        st.push(temp->data);
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL){
        temp->data=st.top();
        st.pop();
        temp=temp->next;
    }
    return head;
}
void printLinkedList(Node *head){
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main(){
    Node *n=new Node(1);//creating object for that
    n->next=new Node(2);
    n->next->next=new Node(3);
    n->next->next->next=new Node(4);
    cout<< "this is before making Reverse"<<endl;
    printLinkedList(n);
    cout<< "after  making Reverse"<<endl;
    n = ReverseLL(n);
     printLinkedList(n);
    return 0;
}
