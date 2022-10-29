#include<iostream>
#include<algorithm>
using namespace std;
// creating a structure Interval
// with a start time and end time
struct Interval{
int st;
int et;
};
// compare function to pass in the sort function
// to sort on the basis of start time
bool compare(Interval i1,Interval i2){
return i1.st < i2.st; // > for descending
}
int main(){
Interval arr[] = {{6, 4}, {3, 4}, {4, 6}, {8, 13}};
sort(arr, arr+4, compare);
for(int i=0; i<4; i++){
cout << arr[i].st << " : " << arr[i].et << endl;
}
return 0;
}
