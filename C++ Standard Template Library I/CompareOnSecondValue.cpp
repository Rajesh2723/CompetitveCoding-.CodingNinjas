#include <iostream>
#include<bits/stdc++.h>
using namespace std;

struct interval{
    int st;
    int end;
};
bool compare(interval l1,interval l2){
    return l1.end<l2.end;
}
int main(){
    interval arr[]={{1,3},{2,3},{3,4},{4,5}};
    sort(arr,arr+4,compare);
    for(int i=0;i<4;i++){
        cout<<arr[i].st<<" "<<arr[i].end<<endl;
    }
    return 0;
}
