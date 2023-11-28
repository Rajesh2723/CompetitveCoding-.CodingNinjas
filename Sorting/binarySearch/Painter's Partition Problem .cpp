/*
given-an-array-list-of-length-n-where-the-array-list-represents-the-boards-and-each-element-of-the-given-array-list-represents-the-length-of-each-board-some-k-numbers-of-painters-are-available-to-paint-these-boards-consider-that-each-unit-of-a-board-takes-1-unit-of-time-to-paint
  */
bool required(vector<int>&boards,int k,int mid){
   int n=boards.size();
   int painterCount=1;
   int painterTime=0;
   for(int i=0;i<boards.size();i++){
      if(painterTime+boards[i]<=mid){
         painterTime+=boards[i];
      }else{
         painterCount++;
         if(painterCount>k||boards[i]>mid){
            return false;
         } 
         painterTime=boards[i];
      }
   }
   return true;
}
int findLargestMinDistance(vector<int> &boards, int k)
{
   int start=0;
   int sum=0;
   for(int i=0;i<boards.size();i++){
      sum+=boards[i];
   }
   int end=sum;
   int ans=-1;
   while(start<=end){
      int mid=start+(end-start)/2;
      if(required(boards,k,mid)){
         ans=mid;
         end=mid-1;

      }else{
        start=mid+1;
      }
   }
   return ans;
    

}
