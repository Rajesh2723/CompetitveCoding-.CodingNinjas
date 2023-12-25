/*
Problem Statement: A Ninja has an ‘N’ Day training schedule. He has to perform one of these three activities (Running, Fighting Practice, or Learning New Moves) each day. There are merit points associated with performing an activity each day. The same activity can’t be performed on two consecutive days. We need to find the maximum merit points the ninja can attain in N Days.

We are given a 2D Array POINTS of size ‘N*3’ which tells us the merit point of specific activity on that particular day. Our task is to calculate the maximum number of merit points that the ninja can earn.
Create a dp array of size [n][4]. There are total ‘n’ days and for every day, there can be 4 choices (0,1,2 and 3). Therefore we take the dp array as dp[n][4].
Whenever we want to find the answer of particular parameters (say f(day,last)), we first check whether the answer is already calculated using the dp array(i.e dp[day][last]!= -1 ). If yes, simply return the value from the dp array.
If not, then we are finding the answer for the given value for the first time, we will use the recursive relation as usual but before returning from the function, we will set dp[day][last] to the solution we get.
 */ //memoization
int f(int day,int last,vector<vector<int>>&points,vector<vector<int>>&dp){
    if(day==0){
        int maxi=0;
        for(int task=0;task<3;task++){
            if(task!=last){
                maxi=max(maxi,points[0][task] );//if day ==0 then there is only one row 

            }
        }
        return  maxi;

    }
    if(dp[day][last]!=-1){
        return dp[day][last];
    }
    int maxi=0;
    for(int task=0;task<3;task++){
        if(task!=last){
            int point=points[day][task]+f(day-1,task,points,dp);//passing task variable since that is action performed 
            maxi=max(maxi,point);
        }
    }
    return dp[day][last]=maxi;
   
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
     
    vector<vector<int>>dp(n,vector<int>(4,-1));//four options available to take
    return f(n-1,3,points,dp);//last=3 because since nothing as took in the first one 
}
