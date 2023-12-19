#include<iostream>

using namespace std;

long long power(int a , int n , int p){

	long long res = 1;

	while(n > 0){

		if(n % 2 == 1){
			res = ((res % p) * (a % p)) % p;
			n--;
		}

		n = n / 2;
		a = ((a % p) * (a % p)) % p;

	}

	return res;
}

int main(){
	
	int t , a , n , p;

	cin>>t;

	while(t--){
		cin>>a>>n>>p;

		cout<<power(a , n , p)<<endl;
	}
}
