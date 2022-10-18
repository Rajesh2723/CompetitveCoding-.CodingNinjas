/* Given a string, compute recursively a new string where all appearances of "pi" have been replaced by "3.14".
Constraints :
1 <= |S| <= 50
where |S| represents the length of string S. 
Sample Input 1 :
xpix
Sample Output :
x3.14x
*/


#include<cstring>
void replacePi(char input[]) {
	int n=strlen(input);
    if(n==0||n==1){
        return;
    }
    replacePi(input+1);
    if((input[0]=='p')&&(input[1]=='i')){
        int len=strlen(input);
        for(int i=len;i>=2;i--){
            input[i+2]=input[i];
        }
        input[0]='3';
        input[1]='.';
        input[2]='1';
        input[3]='4';
    }

}

