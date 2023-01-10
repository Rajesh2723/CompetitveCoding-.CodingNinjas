/*
Weighted Jobs
Send Feedback
You are given N jobs where every job is represented as:
1. Start Time
2. Finish Time
3. Profit Associated
Find the maximum profit subset of jobs such that no two jobs in the subset overlap.
Input Format:
The first line of input contains an integer denoting N.
Next N lines contains three space separated integers denoting the start time, finish time and the profit associated with the ith job. 
Constraints:
1 ≤ N ≤ 10^6
1 ≤ ai, di, p ≤ 10^6
Output Format:
Output one integer, the maximum profit that can be achieved.
Sample Input 1
4
3 10 20
1 2 50
6 19 100
2 100 200
Sample Output 1
250
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Job{
    int start;
    int finish;
    int profit;
};
bool cmp(Job j1,Job j2){
    return j1.finish<j2.finish;
}
int binarysearch(Job *arr,int index){
    int ans=-1;
    int start=0;
    int end=index-1;
    while(start<=end){
        int mid=(start+end)/2;
        if(arr[mid].finish<=arr[index].start){
            ans=mid;
            start=mid+1;
        }else{
            end=mid-1;
        }
    }
    return ans;
}
ll getprofit(Job *arr,int n){
    ll *dp=new ll[n]();
    dp[0]=arr[0].profit;
    ll profit;
    for(int i=1;i<n;i++){
        ll include=arr[i].profit;
        ll exclude=dp[i-1];
        int betterindex=-1;
        betterindex=binarysearch(arr,i);
        if(betterindex!=-1){
            include+=dp[betterindex];
        }
        dp[i]=max(include,exclude);
    }
    return dp[n-1];
}

int main(){
    
   int n;
   cin>>n;
   Job *arr=new Job[n];
    for(int i=0;i<n;i++){
        cin>>arr[i].start;
        cin>>arr[i].finish;
        cin>>arr[i].profit;
    }
    sort(arr,arr+n,cmp);
     cout<<getprofit(arr,n);
    return 0;
}
