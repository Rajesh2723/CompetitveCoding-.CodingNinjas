 /*
     Check whether a given String S is a palindrome using recursion. Return true or false.
Input Format :
String S
Output Format :
'true' or 'false'
Constraints :
0 <= |S| <= 1000
where |S| represents length of string S.
Sample Input 1 :
racecar
Sample Output 1:
true
*/
//
#include<bits/stdc++.h>
bool checkPalindrome(char input[],int start,int end){
    if(start>=end){
        return true;
    }
    if(input[start]!=input[end]){
        return false;
    }else{
        checkPalindrome(input,start+1,end-1);
    }
   
}



bool checkPalindrome(char input[]) {
    int size;
    while(input[size])size++;
    return checkPalindrome(input,0,size-1);

}
#include <iostream>
#include "solution.h"
using namespace std;

int main() {
    char input[50];
    cin >> input;
    
    if(checkPalindrome(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}
