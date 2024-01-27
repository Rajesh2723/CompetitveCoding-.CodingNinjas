/*
Problem statement
You have been given an array 'ARR' of 'N' distinct elements.

Your task is to find the minimum no. of swaps required to sort the array.

For example:
For the given input array [4, 3, 2, 1], the minimum no. of swaps required to sort the array is 2, i.e. swap index 0 with 3 and 1 with 2 to form the sorted array [1, 2, 3, 4].
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 100
1 <= N <= 1000
0 <= ARR[i] <= 10 ^ 9

Where 'ARR[i]' is the value of the input array elements.

Time Limit: 1 sec
Sample Input 1:
2
4
4 3 2 1
5
1 5 4 3 2
Sample Output 1:
2
2
Explanation of Sample Input 1:
For the first test case, swap index 0 with 3 i.e. 4 -> 1 and 1 with 2 i.e. 3 -> 2 to form the sorted array {1, 2, 3, 4}.

For the second test case, swap index 1 with 4 i.e. 5 -> 2 and 2 with 3 i.e. 4 -> 3 to form the sorted array {1, 2, 3, 4, 5}.
Sample Input 2:
2
4
1 2 3 4
6
3 5 2 4 6 8
Sample Output 2:
0
3
  */
int minSwaps(vector<int> &arr)
{
	 int n=arr.size();
	 vector<bool>visited(n,false);
	 vector<pair<int,int>>p(n);//size need to declare else runtime error will come.
	 for(int i=0;i<n;i++){
		p[i].first=arr[i];
		p[i].second=i;
	 }
	 int swaps=0;
	 sort(p.begin(),p.end());
	 for(int i=0;i<n;i++){
		 if(visited[i]||p[i].second==i){
			 continue;
		 }

		 int cycleCount=0;
		 int j=i;
		 while(!visited[j]){
			 visited[j]=true;
			 j=p[j].second;
			 cycleCount++;
		 }
		swaps+=(cycleCount-1);
	 }
	 return swaps;
}
