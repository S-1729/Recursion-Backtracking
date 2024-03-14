class Solution {
public:
    bool solve(string s,string p,int i,int j){
        if(i<0 && j<0)
            return true;
        if(i>=0 && j<0)
            return false;
        if(i<0 && j>=0){
            for(int x=0;x<=j;x++){
                if(p[x]!='*')
                    return false;
            }
            return true;
        }
        if(s[i]==p[j] || p[j]=='?')
            return solve(s,p,i-1,j-1);
        if(p[j]=='*')
            return solve(s,p,i-1,j)|solve(s,p,i,j-1);
        return false;
    }
    
    bool isMatch(string s, string p) {
        return solve(s,p,s.size()-1,p.size()-1);
    }
};

/*
	Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:
	'?' Matches any single character.
	'*' Matches any sequence of characters (including the empty sequence).
	The matching should cover the entire input string (not partial).

	Example 1:
	Input: s = "aa", p = "a"
	Output: false
	Explanation: "a" does not match the entire string "aa".
	
	Example 2:
	Input: s = "aa", p = "*"
	Output: true
	Explanation: '*' matches any sequence.
	
	Example 3:
	Input: s = "cb", p = "?a"
	Output: false
	Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.

	T.C : O(2^n)
*/
