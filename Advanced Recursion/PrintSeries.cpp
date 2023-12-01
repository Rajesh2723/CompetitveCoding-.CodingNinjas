/*
You have given two positive integers N and K. Your task is to print a series of numbers i.e   subtract K from N until it becomes 0 or negative then add K until it becomes N. You need to do this task without using any loop.
 For  N = 5 , K = 2 
Series = [ 5, 3, 1, -1, 1, 3, 5]
2 
3 2
5 4
output
3 1 -1 1 3
5 1 -3 1 5
  */
void f(vector<int>&ans,int n,int k,int middle){
    
   if (middle <= 0) {
        return;
}

 middle=middle-k;
 ans.push_back(middle);
 f(ans,n,k,middle);
 middle=middle+k;
      
     
       ans.push_back(middle);

        
        


}
vector<int> printSeries(int n, int k)
{
    vector<int>ans;
    int middle=n;
    ans.push_back(middle);
    f(ans,n,k,middle);
    return ans;
}
