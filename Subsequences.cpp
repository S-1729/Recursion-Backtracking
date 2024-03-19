class Solution {
public:
    void solve(string s,int i,string str,vector<string>&ans)
	{
		if(i>=s.size()){
			ans.push_back(str);
			return ;
		}
		solve(s,i+1,str,ans);
		solve(s,i+1,str+s[i],ans);
	
	}

	vector<string> Subsequences(string s)
	{
		vector<string>ans;
		solve(s,0,"",ans);
		return ans;
	}
};

/*
	Given string, return all possible subsequences.
	
	Example 1:
	Input: nums = "abc"
	Output: ["","a","b","c","ab","ac","bc","abc"]
	
	T.C : O(2^n)
	S.C : O(n)
*/
