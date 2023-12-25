/*
Dynamic Programming: House Robber (DP 6)
Problem Statement: Dynamic Programming: House Robber (DP 6)

Problem Statement Link: House Robber

A thief needs to rob money in a street. The houses in the street are arranged in a circular manner. Therefore the first and the last house are adjacent to each other. The security system in the street is such that if adjacent houses are robbed, the police will get notified.

Given an array of integers “Arr” which represents money at each house, we need to return the maximum amount of money that the thief can rob without alerting the police.
*/
class Solution {
public:
int f(int index,vector<int>&arr){
    int prev2=0;
    int prev=arr[0];
    int n=arr.size();
    for(int i=1;i<n;i++){
        int pick=arr[i];
        if(i>1)pick+=prev2;//taking the first element
        int notpick=prev; //not taking element (not adding it)
        int cur_i=max(pick,notpick);
        prev2=prev;
        prev=cur_i;
    }
    return prev;

}
    int rob(vector<int>& nums) {
        vector<int>arr1,arr2;
        
    int n=nums.size();
    if(n==1)
       return nums[0];
        for(int i=0;i<n;i++){
            if(i!=0){//not taking first element
                arr1.push_back(nums[i]);
            }
            if(i!=n-1){//not taking the last element
                arr2.push_back(nums[i]);
            }
        }
        int ans1=f(n-1,arr1);
        int ans2=f(n-1,arr2);
        return max(ans1,ans2);
    }
};
