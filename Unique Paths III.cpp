class Solution {
public:
    vector<vector<int>>directions={{-1,0},{1,0},{0,1},{0,-1}};
    int ans=0;
    void solve(int i,int j,int m,int n,int count,int countZeros,vector<vector<int>>& grid){
        if(i<0 ||i>=m || j<0 || j>=n || grid[i][j]==-1 )
            return ;
        if(grid[i][j]==2){
            if(count==countZeros)
                ans++;
            return ;
        }
        grid[i][j]=-1;
        for(auto dir:directions)
            solve(i+dir[0],j+dir[1],m,n,count+1,countZeros,grid);
        grid[i][j]=0;
        
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int countZeros=0,src_i,src_j,m=grid.size(),n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0)
                    countZeros++;
                if(grid[i][j]==1){
                    src_i=i;
                    src_j=j;
                }
            }
        }
        countZeros++;
        solve(src_i,src_j,m,n,0,countZeros,grid);
        return ans;
    }
};

/*
	You are given an m x n integer array grid where grid[i][j] could be:
		1 representing the starting square. There is exactly one starting square.
		2 representing the ending square. There is exactly one ending square.
		0 representing empty squares we can walk over.
		-1 representing obstacles that we cannot walk over.
	Return the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once.

	Example 1:
	Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
	Output: 2
	Explanation: We have the following two paths: 
	1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
	2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)

 	Example 2:
	Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,0,2]]
	Output: 4
	Explanation: We have the following four paths: 
	1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
	2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
	3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
	4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)

	T.C : O(3^(m*n))
*/
