class Solution {
public:
    bool solve(string s,int i,int j){
        if(i>=j)
            return true;
        if(s[i]==s[j])
            return solve(s,i+1,j-1);
        else
            return false;
    }
    
    string longestPalindrome(string s) {
        int start=0,maxLen=0;
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                if(solve(s,i,j)){
                    if(j-i+1>maxLen){
                        maxLen=j-i+1;
                        start=i;
                    }
                }
            }
        }
        return s.substr(start,maxLen);
    }
};

/*
	Given a string s, return the longest palindromic substring in s.
	
	Example 1:
	Input: s = "babad"
	Output: "bab"
	Explanation: "aba" is also a valid answer.
	
	Example 2:
	Input: s = "cbbd"
	Output: "bb"
	
	T.C : O(n^3)
*/
