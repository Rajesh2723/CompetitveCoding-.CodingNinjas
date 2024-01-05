#include<bits/stdc++.h>

using namespace std;

long long power(long long a , int d , int n){

	long long res = 1;

	while(d > 0){
		if(d % 2 == 1){
			res = ((res % n) * (a % n)) % n;
			d--;
		}

		d /= 2;
		a = (a * a) % n;
	}

	return res;
}

bool check_composite(long long a , int s , long long d , long long n){

	long long x = power(a , d , n);

	if(x == 1 || x == n - 1) return false;//after dividing factors if we get any of these its false

	for(int i=1;i<s;i++){
		x = (x * x) % n;

		if(x == n-1) return false;
	}

	return true;
}

bool millerRabin(long long n ){

	if(n < 4) return n == 2 || n == 3;

	int primes[] = {2 , 3 , 5 , 7};//for 32 bit integer we are taking these number to get more accuracy
  //we are taking this line instead of generating random number ,for 64 bits we need to take upto 12 numbers

	long long d = n-1;
	int s = 0;

	while(d % 2 == 0){
		s++;
		d /= 2;
	} //a power s *d 

	for(int a : primes){

		if(check_composite(a , s , d , n) == true)
			return false;
	}

	return true;
}

int main(){

	int t;
	long long n;

	cin>>t;
	while(t--){
		cin>>n;

		if(millerRabin(n) == true) cout<<n<<" is a prime"<<endl;
		else					   cout<<n<<" is not a prime"<<endl;
	}

}
