/*
GCD
Send Feedback
Calculate and return GCD of two given numbers x and y. Numbers are within range of Integer.
Input format :
First line of Input will contain T(number of test cases), each test case follows as.
x and y (separated by space)
Output format :
Print GCD of x and y for each test case in newline
Constraints:
1 <= T <= 10^5
1 <= x, y <= 10^9
Sample Input 1:
1
20 5
Sample Output 1:
5
Sample Input 2:
1
96 14
Sample Output 2:
2
  */
#include <bits/stdc++.h>
using namespace std;

int findGcd(int x, int y) {  return __gcd(x,y); }  

int main(){
    int a,b,q;
    cin>>q;
    while(q--){
       cin>>a>>b;
  
    
    cout<<findGcd(a,b)<<endl;
    }
   
}
/*
#include <bits/stdc++.h>
using namespace std;

// int findGcd(int x, int y) {  return __gcd(x,y); }  
// int findGcd(int a,int b){
//     int result=min(a,b);
//     while(result>0){
//         if(a%result==0 and b%result==0){
//             break;
//         }
//         result--;
//     }
//     return result;
// }
int findGcd(int a,int b){
    if(b==0){
        return a;
    }
    return findGcd(b, a%b);
}
int main(){
    int a,b,q;
    cin>>q;
    while(q--){
       cin>>a>>b;
    
    cout<<findGcd(a,b)<<endl;
    
    // cout<<findGcd(a,b)<<endl;
    }
   
}
*/

