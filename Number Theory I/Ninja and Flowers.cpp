/*
 Problem statement
Ninja wants to get N flowers and he will pay i + 1 amount of money for the Ith flower, example (if n=3 he will pay {2,3,4})

Now he wants to pack these N flowers in boxes of different colours. With one condition if the cost of a flower is a prime divisor of another flower they needed to be of a different colour.

As we know that ninja is a little money minded he wants to minimize the number of different colours of boxes that he needs.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= N <= 2*10^5
Sample Input:
4
Sample Output:
2
1 3
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> primeNumbersTillN(int n) 
{ 
     vector<bool> prime(n+1, true);
               
       vector<int> ans1,ans2;
        vector<int>result;
        //  ans1.push_back(2);
        for(int i = 2; i*i<= n; i++)//pairs are present before and after sqrt(n) so we reduced the iterations
        {
          if (prime[i]) {
              
            for (int j = i * i; j <= n;
                 j = j + i) // check for multiples like so that elements are
                            // decreased of checking
              prime[j] = 0; // marked false
          }
        }

        for (int i = 2; i <= n; i++)
        {
                if (prime[i]){
                         ans1.push_back(i);
                }else{
                        ans2.push_back(i);
                }
               
        }
        result.push_back(min(ans1.size(),ans2.size()));
        result.push_back(max(ans1.size(),ans2.size()));
        return result;
}
int main(){
    
   int n;
   cin>>n;
    vector<int>ans=primeNumbersTillN(n+1);
    cout<<2<<endl;
    for(auto x:ans){
        cout<<x<<" ";
    }


    return 0;
}
