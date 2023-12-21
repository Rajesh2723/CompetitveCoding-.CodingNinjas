#include<bits/stdc++.h>

using namespace std;

const int mod = 1000000000+7;

//1 , 1 , 2 , 3 , 5 , 8 , 13 , 21 , 34 , 55 , 89 . . . .

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
		for(int j=0;j<n;j++) A[i][j] = temp[i][j];
	}
}

int fib(int n){

	if(n <= 2) return 1;

	long long T[2][2] = {{1 , 1} , {1 , 0}};
	long long res[2][2] = {{1 , 0} , {0 , 1}};
	int p = n-2;

	while(p > 0){

		if(p % 2 == 1){
			prod(res , T , 2);
			p--;
		}

		p = p / 2;
		prod(T , T , 2);
	}

	int answer = (res[0][0] + res[0][1]) % mod;

	return answer;

}

int main(){

	int t , n;

	cin>>t;

	while(t--){
		cin>>n;

		cout<<fib(n)<<endl;
	}

}
