/*
A Derangement is a permutation of ‘N’ elements, such that no element appears in its original position. For example, an instance  of derangement of {0, 1, 2, 3} is {2, 3, 1, 0}, because 2 present at index 0 is not at its initial position which is 2 and similarly for other elements of the sequence.
  */
#define MODANSWER 1000000007
long long int countDerangements(int n) {
    if(n == 1){
        return 0;
    }
    
    if(n&1){
        // odd number
        return (n*countDerangements(n-1) - 1)%MODANSWER;
    }
    else{
        return (n*countDerangements(n-1) + 1)%MODANSWER;
    }
}
