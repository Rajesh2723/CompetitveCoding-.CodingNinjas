#include<bits/stdc++.h>
using namespace std;

int Naive(string text,string pattern){

    int n=text.size();
    int m=pattern.size();
    
        int i=0;
        int j=0;
        while(j<pattern.size() and i<(n-m)){
            if(text[i]==pattern[j]){
                i++;
                j++;
            }else{
                i++;
                j=0;
            }
        }
        if(i==m){
            return i; //check wheter i reached size of the pattern .
        }
     return -1;
}

int main(){
    string text,pattern;
    cin>>text>>pattern;
    cout<<Naive(text,pattern)<<endl;
}
