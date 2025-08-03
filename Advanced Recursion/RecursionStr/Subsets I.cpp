/*
Given an array nums of n integers.Return sum of all subsets of the array nums.



Output can be printed in any order.


Examples:
Input : nums = [2, 3]

Output : [0, 2, 3, 5]

Explanation :

When no elements is taken then Sum = 0.

When only 2 is taken then Sum = 2.

When only 3 is taken then Sum = 3.

When element 2 and 3 are taken then sum = 2+3 = 5.

Input : nums = [5, 2, 1]

Output : [0, 1, 2, 3, 5, 6, 7, 8]

Explanation :

When no elements is taken then Sum = 0.

When only 5 is taken then Sum = 5.

When only 2 is taken then Sum = 2.

When only 1 is taken then Sum = 1.

When element 2 and 1 are taken then sum = 2+1 = 3.
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Paste your Solution class here
class Solution {
public:
    void f(vector<int>&ans,vector<int>temp,vector<int>&nums,int index){
        if(index==nums.size()){
            int sum=accumulate(temp.begin(), temp.end(), 0);
            temp.push_back(sum);
            ans.push_back(sum);
            return;
        }
        temp.push_back(nums[index]);
        f(ans,temp,nums,index+1);
        temp.pop_back();
        f(ans,temp,nums,index+1);
    }

    vector<int> subsets(vector<int>& nums) {
       vector<int>ans;
        vector<int>temp;
        f(ans,temp,nums,0);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

int main() {
    Solution s;

    // Example input
    vector<int> nums = { 2, 3};

    // Get all subsets
    vector<int> result = s.subsets(nums);

    // Print subsets
    cout << "Subsets are:\n";
   
        for (auto &num : result) {
            cout << num << " ";
        }

    return 0;
}
