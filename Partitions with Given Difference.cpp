class Solution {
  public:
    int solve(int ind,int n,int target,vector<int>& arr){
        if(ind>=n){
            if(target==0)
                return 1;
            return 0;
        }
        int not_take=solve(ind+1,n,target,arr);
        int take=0;
        if(arr[ind]<=target)
            take+=solve(ind+1,n,target-arr[ind],arr);
        return take+not_take;
    }
    int countPartitions(int n, int d, vector<int>& arr) {
        int sum=accumulate(begin(arr),end(arr),0);
         if(sum<d || (sum-d)%2==1) return 0;
        return solve(0,n,(sum-d)/2,arr);
    }
};

/*
    Given an array arr, partition it into two subsets(possibly empty) such that each element must belong to only one subset. Let the sum of the elements of these two subsets be S1 and S2. 
    Given a difference d, count the number of partitions in which S1 is greater than or equal to S2 and the difference between S1 and S2 is equal to d. Since the answer may be large return it modulo 109 + 7.
    
    Example 1:
    Input:
    n = 4
    d = 3
    arr[] =  { 5, 2, 6, 4}
    Output: 1
    Explanation:
    There is only one possible partition of this array. Partition : {6, 4}, {5, 2}. The subset difference between subset sum is: (6 + 4) - (5 + 2) = 3.
    
    Example 2:
    Input:
    n = 4
    d = 0 
    arr[] = {1, 1, 1, 1} 
    Output: 6 
    Explanation:
    we can choose two 1's from indices {0,1}, {0,2}, {0,3}, {1,2}, {1,3}, {2,3} and put them in S1 and remaning two 1's in S2.
    Thus there are total 6 ways for partition the array arr.

    T.C : O(2^n)
*/
