/*
 F(0) = 0
 F(1) = 1
 F(N) = F(N - 1) + F(N - 2), N >= 2

Your task is very simple. Given two non-negative integers N and M (N <= M), you have to calculate and return the sum (F(N) + F(N + 1) + ... + F(M)) mod 1000000007.
First line of input will contain T(number of test cases), each test case follows as.
Two non-negative space-separated integers N and M. (N <= M)
1 <= T <= 10^3
1 <= N <= M <= 10^18
input:1 
10 19 
output:
10857
  */
// #include<bits/stdc++.h>
// #define ll long long
// using namespace std;



// ll FibSum(ll n,ll m){
//     ll T[2][2]={{1,1},{1,0}};
//     ll res[2][2]={{1,0},{0,1}};
//     int p=n-2;
//     ll sum=0;
//     while(p>0){
//         if(p%2==1){
//            sum+= prod(res,T,2);
//             n--;
//         }
//         p/=2;
//         ll+=prod(T,T,2);
//     }
//     return sum;
// }

// int main(){
    
//      int t;
//      cin>>t;
//      while(t--){
//          ll n,m;
//         cin>>n>>m;
//          cout<<FibSum(n,m);
//      }
//     return 0;
// }
#include<bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

// sum(R) - sum(L-1);

void prod(long long A[2][2] , long long B[2][2] , int n){
    
    long long temp[2][2] = {{0 , 0} , {0 , 0}};
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                temp[i][j] = (temp[i][j] + A[i][k] * B[k][j]) % mod;
            }
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
        A[i][j] = temp[i][j];
    }
}

long long fibSum(long long n){
    
    if(n == 0) return 0;
    
    long long T[2][2] = {{1 , 1} , {1 , 0}};
    long long res[2][2] = {{1 , 0} , {0 , 1}};
    
    while(n > 0){
        
        if(n % 2 == 1){
            prod(res , T , 2);
            n--;
        }
        
        n = n / 2;
        prod(T , T , 2);
        
    }
    
    long long sum = (res[0][0] + res[0][1] - 1) % mod;
    
    if(sum < 0) sum = sum + mod;
    
    return sum;
}

int main(){
    int t;
    
    long long   n , m;
    
    cin>>t;
    
    while(t--){
        cin>>n>>m;
        
        long long res = (fibSum(m) - fibSum(n-1)) % mod;
        if(res < 0) res = res + mod;
        
        cout<<res<<endl;
    }
    return 0;
}
