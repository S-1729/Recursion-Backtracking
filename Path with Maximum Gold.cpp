class Solution {
public:
    vector<vector<int>>directions={{-1,0},{0,-1},{1,0},{0,1}};
    int solve(int i,int j,int n,int m,vector<vector<int>>&grid){
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]==0)
            return 0;
        int ans=0;
        int val=grid[i][j];
        grid[i][j]=0;
        for(auto &dir:directions){
            ans=max(ans,val+solve(i+dir[0],j+dir[1],n,m,grid));
        }
        grid[i][j]=val;
        return ans;
    }
        
    int getMaximumGold(vector<vector<int>>& grid) {
        int ans=0,n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0){
                    ans=max(ans,solve(i,j,n,m,grid));
                }
            }
        }
        return ans;
    }
};

/*
    In a gold mine grid of size m x n, each cell in this mine has an integer representing the amount of gold in that cell, 0 if it is empty.
    Return the maximum amount of gold you can collect under the conditions:

     .Every time you are located in a cell you will collect all the gold in that cell.
     .From your position, you can walk one step to the left, right, up, or down.
     .You can't visit the same cell more than once.
     .Never visit a cell with 0 gold.
     .You can start and stop collecting gold from any position in the grid that has some gold.
 

    Example 1:
    Input: grid = [[0,6,0],[5,8,7],[0,9,0]]
    Output: 24
    Explanation:
    [[0,6,0],
     [5,8,7],
     [0,9,0]]
    Path to get the maximum gold, 9 -> 8 -> 7.

    Example 2:
    Input: grid = [[1,0,7],[2,0,6],[3,4,5],[0,3,0],[9,0,20]]
    Output: 28
    Explanation:
    [[1,0,7],
     [2,0,6],
     [3,4,5],
     [0,3,0],
     [9,0,20]]
    Path to get the maximum gold, 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7.

    T.C : O(4^(n*m))
*/
