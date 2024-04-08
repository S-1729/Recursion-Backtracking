class Solution {
public:
    vector<vector<int>>directions={{-1,0},{1,0},{0,1},{0,-1}};
    bool solve(int i,int j,int n,int m,int diff,vector<vector<int>>& heights){
        if(i==n-1 && j==m-1)
            return true;
        int prev=heights[i][j];
        heights[i][j]=-1;
        for(auto dir:directions){
            int new_i=i+dir[0];
            int new_j=i+dir[1];
            if(new_i>=0 && new_i<n && new_j>=0 && new_j<m && heights[i][j]!=-1 && abs(prev-heights[new_i][new_j])<=diff){
                if(solve(new_i,new_j,n,m,diff,heights))
                    return true;
            }
        }        
        heights[i][j]=prev;
        return false;
    }
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int low=0,high=1000000,n=heights.size(),m=heights[0].size();
        while(low<=high){
            int mid=low+(high-low)/2;
            if(solve(0,0,n,m,mid,heights))
            high=mid-1;
            else
            low=mid+1;
        }
        return low;
    }
};



class Solution {
public:
    vector<vector<int>>directions={{-1,0},{1,0},{0,1},{0,-1}};
    bool solve(int i,int j,int n,int m,int diff,vector<vector<int>>& heights,vector<vector<int>>& visited){
        if(i==n-1 && j==m-1)
            return true;
        visited[i][j]=1;
        for(auto dir:directions){
            int new_i=i+dir[0];
            int new_j=j+dir[1];
            if(new_i>=0 && new_i<n && new_j>=0 && new_j<m && visited[new_i][new_j]!=1 && abs(heights[i][j]-heights[new_i][new_j])<=diff){
                if(solve(new_i,new_j,n,m,diff,heights,visited))
                    return true;
            }
        }        
        visited[i][j]=0;
        return false;
    }
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int low=0,high=1000000,n=heights.size(),m=heights[0].size();
        while(low<=high){
            int mid=low+(high-low)/2;
             vector<vector<int>> visited(m, vector<int>(n));
            if(solve(0,0,n,m,mid,heights,visited))
            high=mid-1;
            else
            low=mid+1;
        }
        return low;
    }
};

/*
	You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). 
	You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.
	A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.
	Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

	Example 1:
	Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
	Output: 2
	Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
	This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.
	
	Example 2:
	Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
	Output: 1
	Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better than route [1,3,5,3,5].
	
	Example 3:	
	Input: heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
	Output: 0
	Explanation: This route does not require any effort.

	T.C : O(3^n)
	S.C : O(n*n)
*/
