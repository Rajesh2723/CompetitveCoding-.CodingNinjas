/*
Print Keypad - String
Send Feedback
Given an integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n.
Note : The order of strings are not important. Just print different strings in new lines.
Input Format :
Integer n
Output Format :
All possible strings in different lines
Constraints :
1 <= n <= 10^6
Sample Input:
23
Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf
*/
#include <iostream>
#include <string>
using namespace std;
void printKeypadHelper(int num,string output,string phone[10]){
     if(num==0){
          cout<<output<<endl;
          return;
     }
     int digit=num%10;
     int i=0;
     while(i<phone[digit].length()){
          printKeypadHelper(num/10,phone[digit][i]+output,phone);
          i++;
     }
     return;
}
void printKeypad(int num){
       string phone[10]={" "," ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
       printKeypadHelper(num,"",phone);
       return;
}

#include <iostream>
#include <string>
#include "solution.h"
using namespace std;

int main(){
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}
