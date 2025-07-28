/*
You are given a stack of integers. Your task is to reverse the stack using recursion. You may only use standard stack operations (push, pop, top/peek, isEmpty). You are not allowed to use any loop constructs or additional data structures like arrays or queues.



Your solution must modify the input stack in-place to reverse the order of its elements.


Examples:
Input: stack = [4, 1, 3, 2]

Output: [2, 3, 1, 4]

Input: stack = [10, 20, -5, 7, 15]

Output: [15, 7, -5, 20, 10]
  */
void sortedStack(stack<int>&s){
    if(s.empty()){
        return ;
    }
    int top=s.top();
    s.pop();
    sortedStack(s);
    s.push(top);
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
