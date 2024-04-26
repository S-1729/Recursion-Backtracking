class Solution {
public:
    int solve(int i,int j,int n,vector<vector<int>>&grid){
        if(i==n-1)
            return grid[i][j];
        int ans=INT_MAX;
        for(int col=0;col<n;col++){
            if(col!=j)
                ans=min(ans,grid[i][j]+solve(i+1,col,n,grid));
        }
        return ans;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),result=INT_MAX;
        for(int i=0;i<n;i++)
            result=min(result,solve(0,i,grid.size(),grid));
        return result;
    }
}; 

/*
    Given an n x n integer matrix grid, return the minimum sum of a falling path with non-zero shifts.
    A falling path with non-zero shifts is a choice of exactly one element from each row of grid such that no two elements chosen in adjacent rows are in the same column.

    Example 1:
    Input: grid = [[1,2,3],[4,5,6],[7,8,9]]
    Output: 13
    Explanation: 
    The possible falling paths are:
    [1,5,9], [1,5,7], [1,6,7], [1,6,8],
    [2,4,8], [2,4,9], [2,6,7], [2,6,8],
    [3,4,8], [3,4,9], [3,5,7], [3,5,9]
    The falling path with the smallest sum is [1,5,7], so the answer is 13.

    Example 2:
    Input: grid = [[7]]
    Output: 7

    T.C : O(n^n)
*/
