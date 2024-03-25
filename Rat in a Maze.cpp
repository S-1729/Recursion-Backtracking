class Solution{
public:
	int di[4]={0,1,0,-1};
	int dj[4]={1,0,-1,0};
	string d="RDLU";
	void count(int n,vector<vector<int>>&m,int i,int j,string &path,vector<string>&ans){
	    if(i<0 or j<0 or i>=n or j>=n or m[i][j]==0) 
			return;
	    if(i==n-1 and j==n-1){
	        ans.push_back(path);
	        return;
	    }
	    m[i][j]=0;
	    for(int x=0;x<4;x++){
	        path.push_back(d[x]);
	        count(n,m,i+di[x],j+dj[x],path,ans);
	        path.pop_back();
	    }
	    m[i][j]=1;
	}
	
	vector<string> findPath(vector<vector<int>> &m, int n) {
	    string path="";
	    vector<string>ans;
	    count(n,m,0,0,path,ans);
	    return ans;
	}
};

/*
	Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). 
	Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). 
	Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
	Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell.
	
	Example 1:
	Input:
	N = 4
	m[][] = {{1, 0, 0, 0},
			{1, 1, 0, 1},
			{1, 1, 0, 0},
			{0, 1, 1, 1}}
	Output: DDRDRR DRDDRR
	Explanation:
	The rat can reach the destination at (3, 3) from (0, 0) by two paths - DRDDRR and DDRDRR, when printed in sorted order we get DDRDRR DRDDRR.
	
	Example 2:
	Input:
	N = 2
	m[][] = {{1, 0},
			{1, 0}}
	Output: -1
	Explanation:
	No path exists and destination cell is blocked.
	
	T.C : O(3^(n*n))
*/
