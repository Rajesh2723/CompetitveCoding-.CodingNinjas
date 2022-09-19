/*
All Indices of Number
Send Feedback
Problem Statement:
Given an array of length N and an integer x, you need to find all the indexes where x is present in the input array. Save all the indexes in an array (in increasing order).
Do this recursively. Indexing in the array starts from 0.
Input Format :
Line 1 : An Integer N i.e. size of array
Line 2 : N integers which are elements of the array, separated by spaces
Line 3 : Integer x
Output Format :
indexes where x is present in the array (separated by space)
Constraints :
1 <= N <= 10^3
C++ Code with Logical Errors:
#include<bits/stdc++.h>
using namespace std;
void findIndexes(int input[],int currIndex, int size, int x, int output[],int &k) {
    if(currIndex==size+1)
        return;
    if(input[currIndex]==x){
        output[k]=currIndex;
        k--;
    }
    findIndexes(input,currIndex+1,size,x,output,k);
}

int allIndexes(int input[], int size, int x, int output[]) {
    int k=0;
    findIndexes(input,0,size,x,output,k);
    return k;
}
Please improve upon this code and submit the problem.

Sample Input :
5
9 8 10 8 8
8
Sample Output :
1 3 4
*/

void allIndexes(int input[], int size, int x, int output[],int cur,int &k) {         //Here we are passing the reference and 
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Save all the indexes in the output array passed and return the size of output array.
     Taking input and printing output is handled automatically.
  */
    if(cur==size)
        return ;
    //int k=0;
    if(input[cur]==x){
        output[k]=cur;
        k++;
    }
 	 allIndexes(input,size,x,output,cur+1,k);

}
int allIndexes(int input[],int size,int x,int output[]){
    int k=0;
  allIndexes(input,size,x,output,0, k);
    return k;
}
###########
int allIndexes(int input[], int size, int x, int output[]) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Save all the indexes in the output array passed and return the size of output array.
     Taking input and printing output is handled automatically.
  */

     if(size==0)
    {
        return 0;
    }

    int ans=allIndexes(input,size-1,x,output);
    if(input[size-1]==x){
        output[ans]=size-1;
        ans = ans + 1;
    }
    return ans;
}

