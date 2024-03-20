/*
You are given two strings 'A' and 'B' where string 'A' is fixed. But you can perform left shift operations on string B any number of times.

Your task is to find out the minimum number of left-shift operations required in order to obtain the longest common prefix of string 'A' and 'B'.

Note:

Left shift is defined as a single circular rotation on the string after which the first character becomes the last character and all other characters are shifted one index to the left.
For Example:
If A = “an”, B = “can”.
After performing one left shift operation, string B becomes “anc”.
After performing two left shift operations, string B becomes “nca”.
Follow Up:
Can you solve this in linear time and space complexity?
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 100
1 <= |A|, |B| <= 5 * 10^4
Where |A| and |B| denote the length of string, A and B respectively.   

All the characters of the string A and B contain lowercase English letters only.

Time limit: 1 second
Sample Input 1:
2
on
soon
an
an
Sample Output 1:
2
0
Explanation for sample 1:
For the first test case, the common prefix of A and B is .””
After one left shift, the string B becomes “oons”, now the common prefix is “o”.
After two left shifts, the string B becomes “onso”, now the common prefix is “on”.
After three left shifts, the string B becomes “nsoo”, now the common prefix is “”.
(We do not need to perform one more left shift, because if the number of left-shift operations is equal to the length of the string, then we get the original string. For example, here if we perform one more shift, then we get the string “soon” which was the original string.)
So after two left shifts, we get the longest common prefix i.e. “on”. Hence, the answer is 2.

For the second test case, the common prefix of A and B is “an”.
After one left shift, the string B becomes “na”, now the common prefix is “”.
So we get the longest common prefix without performing any shifts. Hence, the answer is 0. 
Sample Input 2:
2
abc 
def
sorry
personal
Sample output 2:
0
3
Explanation for sample 2:
For the first test case, the common prefix of A and B is “”.
After one left shift, the string B becomes “efd”, now the common prefix is again “”.
After two left shifts, the string B becomes “fde”, now the common prefix is again “”.
Here the length of the longest common prefix is 0, as there is no common prefix in all the cases. So we get the longest common prefix without performing any shifts. Hence, the answer is 0.
For the second test case, the common prefix of A and B is “”.
After one left shift, the string B becomes “ersonalp”, now the common prefix is “”.
After two left shifts, the string B becomes “rsonalpe”, now the common prefix is “”.
After three left shifts, the string B becomes “sonalper”, now the common prefix is “so”.
After four left shifts, the string B becomes “onalpers”, now the common prefix is “”.
After five left shifts, the string B becomes “nalperso”, now the common prefix is “”.
After six left shifts, the string B becomes “alperson”, now the common prefix is “”.
After seven left shifts, the string B becomes “lpersona”, now the common prefix is “”.

So after three left shifts, we get the longest common prefix i.e. “so”. Hence, the answer is 3.
  */
int minimumRequiredShifts(string a, string b){
	int ret=0, maxsame=0;
	for(int shift=0; shift<b.length(); shift++){
		for(int i=0, j=shift; i<a.length(); i++, j++){
			int k=j%b.size();
			if(a[i]!=b[k]) break;
			if(i+1>maxsame){
				maxsame=i+1;
				ret=shift;
			}
		}
	}
	return ret;

}
/*
    Time Complexity: O(N+M)
    Space Complexity: O(M)

    Where M and N are the lengths of string a and b respectively.
*/
/*


#include <vector>

vector<int> kmpPreProcess(string a, int m){

    int i = 1, j = 0;

    /* 
    	Create lps array of size m, which stores the 
        longest prefix suffix for each index.
    */
    vector<int> lps(m,0);

    while(i < m) {

        /* 
            If the ith index of "a" matches with the jth index of "a", 
            then store the value j+1 at lps[i] and 
        	increment both i and j.
        */
        if(a[i] == a[j]) {
            lps[i] = j + 1;
            i++; 
            j++;
        } 

        /* 
            If the ith index of "a" doesn't match with the 
            jth index of "a" and j > 0, then j redirects to lps[j-1].
        */
        else if (j > 0) {
            j = lps[j - 1];
        }

        /* 
        	If none of the above condition matches 
            then make lps[i] as 0 and increment i.
        */
        else {
            lps[i] = 0;
            i++;
        }
    }

    return lps;
}

int minimumRequiredShifts(string a, string b){

	// Concatenate string b with itself.
	b = b + b;

	int n = b.length();
    int m = a.length();

    // The ans variable stores the minimum required shifts. 
    int ans = 0;

    /* 
    	The max variable stores the length of the 
        longest common prefix encountered so far.
    */
    int max = 0;

    // Calculate the lps array.
    vector<int> lps = kmpPreProcess(a, m);
    int i = 0, j = 0;

    while(i < n && j < m) {

        /* 
        	If the ith character of "b" matches with 
            the jth character of "a", then increment 
            both i and j.
        */
        if(b[i] == a[j]) {
            i++;
            j++;
        } 

        /* 
        	If the above characters do not match and j > 0, 
            then j redirects to lps[j-1] and continue in the loop.
        */
        else if(j > 0) {
            j = lps[j - 1];
            continue;
        } 

        /* 
        	If none of the above mentioned condition matches, 
            then increment i.
        */
        else {
            i++;
        }

        /* 
        	If the value of j exceeds the max variable, 
            then update the max to j and ans to i-j. 
        */
        if(j > max){
        	max = j;
          	ans = i - j;
        }
    }

    return ans; 
}

*/
