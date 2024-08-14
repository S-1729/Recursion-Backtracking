class Solution {
  public:
    int ans=0;
    int solve(string str1,string str2,int i,int j){
        if(i>=str1.size() || j>=str2.size())
            return 0;
        int res=0;
        if(str1[i]==str2[j]){
            res=1+solve(str1,str2,i+1,j+1);
            ans=max(ans,res);
        }
        solve(str1,str2,i,j+1);
        solve(str1,str2,i+1,j);
        return res;
    }
    int longestCommonSubstr(string str1, string str2) {
        solve(str1,str2,0,0);
        return ans;
    }
};

/*
    You are given two strings str1 and str2. Your task is to find the length of the longest common substring among the given strings.
    
    Examples:
    
    Input: str1 = "ABCDGH", str2 = "ACDGHR"
    Output: 4
    Explanation: The longest common substring is "CDGH" which has length 4.
    
    Input: str1 = "ABC", str2 = "ACB"
    Output: 1
    Explanation: The longest common substrings are "A", "B", "C" all having length 1.

    T.C : O(2^(n*m))
*/
