/*
Problem statement
You are given a set of 3 points in a 2-D plane. You have to find out whether they are collinear or not.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 10^5
-10^6 <= x, y <= 10^6
Ouput Format:
For each test case output "YES" if they are collinear and "NO" if they are not.
Sample Input:
2
1 3
1 4
1 5
-1 0
 0 1
 1 0
Sample Output:
YES 
NO
  */
#include<bits/stdc++.h>
using namespace std;
bool f(vector<vector<int>>& v) {
    int x1 = v[0][0];
    int y1 = v[0][1];
    int x2 = v[1][0];
    int y2 = v[1][1];
    int x3 = v[2][0];
    int y3 = v[2][1];
    if ((x3 - x2) * (y2 - y1) - (y3 - y2) * (x2 - x1) == 0) {
        return true;
    }
    return false;
}
int main(){
    
    int t;
    cin>>t;
    while(t--){
        vector<vector<int>>v(3);//rows 3 size(3 points)
        for(int i=0;i<3;i++){
            int x,y;
            cin>>x>>y;
          v[i].push_back(x);
           v[i].push_back(y);
        }    
        if(f(v)){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
