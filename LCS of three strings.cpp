class Solution
{
    public:
    int solve(int i,int j,int k,int n1,int n2,int n3,string s1,string s2,string s3){
        if(i>=n1 || j>=n2 || k>=n3)
            return 0;
        if(s1[i]==s2[j] && s2[j]==s3[k])
            return 1+solve(i+1,j+1,k+1,n1,n2,n3,s1,s2,s3);
        else{
            int a=solve(i+1,j,k,n1,n2,n3,s1,s2,s3);
            int b=solve(i,j+1,k,n1,n2,n3,s1,s2,s3);
            int c=solve(i,j,k+1,n1,n2,n3,s1,s2,s3);
            return max({a,b,c});
        }
    }
    
    int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
    {
        return solve(0,0,0,n1,n2,n3,A,B,C);
    }
};

/*
	Given 3 strings A, B and C, the task is to find the length of the longest sub-sequence that is common in all the three given strings.
	
	Example 1:
	Input:
	A = "geeks"
	B = "geeksfor", 
	C = "geeksforgeeks"
	Output: 5
	Explanation: 
	"geeks"is the longest common subsequence with length 5.
	
	Example 2:	
	Input: 
	A = "abcd"
	B = "efgh"
	C = "ijkl"
	Output: 0
	Explanation: 
	There's no subsequence common in all the three strings.
	
	T.C : O(3^n)
*/
