class Solution {
public:
    vector<string>ans;
    void solve(int open,int close,string s,int n){
        if(open==n && close==n){
            ans.push_back(s);
            return ;
        }
        if(open<n)
            solve(open+1,close,s+'(',n);
        if(close<open)
            solve(open,close+1,s+')',n);
    }
    vector<string> generateParenthesis(int n) {
        solve(0,0,"",n);
        return ans;
    }
};

/*
	Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
	
	Example 1:	
	Input: n = 3
	Output: ["((()))","(()())","(())()","()(())","()()()"]
	
	Example 2:
	Input: n = 1
	Output: ["()"]
	
	T.C : O(2^n)
	S.C : O(n)
*/
