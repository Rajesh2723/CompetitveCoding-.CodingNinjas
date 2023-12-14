/*
A number is called super-prime if it has exactly two distinct prime divisors
input:10
ouput:2
*/
 
#include<bits/stdc++.h>
using namespace std;
int solve(int n){
    bool isPrime[n+1];
    memset(isPrime,true,sizeof(isPrime));
    int primeCount[n+1];
    memset(primeCount,0,sizeof(primeCount));
    for(int i=2;i<=n;i++){
        if(isPrime[i]==true){
            for(int j=2;j*i<=n;j++){
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
