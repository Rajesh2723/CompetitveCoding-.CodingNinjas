#include <iostream>
#include <bits/stdc++.h>
using namespace std;




int StringToInt(string& s, int ind){
    // base condition
    if(ind<0) return 0;


    // recursive calls
    int num = (s[ind]-'0');    //here we taking the first index and we substracting it with the character 0 to get the int value
    int ans = num + 10*(StringToInt(s,ind-1));
    return ans;
}


int main() {
    string s;
    cin>>s;


    int n = s.size();


    // convert string into int.
    int ans = StringToInt(s,n-1);
    cout<<ans<<"\n";
}
/*
int stringTonumber(char input[],int cur) {
    if(cur<0){
        return 0;
    }
    return ((input[cur]-'0')+stringTonumber(input,cur-1)*10);
    
    
    


}
int stringToNumber(char input[]){
 int size=0;
    while(input[size])size++;                     // To get the size of the character and we are passing the size to evaluate for it
    return stringTonumber(input, size-1 );
}


*/
