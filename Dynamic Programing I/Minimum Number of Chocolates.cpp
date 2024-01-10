/*
Problem statement
Miss. Noor Rashid is a teacher. She wants to give some chocolates to the students in her class. All the students sit in a line, and each of them has a score according to performance. Noor wants to give at least one chocolate to each student. She distributes chocolates to them such that If two students sit next to each other, then the one with the higher score must get more chocolates. Miss. Noor wants to save money, so she wants to minimize the total number of chocolates.

Note :
When two students have an equal score, they are allowed to have a different number of chocolates. 
Detailed explanation ( Input/output format, Notes, Images )
Constraints
1 <= N <= 10^5
1 <= score <= 10^5

Time Limit: 1 sec
Sample Input 1 :
4
1 4 4 6
Sample Output 1 :
6
Explanation:
One of the ways in which the chocolates can be distributed, such Noor has to give minimum number of chocolates, are: The first student can be given one chocolate, second student can be given two chocolates, third student can be one chocolate and fourth can be given two chocolates.  
Sample Input 2 :
3
8 7 5
Sample Output 2 :
6
  */
#include<bits/stdc++.h>

int getMin(int *arr, int n)
{
	 int ans=0;
	 vector<int>result(n+1,1);
	 for(int i=1;i<n;i++){
		 if(arr[i]>arr[i-1]){//if greater add result of previous[i-1]+1 for that
			 result[i]=result[i-1]+1;
		 }
	 }
	 for(int i=n-2;i>=0;i--){
		  if(arr[i]>arr[i+1] && result[i]<=result[i+1]){
			  result[i]=result[i+1]+1;
		  }
	 }
	for(int i=0;i<n;i++)
    {
        ans+=result[i];
    }   
    
	 return ans;
}
