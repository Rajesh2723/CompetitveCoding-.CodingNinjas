 

#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
     int firstValue=5;
     int secondValue=5;
     char thirdValue='a';
     
     int *p1,*p2;
     char*p3;
     
     p1=&firstValue;
     p2=&secondValue;
     p3=&thirdValue;
     *p1=10;
      cout<<"firstValue:"<<firstValue<<endl;
     cout<<"secondValue:"<<secondValue<<endl;
     cout<<"thirdValue:"<<thirdValue<<endl;
     *p2=*p1;
      cout<<"firstValue:"<<firstValue<<endl;
     cout<<"secondValue:"<<secondValue<<endl;
     cout<<"thirdValue:"<<thirdValue<<endl;
      cout<<"p2:"<<p2<<endl;
     cout<<"p1:"<<p1<<endl;
     p1=p2;
     cout<<"p2:"<<*p2<<endl;
     cout<<"p1:"<<*p1<<endl;
      cout<<"firstValue:"<<firstValue<<endl;
     cout<<"secondValue:"<<secondValue<<endl;
     cout<<"thirdValue:"<<thirdValue<<endl;
     *p1=20;
      cout<<"firstValue:"<<firstValue<<endl;
     cout<<"secondValue:"<<secondValue<<endl;
     cout<<"thirdValue:"<<thirdValue<<endl;
     *p3='b';
      cout<<"firstValue:"<<firstValue<<endl;
     cout<<"secondValue:"<<secondValue<<endl;
     cout<<"thirdValue:"<<thirdValue<<endl;
     
     cout<<"firstValue:"<<firstValue<<endl;
     cout<<"secondValue:"<<secondValue<<endl;
     cout<<"thirdValue:"<<thirdValue<<endl;
}
