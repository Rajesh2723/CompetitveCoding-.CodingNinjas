/*
Given an array of length N, you need to find and return the sum of all elements of the array.
Do this recursively.
Input Format :
Line 1 : An Integer N i.e. size of array
Line 2 : N integers which are elements of the array, separated by spaces
Output Format :
Sum
Constraints :
1 <= N <= 10^3
Sample Input 1 :
3
9 8 9
Sample Output 1 :
26
*/

int sum(int input[], int n) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
  */
	
    if(n==0){
        return 0;
    }
    int result=input[0]+sum(input+1,n-1);
    return result;
}
///
sumOfDigits using vectors 
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int sumOfDigits(int cur,vector<int>&a){
    int size=a.size();
    if(size==cur){           //if the cur is came to size then return 0
        return 0;
    }
    return(a[cur]+sumOfDigits(cur+1,a));
}
int main()
{
    int n;
    cin>>n;
    vector<int>a(n);      //here we are initialising the vector a initialized to n elements
    for(int i=0;i<n;i++)cin>>a[i];
    int sum=sumOfDigits(0,a); here we are passing the cur to zero 
    cout<<sum<<endl;

    return 0;
}
