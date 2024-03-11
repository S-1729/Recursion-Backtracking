class Solution {
public:
    vector<vector<string>>ans;
    void solve(int col,int n,vector<string>board,vector<int>leftRow,vector<int>lowerDiagonal,vector<int>upperDiagonal){
        if(col>=n){
            ans.push_back(board);
            return ;
        }
        for(int row=0;row<n;row++){
            if(leftRow[row]==0 && lowerDiagonal[row+col]==0 && upperDiagonal[n-1+col-row]==0){
                leftRow[row]=lowerDiagonal[row+col]=upperDiagonal[n-1+col-row]=1;
                board[row][col]='Q';
                solve(col+1,n,board,leftRow,lowerDiagonal,upperDiagonal);
                leftRow[row]=lowerDiagonal[row+col]=upperDiagonal[n-1+col-row]=0;
                board[row][col]='.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<int>leftRow(n,0),lowerDiagonal(2*n-1,0),upperDiagonal(2*n-1,0);
        string s(n,'.');
        vector<string>board(n,s);
        solve(0,n,board,leftRow,lowerDiagonal,upperDiagonal);
        return ans;
    }
};

/*
	The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
	Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
	Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

	Example 1:
	Input: n = 4
	Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
	Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
	
	Example 2:
	Input: n = 1
	Output: [["Q"]]
	
	T.C : O(n!)
	S.C : O(n)
*/
