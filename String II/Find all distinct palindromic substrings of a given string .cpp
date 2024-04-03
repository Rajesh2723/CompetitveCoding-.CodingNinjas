/*
Problem statement
Ninja did not do homework. As a penalty, the teacher has given a string ‘S’ to ninja and asked him to print all distinct palindromic substrings of the given string. A string is said to be palindrome if the reverse of the string is the same as the string itself. For example, the string “bccb” is a palindrome, but the string “def” is not a palindrome.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 10
1 <= |S| <= 1000

String S contains lowercase English letters only.

Where ‘T’ represents the number of test cases and ‘S’ represents the given string.

Time limit: 1 sec
Sample Input 1:
2
aba
aabb
Sample Output 1:
a aba b
a aa b bb
Explanation of sample input 1:
For the first test case, 
All the possible substrings are [ ‘a’, ‘b’, ‘ab’, ‘ba’, ‘aba’ ] out of which [ ‘a’, ‘aba', 'b’ ] are 
palindromic substrings.

For the second test case,
All the possible substrings are [ ‘a’, ‘b’, ‘aa’, ‘ab’, ‘bb’, ‘aab’, ‘abb’ , ‘aabb’ ] out of which [ 
‘a’, ‘b’, ‘aa’, ‘bb’ ] are palindromic substrings.
Sample Input 2:
2
babbb
abcdc
Sample Output 2:
a b bab bb bbb 
a b c cdc d
*/
#include<bits/stdc++.h>
bool isPalindrome(string temp){
    int start=0;
    int end=temp.size()-1;
    while(start<=end){
        if(temp[start++]!=temp[end--])return false;
    }
    return true;
}
vector<string> distinctPalindrome(string &s)
{
    set<string>ss;
    vector<string>ans;
    int n=s.size();
    for(int i=0;i<s.size();i++){
        for(int j=i;j<n;j++){
            string temp=s.substr(i,j-i+1);
            if(isPalindrome(temp)){
                ss.insert(temp);
            }
        }
    }
    for(auto x:ss){
        ans.push_back(x);
    }
    return ans;
	
}
