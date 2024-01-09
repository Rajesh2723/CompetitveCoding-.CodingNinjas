/*
Problem statement
Given an integer matrix of size m*n, you need to find out the value of minimum cost to reach from the cell (0, 0) to (m-1, n-1).

From a cell (i, j), you can move in three directions : (i+1, j), (i, j+1) and (i+1, j+1).

Cost of a path is defined as the sum of values of each cell through which path passes.

Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= m, n <= 100

Sample Input 1 :
3 4
3 4 1 2
2 1 8 9
4 7 8 1
Sample Output 1 :
13
  */
#include<bits/stdc++.h>
// n - number of rows
/// m - number of columns
int f(int i,int j,int **input,int **temp){
    if(i<0||j<0){
        return INT_MAX;
    }
    if(i==0 && j==0){
        return input[i][j];
    }
    if(temp[i][j]!=-1){
        return temp[i][j];
    }
    int x=f(i-1,j,input,temp);
    int y=f(i,j-1,input,temp);
    int z=f(i-1,j-1,input,temp);
    int ans=0;
    if(x<y and x<z){
            ans=x+input[i][j];
    }  else if(y<x and y<z){
        ans=y+input[i][j];
    } else{
        ans=z+input[i][j];
    }
    return temp[i][j]=ans;
}
int minCostPath(int **input, int n, int m) {
     int **temp=new int*[n+1];
     for(int i=0;i<=n;i++){
         temp[i]=new int[m];
         for(int j=0;j<=m;j++){
             temp[i][j]=-1;
         }
     }
     return f(n-1,m-1,input,temp);

}
