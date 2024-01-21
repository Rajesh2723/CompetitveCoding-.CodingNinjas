/*
 Problem statement
A number is called super-prime if it has exactly two distinct prime divisors

Example 10 , 6

You are supposed to find the count of super-prime numbers between 1 and N (inclusive).

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= N <= 10^6
Sample Input 1:
10
Sample Output 1:
2
Sample Input 2:
25
Sample Output 2:
10
Explanation:
The super-primes are: 6, 10, 12, 14, 15, 18, 20, 21, 22, 24
*/
 /*
  void* memset(void* ptr, int value, size_t num);
ptr: Pointer to the block of memory to fill.
value: Value to be set. It is passed as an int, but it is converted to an unsigned char when stored in the memory.
num: Number of bytes to be set to the value.
*/

#include<bits/stdc++.h>
using namespace std;
int solve(int n){
    bool isPrime[n+1];
    memset(isPrime,true,sizeof(isPrime));// used to set a block of memory to a specific value.
    int primeCount[n+1];
    memset(primeCount,0,sizeof(primeCount));
    for(int i=2;i<=n;i++){
        if(isPrime[i]==true){
            for(int j=2;j*i<=n;j++){//i=2 it takes 2,4,6,8,10
             //i=3 it takes 6,
             //i=4 it takes 8
             //i=5 it takes 10
             //6 appears twice and 10 also .it returns count=2
                isPrime[i*j]=false;
                primeCount[i*j]++;
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(primeCount[i]==2){
            ans++;
        }
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    cout<<solve(n)<<endl;
}
//  #include<bits/stdc++.h>
//  using namespace std;

// int getPrime(int n){
//     int ans=0;
//     for(int i=2;i<=n;i++){
//         int num=i;
//         int cur=0;
//         if(num%2==0){
//             cur=1;
//         }
//         while(num%2==0){
//             num/=2;
//         }
//         for(int i=3;i<=sqrt(num);i=i+2){
//             if(cur%i==0){
//                 cur+=1;
//             }
//             while(num%i==0){
//                 num=num/i;
//             }

//         }
//         if(num>2){
//             cur+=1;
//         }
//         if(cur==2){
//             ans+=1;
//         }

//     }
//     return ans;
// }

// int main(){
//     int n;
//     cin>>n;
//     cout<<getPrime(n)<<endl;
    
// }
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
    
//    int t;
//    cin>>t;
//    while(t--){
//        int n;
//        cin>>n;
//        int count=0;
//        int countR=0;
//        for(int i=1;i<=n;i++){
//            for(int j=2;j*j<=n;j++){
//                if(i%j==0){
//                    count++;
//                }
//            }
          
//        }
//         if(count==2){
//                countR++;
//            }
//        cout<<countR<<endl;
//    }
//     return 0;
// }
