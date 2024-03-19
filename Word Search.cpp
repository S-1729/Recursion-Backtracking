class Solution {
public:
    vector<vector<int>>directions={{-1,0},{0,1},{1,0},{0,-1}};
    bool solve(int i,int j,int m,int n,vector<vector<char>>& board, string word,int ind){
        if(ind>=word.size())
            return true;
        if(i<0 || j<0 || i>=m || j>=n || board[i][j]=='$' || board[i][j]!=word[ind])
            return false;
        char ch=board[i][j];
        board[i][j]='$';
        for(auto& dir:directions){
            if(solve(i+dir[0],j+dir[1],m,n,board,word,ind+1))
                return true;
        }
        board[i][j]=ch;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size(),n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    if(solve(i,j,m,n,board,word,0))
                        return true;
                }
            }
        }
        return false;
    }
};

/*
	Given an m x n grid of characters board and a string word, return true if word exists in the grid.
	The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

	Example 1:
	Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
	Output: true
	
	Example 2:
	Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
	Output: true
	
	Example 3:
	Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
	Output: false

	T.C : O(n*m*4^n)
*/
