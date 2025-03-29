1.create dp[n] array first.
2.find dp[1],dp[2],dp[3].by basic observations
3.create general formula.
4.dp[1]...dp[2]..dp[n] using loop and general formula.
5.dp[n] in general is final answer.


#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{   
    int n;
    cin>>n;
    int dp[n]={0};
    
    
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    int first=0;
    dp[0]=max(arr[0],first);
    cout<<"first value:"<<dp[0]<<endl;
    dp[1]=max(dp[0],max(first,arr[1]));
    cout<<"second value:"<<dp[1]<<endl;
    for(int i=2;i<n;i++){
        dp[i]=max(dp[i-1],arr[i]+dp[i-2]);
        cout<<"value at each:"<<dp[i]<<endl;
    }
    cout<<dp[n-1]<<"value of n-1:"<<n-1<<endl;
}
// 5
// 1 -2 3 -4 6

import java.util.*;
public class Main
{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int[]dp=new int[n];
		int[]arr=new int[n];
		
		for(int i=0;i<n;i++){
		    arr[i]=sc.nextInt();
		}
		int first=0;
		dp[0]=Math.max(arr[0],first);
		if(n>1){
		    dp[1]=Math.max(dp[0],Math.max(first,arr[1]));
		}
		for(int i=2;i<n;i++){
		    dp[i]=Math.max(dp[i-1],arr[i]+dp[i-2]);
		}
		System.out.println("dp[n-1] value:"+dp[n-1]);
		sc.close();
	}
}
// 5
// 1 -2 3 -4 6

