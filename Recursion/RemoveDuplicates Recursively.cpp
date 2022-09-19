Given a string S, remove consecutive duplicates from it recursively.
Input Format :
String S
Output Format :
Output string
Constraints :
1 <= |S| <= 10^3
where |S| represents the length of string
Sample Input 1 :
aabccba
Sample Output 1 :
abcba
//
#include<bits/stdc++.h>
void removeConsecutiveDuplicates(char *input) {
	/* Don't write main().
	* Don't read input, it is passed as function argument.    
	* Change in the given string itself.
	* No need to return or print anything
	* Taking input and printing output is handled automatically.
	*/
	
	int n=strlen(input);
   if(input[0]=='\0')
       return;
    
    removeConsecutiveDuplicates(input+1);
    //int i;
   // for(int i=1;i<n;i++){
    if(input[0]==input[1]){
       // int len=strlen(input);
         int i;
       for( i=0;input[i]!='\0';i++){
	   input[i]=input[i+1];                //here we cant start the input[i-1]=input[i] that makes the rumtime error
       }
       input[i]='\0';
    }
     //input[i]='\0';
    
}


//main function
#include <iostream>
using namespace std;
#include "solution.h"

int main() {
    char s[100000];
    cin >> s;
    removeConsecutiveDuplicates(s);
    cout << s << endl;
}
