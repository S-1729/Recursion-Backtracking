class Solution {
public: 
    vector<vector<int>>directions={{-2,-1},{-2,1},{-1,-2},{-1,2},{2,-1},{2,1},{1,-2},{1,2}};
    double solve(int n,int k,int row,int col){
        if(row<0 || col<0 ||row>=n || col>=n||k<0)
            return 0.0;
        if(k==0)
            return 1.0;
        double ans=0;
        for(auto dir:directions){
            ans+=solve(n,k-1,row+dir[0],col+dir[1]);
        }
        return (ans/8.0);
    }
    double knightProbability(int n, int k, int row, int column) {
        return solve(n,k,row,column);
    }
};

/*
	On an n x n chessboard, a knight starts at the cell (row, column) and attempts to make exactly k moves. 
	The rows and columns are 0-indexed, so the top-left cell is (0, 0), and the bottom-right cell is (n - 1, n - 1).
	A chess knight has eight possible moves it can make, as illustrated below. Each move is two cells in a cardinal direction, then one cell in an orthogonal direction.
	Each time the knight is to move, it chooses one of eight possible moves uniformly at random (even if the piece would go off the chessboard) and moves there.
	The knight continues moving until it has made exactly k moves or has moved off the chessboard.
	Return the probability that the knight remains on the board after it has stopped moving.
	
	Example 1:
	Input: n = 3, k = 2, row = 0, column = 0
	Output: 0.06250
	Explanation: There are two moves (to (1,2), (2,1)) that will keep the knight on the board.
	From each of those positions, there are also two moves that will keep the knight on the board.
	The total probability the knight stays on the board is 0.0625.
	
	Example 2:
	Input: n = 1, k = 0, row = 0, column = 0
	Output: 1.00000
	
	T.C : O(8^(n*n))
*/
