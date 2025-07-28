/*
You are given a stack of integers. Your task is to sort the stack in descending order using recursion, such that the top of the stack contains the greatest element. You are not allowed to use any loop-based sorting methods (e.g., quicksort, mergesort). You may only use recursive operations and the standard stack operations (push, pop, peek/top, and isEmpty).


Examples:
Input: stack = [4, 1, 3, 2]

Output: [4, 3, 2, 1]

Explanation:

After sorting, the largest element (4) is at the top, and the smallest (1) is at the bottom.



Input: stack = [1]

Output: [1]

Explanation:

A single-element stack is already sorted.
  */
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void insertedStack(stack<int>&s,int element){
    if(s.empty()||s.top()<element){
        s.push(element);
        return;
    }
    int top=s.top();
    s.pop();
    insertedStack(s,element);
    s.push(top);
}

void sortedStack(stack<int>s){
    if(s.empty()){
        return ;
    }
    int top=s.top();
    s.pop();
    sortedStack(s);
    insertedStack(s,top);
}

int main()
{
   int n;
   cin>>n;
   vector<int>arr(n);
   for(int i=0;i<n;i++)cin>>arr[i];
   stack<int>s;
   for(int i=0;i<n;i++)s.push(arr[i]);
    sortedStack(s);
    while(!s.empty()){
        int top=s.top();
        s.pop();
        cout<<"elements:"<<top<<endl;
    }
    return 0;
}
