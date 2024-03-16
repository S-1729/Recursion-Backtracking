class Solution {
public:
    vector<vector<string>>ans;
    bool isPalindrome(string s,int i,int j){
        while(i<=j){
            if(s[i]!=s[j])
            return false;
            i++,j--;
        }
        return true;
    }

    void solve(int ind,string s,vector<string>v){
        if(ind==s.size()){
            ans.push_back(v);
            return ;
        }
        for(int i=ind;i<s.size();i++){
            if(isPalindrome(s,ind,i)){
                v.push_back(s.substr(ind,i-ind+1));
                solve(i+1,s,v);
                v.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s){
        vector<string>v;
        solve(0,s,v);
        return ans;
    }
};

/*
	Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

	Example 1:
	Input: s = "aab"
	Output: [["a","a","b"],["aa","b"]]
	
	Example 2:
	Input: s = "a"
	Output: [["a"]]
	
	T.C : O(2^n)
*/
