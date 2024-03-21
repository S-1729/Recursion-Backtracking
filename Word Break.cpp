class Solution {
public:
    unordered_set<string>Set;
    bool solve(int ind,string s){
        if(ind>=s.size())
            return true;
        for(int i=ind;i<s.size();i++){
            string sub=s.substr(ind,i-ind+1);
            if(Set.find(sub)!=Set.end() && solve(i+1,s))
                return true;
        }
        return false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto word:wordDict)
            Set.insert(word);
        return solve(0,s);
    }
};

/*
	Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.
	Note that the same word in the dictionary may be reused multiple times in the segmentation.

	Example 1:	
	Input: s = "leetcode", wordDict = ["leet","code"]
	Output: true
	Explanation: Return true because "leetcode" can be segmented as "leet code".
	
	Example 2:
	Input: s = "applepenapple", wordDict = ["apple","pen"]
	Output: true
	Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
	Note that you are allowed to reuse a dictionary word.
	
	Example 3:
	Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
	Output: false
	
	T.C : O(2^n)
*/
