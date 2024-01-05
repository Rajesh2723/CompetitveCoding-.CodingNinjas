/*
First line of input will contain T(number of test cases), each test case follows as.

On each line are written two integers L and U separated by a blank. L - lower bound of 
interval, U - upper bound of interval.
  1  <= T <= 100
1 <= L <= U <= 10^9
0 <= U - L <= 10^5

  2
2 10
3 7

ouput:
2 3 5 7
3 5 7 
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n=1000000000;
    long long size=sqrt(n);
    bool arr[size];
    //cout<<size<<endl;
    arr[0]=false;
    arr[1]=false;
    for(long long i=2;i<=size;i++)
    {
        arr[i]=true;
    }
    for(long long i=2;i<=size;i++)
    {
        for(long long j=i*i;j<=size;j+=i)
        {
            arr[j]=false;
        }
    }
    int t;
    cin>>t;
    while(t--)
    {
        long long l,u;
        cin>>l>>u;
        bool isPrime[u-l+1];
        for(int i=0;i<=u-l;i++)
        {
            isPrime[i]=true;
        }
        if(u>size)
        {
            for(long long i=2;i<=size;i++)
            {
                if(i*i>u)
                {
                    break;
                }
                if(arr[i]==true)
                {
                    long long base=(l/i)*i;
                    if(base<l)
                    {
                        base=base+i;
                    }
                     for(long long j=base;j<=u;j+=i)
                	{
                    isPrime[j-l]=false;
                	}
                    if(base==i)
                    {
                        isPrime[base-l]=true;
                    }
                }
            }
            for(long long i=0;i<=(u-l);i++)
            {
                if(isPrime[i]==true)
                {
                    cout<<i+l<<" ";
                }
            }
        }
        else
        {
            for(long long i=l;i<=u;i++)
            {
                if(arr[i]==true)
                {
                    cout<<i<<" ";
                }
            }
        }
        cout<<endl;
    }
    return 0;
}
/* this code works good(refer)
#include<bits/stdc++.h>
using namespace std;
long long n=100001;
bool sieve[100001];//because array initialisation cannot be done with a variable
if you want to use n+1 then declare n as const int n
void createSieve(){
        for(int i=2;i<=n;i++){
            sieve[i]=true;
        }
        for(int i=2;i*i<=n;i++){
                if(sieve[i]){
                    for(int j=i*i;j<=n;j+=i){
                        sieve[j]=false;
                    }
                }
        }
}
vector<int>generatePrime(long long n){//function to print all prime numbers
    vector<int>ds;
    for(int i=2;i<=n;i++){
        if(sieve[i]==true){
            ds.push_back(i);
        }
    }
    return ds;
}
int main(){
    createSieve();
    long long  t;
    cin>>t;
    while(t--){
        long long l,r;
        cin>>l>>r;
        if(l<2){
            l=2;
        }
        vector<int>primes=generatePrime(sqrt(r));
       vector<int>dummy(r-l+1);//create size of r-l+1 with 10 power 5
        for(int i=0;i<r-l+1;i++){
            dummy[i]=1;
        }
        for(auto pr:primes){//main function for this problem
            int firstMultiple=(l/pr)*pr;
            if(firstMultiple<l)firstMultiple+=pr;
            for(int j=max(firstMultiple,pr*pr);j<=r;j+=pr){//for all multiples of primes we are marking false 
                dummy[j-l]=0;
            }
            // if (firstMultiple == pr) {
            //     dummy[firstMultiple - l] = 0;
            // }
        }
        for(int i=l;i<=r;i++){
            if(dummy[i-l]==1){
                cout<<i<<" ";
            }
        }
        cout<<endl;
    }
   
    return 0;
}
*/
