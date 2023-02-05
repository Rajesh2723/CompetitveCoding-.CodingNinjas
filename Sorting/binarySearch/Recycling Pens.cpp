/*
Recycling Pens
Send Feedback
You have 'N' empty pens whose refills have been used up. You have 'R' rupees in your pocket. You have two choices of operations that you can perform each time.
1) Recycle 1 empty pen and get 'K' rupees as a reward.
2) Buy 1 refill for 'C' rupees and combine it with 1 empty pen to make one usable pen.
Your task is to find the maximum number of usable pens that you can get.
For example if you have 'N' = 5 , 'R' = 10 , 'K' = 2 , 'C' = 3. You can recycle one pen and get 2 rupees as a reward so you will have a total of 12 rupees. Now you can buy 4 refills and combine it with 4 pens to make it usable. So your answer is 4.
Input Format :
The first line of the input contains a single integer 'T', denoting the number of test cases. Then the 'T' test case follows.

The first and the only line of each test case consists of 4 non-negative integers 'N', 'R', 'K' and 'C', as described in the problem statement.
Output Format :
For each test case, print a single integer in a new line, denoting the maximum number of usable pens you can get.
Note:
You do not need to print anything. It has already been taken care of. Just implement the given function.
Constraints :
1 <= T <= 10^5
1 <= N <= 10^9
0 <= R <= 10^9
1 <= K <= 10^9
1 <= C <= 10^9

Time limit: 1 sec
Sample Input 1 :
3
10 10 5 5
15 11 3 5
3 20 20 2
Sample Output 1 :
6
7
3
Explanation for Sample input 1 :
In the first test case, you will sell 4 empty pens and you will get 20 rupees so your total money will be 10+20 = 30 and from that, you will buy 6 refills and make 6 usable pens.

In second test case you will sell 8 pens and you will get 8*3=24 rupees and your total money will be 24+11 = 35 and from that, you will buy 7 refills and make 7 usable pens.

In this test case, you have a lot of money to buy but you have only 3 empty pens so you buy 3 refills for 6 rupees and make 3 usable pens.
Sample Input 2 :
3
10 10 1 10
5 0 5 5
6 0 4 2
Sample Output 4 :
1
2
4
Explanation of Sample Input 2 :
In the first test case you can buy 1 refill from the money you have and make 1 usable pen.

In the second test case you can sell 2 empty pens and get 10 rupees and from it, you can buy 2 refills and make 2 usable pens.

In the third test case you can sell 2 empty pens and get 8 rupees and from it, you can buy 4 refills and make 4 usable pens.
*/

bool check(int n, int r, int k,long long int c,long long int barrier){
    
    long long int totalmoney=(long long int)r+(long long int)((n-barrier)*k);
    long long int pro=(long long int)(totalmoney/c);
    if(pro<(barrier)){
 
            return false;
        
    }else{
        
        return true;
        
    }
    
}
int recyclePens(int n, int r, int k, int c ){

	int start=0;
    int end=n;
    int ans=-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(check(n,r,k,c,mid)){
            ans=mid;
            start=mid+1;
        }else{
            end=mid-1;
        }
    }
    return ans;
	
}

#include <iostream>
#include <fstream>
using namespace std;

#include "solution.h"
int main()
{

   int tc;
   cin>>tc;
   
   while(tc--){
      int n,r,k,c;
      cin>>n>>r>>k>>c;
      long long ans = recyclePens(n,r,k,c);
      cout<<ans<<endl;
   }

   return 0;
   
}


