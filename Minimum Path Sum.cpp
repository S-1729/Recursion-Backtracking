class Solution {
public:
    int solve(int i,int j,int n,int m,vector<vector<int>>& grid){
        if(i==n-1 && j==m-1)
            return grid[i][j];
        if(i==n-1)
            return grid[i][j]+solve(i,j+1,n,m,grid);
        if(j==m-1)
            return grid[i][j]+solve(i+1,j,n,m,grid);
        return grid[i][j]+min(solve(i+1,j,n,m,grid),solve(i,j+1,n,m,grid));
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        return solve(0,0,n,m,grid);
    }
};

/*
	Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.
	Note: You can only move either down or right at any point in time.

	Example 1:
	Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
	Output: 7
	Explanation: Because the path 1 ? 3 ? 1 ? 1 ? 1 minimizes the sum.
	
	Example 2:
	Input: grid = [[1,2,3],[4,5,6]]
	Output: 12
	
	T.C : (2^n)
*/
