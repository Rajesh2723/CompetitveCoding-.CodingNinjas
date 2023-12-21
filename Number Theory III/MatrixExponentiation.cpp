#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int mod = 1000000000+7;

void product(vector<vector<ll> >& A , vector<vector<ll> >& B , int n){
	
	ll temp[n][n];
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			temp[i][j] = 0;
			
			for(int k=0;k<n;k++)
			{
				temp[i][j] = (temp[i][j] + ( (A[i][k] * B[k][j]) % mod)) % mod;
			}
		}
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++) A[i][j] = temp[i][j];
	}
	
}

void power(vector<vector<ll> >& A , int m , int n){
	
	vector<vector<ll> > res(m , vector<ll> (m));
	
	//initialization
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<m;j++)
		if(i == j) res[i][j] = 1;
	}
	
	while(n > 0){
		if(n % 2 == 1){
			product(res , A , m);
			n--;
		}
		
		n = n / 2;
		product(A , A , m);
	}
	
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++) cout<<res[i][j]<<" ";
		cout<<"\n";
	}
	
}

int main() {
	int t , m , n;
	
	cin>>t;
	
	while(t--){
		cin>>m>>n;
		
		vector<vector<ll> > A(m , vector<ll> (m));
		
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<m;j++) cin>>A[i][j];
		}
		
		power(A , m , n);
		
	}
	return 0;
}
