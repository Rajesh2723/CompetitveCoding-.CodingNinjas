/*
Let the array 'ARR' be [1, 2, 3] and 'B' = 5. Then all possible valid combinations are-

(1, 1, 1, 1, 1)
(1, 1, 1, 2)
(1, 1, 3)
(1, 2, 2)
(2, 3)
  */
void solve(int ind,int target,vector<int>&arr,vector<vector<int>>&ans,vector<int>ds){

 

if(ind==arr.size()){

 

    if(target==0){

 

        ans.push_back(ds);

 

    }

 

    return;

 

}

 

 //picking the element

 

if(arr[ind]<=target){

 

    ds.push_back(arr[ind]);

 

    solve( ind, target-arr[ind],  arr,  ans,  ds);

 

    ds.pop_back();

 

}

 

//not pick

 

solve( ind+1,target,arr,ans,ds);

 

 

 

}

 

 

 

vector<vector<int>> combSum(vector<int> &arr, int B)

 

{

 

    // Write your code here.

 

    sort(arr.begin(),arr.end());

 

    vector<vector<int>>ans;

 

    vector<int>ds;

 

    solve(0,B,arr,ans,ds);

 

    return ans;

 

}
/*
void f(int index,vector<int>&arr,int target,vector<vector<int>>&ans,vector<int>&result){
    if(target==0){
        ans.push_back(arr);
        return;
    }
    if(index==arr.size() || target-arr[index]<0)return ;
    result.push_back(arr[index]);
    f(index+1,arr,target-arr[index],ans,result);
    result.pop_back();

    f(index+1,arr,target,ans,result);
}
vector<vector<int>> combSum(vector<int> &arr, int target)
{
    vector<vector<int>>ans;
    vector<int>result;
    f(0,arr,target,ans,result);
    // sort(ans.begin(),ans.end());
    return ans;
}
*/
why this code is error have to check 
