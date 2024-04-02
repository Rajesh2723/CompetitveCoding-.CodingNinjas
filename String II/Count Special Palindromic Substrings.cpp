/*
Problem statement
You are given a string 'STR'. Your task is to count the number of special palindromic substrings of size greater than 1 that the given string contains. A substring is said to be a special palindrome in the following two cases:

If all the characters in the substring are the same.

If the length of the substring is odd and only the middle element is different, while all the other characters are the same. 
Example:
“aba” is a special palindrome, while “abaa” is not
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 100
1 <= |STR| <= 10000

Time limit: 1 sec
Sample Input 1:
2
bcbc
ccddd
Sample Output 1:
2
4
Explanation For Sample Input 1:
In the first test case, 
The special palindromic substrings in the given string are: bcb and cbc. Hence, the answer is 2 in this case.

In the second test case, 
The special palindromic substrings in the string are: cc, dd, ddd and dd. Hence, the answer is 4 in this case. 
Sample Input 2:
2
abccdcdf
baabaab
Sample Output 2:
3
4
  */
int specialPalindromes(string &s)
{
    int n = s.size();
    int ans = 0;
    int sameChar[n] = { 0 };

    int i=0;
    while(i<n){
        int cnt = 1;
        int j = i+1;
        while(s[i]==s[j] && j<n)
            cnt++, j++;
        
        ans += (cnt * (cnt+1)/2);
        sameChar[i] = cnt;
        i=j;
    }

    for(int j=1; j<n; ++j){
        if(s[j] == s[j-1])
            sameChar[j] = sameChar[j-1];
        if(j>0 && j<(n-1) && (s[j-1]==s[j+1] && s[j]!=s[j-1]))
            ans += min(sameChar[j-1], sameChar[j+1]);
    }
    ans -= n;
    return ans;
}
