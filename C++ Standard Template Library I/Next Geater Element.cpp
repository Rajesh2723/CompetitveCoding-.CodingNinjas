/*
Next Geater Element
Send Feedback
Given an array, print the Next Greater Element (NGE) for every element. The Next greater Element for an element x, is the first greater element on right side of x in the array. Elements for which no greater element exist, consider next greater element as -1.
Input format :

Line 1 : Size of input array

Line 2 : Array elements (separated by space)

Constraints:
Time Limit: 1 second
Size of input array lies in the range: [1, 1000000]
Sample Input
5
3  8  1  2  0
Sample Output
8 -1  2 -1 -1
*/
#include <vector>
#include<bits/stdc++.h>
vector<int> nextGreaterElement(vector<int> input) {
	int size=input.size();
    vector<int>ans(size);
    stack<int>s;
    s.push(-1);
    for(int i=size-1;i>=0;i--){
        int cur=input[i];
        while(!s.empty()&&s.top()<=cur)s.pop();
        
        if(s.empty())ans[i]=-1;
        else
            ans[i]=s.top();
        s.push(cur);
    }
    return ans;
}
#include <iostream>
using namespace std;
#include "solution.h"

int main() {
    int size, temp;
    cin >> size;

    vector<int> input;

    for(int i = 0; i < size; i++) {
	cin >> temp;
        input.push_back(temp);
    }

    vector<int> output = nextGreaterElement(input);
    for(int i = 0; i < output.size(); i++) {
	    cout << output[i] << " ";
    }
}
