a=[2,4,6,8]
b=[3,6,9]
c=[5,10]
//union total numbers will be ->2,3,4,5,6,8,9,10-?so total 8 values.
#include<bits/stdc++.h>
using namespace std;

int lcm(int cur,int mid){
    int final=cur*mid/__gcd(cur,mid);
    return final;
}

int f(vector<int>&v,int n){
    int res=0;
    int subset_size=(1<<n);
    for(int mask=1;mask<subset_size;mask++){
        int Lcm=1,count=0;
        for(int i=0;i<n;i++){
            if((mask&(1<<i))!=0){
                Lcm=lcm(Lcm,v[i]);
                count++;
            }
        }
        if(count%2!=0){
            res+=n/Lcm;//assume range is (1,10) then 10/2->5 total 5 values which are divisible or multiples of 2 is there.
        }else{
            res-=n/Lcm;
        }
    }
    return res;
}

int main() {
    int n, m, p;
    cout << "Enter the size of set A: ";
    cin >> n;
    vector<int> A(n);
    cout << "Enter the elements of set A: ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    cout << "Enter the size of set B: ";
    cin >> m;
    vector<int> B(m);
    cout << "Enter the elements of set B: ";
    for (int i = 0; i < m; i++) {
        cin >> B[i];
    }

    cout << "Enter the size of set C: ";
    cin >> p;
    vector<int> C(p);
    cout << "Enter the elements of set C: ";
    for (int i = 0; i < p; i++) {
        cin >> C[i];
    }

    int unionSize = f(A, n) + f(B, m) + f(C, p);
    cout << "Size of A union B union C: " << unionSize << endl;

    return 0;
}
