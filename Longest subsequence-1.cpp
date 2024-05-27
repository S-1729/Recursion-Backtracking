class Solution {
  public:
    int solve(int ind,int prev,int n,vector<int> &a){
        if(ind>=n)
            return 0;
        int take=0;
        if(prev==-1 || abs(a[ind]-prev)==1)
            take=1+solve(ind+1,a[ind],n,a);
        int not_take=solve(ind+1,prev,n,a);
        return max(take,not_take);
    }
    int longestSubseq(int n, vector<int> &a) {
        return solve(0,-1,n,a);
    }
};

/*
    Given an integer array a[] of size n, find the length of the longest subsequence such that the absolute difference between adjacent elements is 1.
    
    Example 1:
    Input:
    n = 7
    a[] = {10, 9, 4, 5, 4, 8, 6}
    Output: 
    3
    Explaination: 
    The three possible subsequences of length 3 are {10, 9, 8}, {4, 5, 4}, and {4, 5, 6}, where adjacent elements have a absolute difference of 1. No valid subsequence of greater length could be formed.
    
    Example 2:
    Input: 
    n = 5
    a[] = {1, 2, 3, 4, 5}
    Output: 
    5
    Explaination: 
    All the elements can be included in the valid subsequence.

    T.C : O(2^n)
*/
