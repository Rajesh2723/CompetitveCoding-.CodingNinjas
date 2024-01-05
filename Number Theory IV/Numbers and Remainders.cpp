/*
Ninja is learning about the mathematical division and remainders. So in curiosity, he forms two lists of numbers ‘ARR’ and ‘REM’ both having ‘N’ numbers. Now Ninja is interested in finding the minimum positive number ‘X’ such that ‘X’ satisfies the following condition for all ‘N’ values:

X % ‘ARR’[i] = ‘REM’[i] (Remainder of X / ARR[i] should be equal to  ‘REM’[i]).
You are given two arrays ‘ARR’ and ‘REM’ both having ‘N’ values corresponding to the numbers and remainders. Your task is to find the smallest positive integer ‘X’ fulfilling the given conditions.

Note:

All numbers in ‘ARR’ are pairwise co-prime.
For Example
For the given if N = ‘3’, ‘ARR’ = [4,5,7] and ‘REM’ = [3,2,2].
The answer will be 107.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 10
1 <= N <= 1000.
1 <= ARR[i] , REM[i] <= 10^5.
For each i,  ARR[i] > REM[i]. 

Time limit: 1 sec
Sample Input 1:
2
3
4 5 7
3 2 2 
3
3 4 5
2 3 1
Sample Output 1:
107
11
Explanation of sample input 1:
For the first test case,
107 is the smallest integer satisfying the condition as :
107 % 4 = 3
107 % 5 = 2
107 % 7 = 2  

For the second test case:
11 is the smallest integer satisfying the condition as :
11 % 3 = 2
11 % 4 = 3
11 % 5 = 1  
Sample Input 2:
2
2
2 13 
0 7 
2
3 17 
1 15
Sample Output 2:
20
49
  */
#define ll long long
ll inverse(ll a,ll b){
    if(b==1){
        return 0;
    }
    ll m=b;
    ll x=0;
    ll y=1;
    while (a > 1) {
        ll q = a / b;
        ll t = b;
        b = a % b;
        a = t;
        t = x;
        x = y - (q * x);
        y = t;
    }
    if(y<0){
        y+=m;
    }
return y;
    }

long long numbersAndRemainders(int n, vector<int> &arr, vector<int> &rem)
{
     ll product=1;
     for(ll i=0;i<n;i++){
         product=product*arr[i];
     }
     ll ans=0;
     for(ll j=0;j<n;j++){
         ll prod=product/arr[j];
         ll inv=inverse(prod,arr[j]);
        ans=ans+1ll*(rem[j]*prod*inv);
     }
     ans=ans%product;
     return ans;
}
