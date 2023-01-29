/*
Sorting the Skills
Send Feedback
There is a company named James Peterson & Co. The company has ‘n’ employees. The employees have skills, which is denoted with help of an integer. The manager of James Peterson & Co. wants to sort the employees on the basis of their skills in ascending order. He is only allowed to swap two employees which are adjacent to each other. He is given the skills of employees in an array of size ‘n’. He can swap the skills as long as the absolute difference between their skills is 1. You need to help the manager out and tell whether it is possible to sort the skills of employees or not.
Input Format:
First Line will have an integer ‘t’ denoting the no. of test cases.
First line of each test case contains an integer ‘n’ denoting the no. of employees in the company.
Second line of each test case contains ‘n’ integers.
Output Format:
For each test case, print “Yes” if it is possible to sort the skills otherwise “No”.
Constraints:
1 <= t <= 10^4
1 <= n <= 10^5
Sum of n over all test cases doesn't exceed 10^6
Sample Input:
2
4
1 0 3 2
3
2 1 0
Sample Output:
Yes
No
Explanation:
In first T.C., [1, 0, 3, 2] -> [0, 1, 3, 2] -> [0, 1, 2, 3]
In second T.C., [2, 1, 0] -> [1, 2, 0]  OR  [2, 1, 0] -> [2, 0, 1] So, it is impossible to sort.
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
  
    int t;
    cin>>t;
    while(t--){
      cin >> n;
      vector<int> arr(n), temp(n);
      for (int i = 0; i < n; i++) {
        cin>>arr[i];
    }
    for (int i = 0; i < arr.size(); i++){
        temp.push_back(arr[i]);
    }
  bool flag=false;
      for (int i = 0; i < n - 1; i++) {
        int k=abs(arr[i]-arr[i+1]);
        if(arr[i]<=arr[i+1]){
          continue;
        }
        if(k==1){
            int temp=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=temp;
        }else{
          flag=true;
          break;
        }
    }
   if(flag){
     cout<<"No"<<endl;
   } else {
     cout << "Yes" << endl;
   }
    }
}
