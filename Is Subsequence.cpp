class Solution {
public:
    bool solve(int i,int j,string s,string t){
        if(i==s.size())
            return true;
        if(j==t.size())
            return false;
        if(s[i]==t[j])
            return solve(i+1,j+1,s,t);
        else
            return solve(i,j+1,s,t);
    }
    
    bool isSubsequence(string s, string t) {
        return solve(0,0,s,t);
    }
};

/*
	Given two strings s and t, return true if s is a subsequence of t, or false otherwise.
	A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

	Example 1:
	Input: s = "abc", t = "ahbgdc"
	Output: true
	
	Example 2:
	Input: s = "axc", t = "ahbgdc"
	Output: false

	T.C : O(max(n,m))
*/
