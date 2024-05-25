class Solution {
public:
    vector<string>ans;
    void solve(int ind,string s,unordered_set<string>S,string str){
        if(ind>=s.size()){
            ans.push_back(str);
            return ;
        }
        for(int i=ind;i<s.size();i++){
            string subStr=s.substr(ind,i-ind+1);
            if(S.find(subStr)!=S.end()){
                if(i+1>=s.size())
                    solve(i+1,s,S,str+subStr);
                else
                    solve(i+1,s,S,str+subStr+" ");
            }
        }
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>S;
        for(auto &str:wordDict)
            S.insert(str);
        solve(0,s,S,"");
        return ans;
    }
};

/*
    Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in any order.
    Note that the same word in the dictionary may be reused multiple times in the segmentation.
    
    Example 1:
    Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
    Output: ["cats and dog","cat sand dog"]
    
    Example 2:
    Input: s = "pineapplepenapple", wordDict = ["apple","pen","applepen","pine","pineapple"]
    Output: ["pine apple pen apple","pineapple pen apple","pine applepen apple"]
    Explanation: Note that you are allowed to reuse a dictionary word.
    
    Example 3:
    Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
    Output: []

    T.C : O(2^n)
    S.C : O(n)
*/
