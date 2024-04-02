/*
Problem statement
You are given a string 'str' of length 'N'.



Your task is to return the longest palindromic substring. If there are multiple strings, return any.



A substring is a contiguous segment of a string.



For example :
str = "ababc"

The longest palindromic substring of "ababc" is "aba", since "aba" is a palindrome and it is the longest substring of length 3 which is a palindrome. 

There is another palindromic substring of length 3 is "bab". Since starting index of "aba" is less than "bab", so "aba" is the answer.
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
abccbc
Sample Output 1:
bccb
Explanation for input 1:
For string "abccbc",  there are several palindromic substrings such as "a", "b", "c", "cc", "bccb", and "cbc". However, the longest palindromic substring is "bccb".
Sample Input 2:
aeiou
Sample Output 2:
a
Constraints :
1 <= |str| <= 10^3

Time Limit: 1 sec
 

 


*/
 

string longestPalinSubstring(string s) {
   if (s.empty()) return "";
    
    // Preprocess the string to insert "#" between each character and at the beginning and end
    string modified = "#";
    for (char c : s) {
        modified += c;
        modified += "#";
    }
    
    int n = modified.size();
    vector<int> p(n, 0); // p[i] stores the length of palindrome centered at i
    
    int center = 0, right = 0; // center and right boundary of the current palindrome
    int maxLen = 0, maxCenter = 0; // length and center of the longest palindrome found
    
    for (int i = 0; i < n; ++i) {
        // Mirror index of i w.r.t current center
        int mirror = 2 * center - i;
        
        // Check if the current index i is within the current palindrome boundary
        if (i < right) {
            p[i] = min(right - i, p[mirror]);
        }
        
        // Attempt to expand palindrome centered at i
        int leftBound = i - (1 + p[i]);
        int rightBound = i + (1 + p[i]);
        while (leftBound >= 0 && rightBound < n && modified[leftBound] == modified[rightBound]) {
            p[i]++;
            leftBound--;
            rightBound++;
        }
        
        // If the expanded palindrome exceeds current right boundary,
        // update center and right boundary
        if (i + p[i] > right) {
            center = i;
            right = i + p[i];
        }
        
        // Update maximum palindrome length found so far
        if (p[i] > maxLen) {
            maxLen = p[i];
            maxCenter = i;
        }
    }
    
    // Extract the longest palindrome substring from the modified string
    int start = (maxCenter - maxLen) / 2;
    return s.substr(start, maxLen);
}
