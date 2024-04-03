/*
Problem statement
You are given a string ‘Str’ of length ‘N’. Find the last substring of ‘Str’ in lexicographical order.

In Lexicographical order string ‘S1’ comes before string ‘S2’ if S1 is the prefix of S2 and (|S1| < |S2|), or if none of them is a prefix of the other and at the first position where they differ, the character in ‘S1’ is smaller than the character in ‘S2’.

Example :
Consider string ‘Str’ = “abba”, then its substring in lexicographical order is [“a”, “ab”, “abb”, “abba”, “b”, “bb”, “bba”].  Clearly, the last substring in lexicographical order is  “bba”. 
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= T <= 50
1 <= N <= 10^4
‘Str’ contains only lowercase English letters.

Time limit: 1 sec
  */
/*
  
Greedy
We can prove that the lexicographically largest substring or last substring in lexicographical order will be one of the suffixes of the given string.   

 

We can prove it by contradiction, let assume that a substring Str[i...j]  is the last substring of string ‘Str’ of length ‘N’ in ’ lexicographical order. Here j < N-1, i.e Str[i..j] is not a suffix.   Then Str[i..j+1] > Str[i..j] because Str[i...j] is the prefix of Str[i...j+1],  That proves our assumption is wrong.

 

Algorithm

 

Create two empty strings ‘lastSubstr’ and ‘curSuffix’.
Run a loop where ‘i’ ranges from N - 1 to 0 (i.e in reverse order) and for each ‘i’ do the following
Add the ith character of Str at the start of the string ‘curSuffix’.
If  curSuffix’  > ‘lastSubstr’, then do lastSubstr := curSuffix. 
Return lastSubstr’.
*/
#include<bits/stdc++.h>
string findLastSubstring(string &str) {
   int n = str.length();
   string lastSubstr, curSuffix;
   for (int i = n - 1; i >= 0; i--) {
       curSuffix = str[i] + curSuffix;
       if (curSuffix > lastSubstr) {
           lastSubstr = curSuffix;
       }
   }
   return lastSubstr;  
}
/*TLE..
#include<bits/stdc++.h>
string findLastSubstring(string &str) {
    cin.tie(NULL);
    cout.tie(NULL);
     vector<string>mid;
   for(int i=0;i<str.size();i++){
       for(int j=i;j<str.size();j++){
           string temp=str.substr(i,j-i+1);
          mid.push_back(temp);
       }
   }
   sort(mid.begin(),mid.end());
   string ans=mid[mid.size()-1];
   return ans;
}
*/

