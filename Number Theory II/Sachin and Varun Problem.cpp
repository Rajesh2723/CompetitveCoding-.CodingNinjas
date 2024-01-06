/*
Varun and you are talking about a movie that you have recently watched while Sachin is busy teaching Number Theory. Sadly, Sachin caught Varun talking to you and asked him to answer his question in order to save himself from punishment. The question says:
Given two weights of a and b units, in how many different ways you can achieve a weight of d units using only the given weights? Any of the given weights can be used any number of times (including 0 number of times).
Note: Two ways are considered different if either the number of times a is used or a number of times b is used is different in the two ways.
input 1:
4
2 3 7
4 10 6
6 14 0
2 3 6

  output:
1
0
1
2*/
#include<bits/stdc++.h>
using namespace std;

long long extendedGCD(long long a , long long b , long long& x , long long& y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    
    long long x1 , y1, g;
    
    g = extendedGCD(b , a%b , x1 , y1);
    x = y1;
    y = x1 - (a/b)*y1;
    
    return g;
}

int main(){
    
    // write your code here
    int t , a , b , d;
    
    cin>>t;
    
    while(t--){
        
        cin>>a>>b>>d;
        
        long long x , y , g;
        
        g = extendedGCD(a , b , x , y);
        
        if(d % g == 0){
            
            x = x * (d / g);//if d is divisible by g then we have to scale the ax+by for this we have to multiply d/g so will get below equations a,b are constants
            y = y * (d / g);
            
            long long L = ceil(-1.0 * x / (b/g));//3.6 to 4
            long long R = floor(1.0 * y / (a/g));//6.8 to 6
            
            if(L > R) cout<<0<<endl;
            else      cout<<R - L + 1<<endl;
        }
        else{
            cout<<0<<endl;
        }
    }
    return 0;
}
