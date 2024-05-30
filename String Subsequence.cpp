class Solution {
  public:
    int ans=0;
    void solve(string s1,string s2,int i,int j,int n,int m){
        if(j>=m){
            ans++;
            return ;
        }
        if(i>=n)
            return ;
        if(s1[i]==s2[j])
            solve(s1,s2,i+1,j+1,n,m);
        solve(s1,s2,i+1,j,n,m);
    }
    int countWays(string s1, string s2) {
        solve(s1,s2,0,0,s1.size(),s2.size());
        return ans;
    }
};

//Code-2
class Solution {
  public:
    const int MOD=1e9+7;
    int solve(string s1,string s2,int i,int j,int n,int m){
        if(j>=m)
            return 1;
        if(i>=n)
            return 0;
        if(s1[i]==s2[j])
            return (solve(s1,s2,i+1,j+1,n,m)%MOD+solve(s1,s2,i+1,j,n,m)%MOD)%MOD;
        return solve(s1,s2,i+1,j,n,m)%MOD;
    }
    int countWays(string s1, string s2) {
        return solve(s1,s2,0,0,s1.size(),s2.size())%MOD;
    }
};

//Code-3
class Solution {
  public:
    const int MOD=1e9+7;
    int solve(string s1,string s2,int i,int j,int n,int m){
        if(j>=m)
            return 1;
        if(i>=n)
            return 0;
        int take=0,not_take=0;
        if(s1[i]==s2[j])
            take=solve(s1,s2,i+1,j+1,n,m)%MOD;
        not_take=solve(s1,s2,i+1,j,n,m)%MOD;
        return take+not_take;
    }
    int countWays(string s1, string s2) {
        return solve(s1,s2,0,0,s1.size(),s2.size())%MOD;
    }
};

/*
    Given two strings, s1 and s2, count the number of subsequences of string s1 equal to string s2.
    Return the total count modulo 1e9+7.
    
    Example 1:
    Input: s1 = geeksforgeeks, s2 = gks
    Output: 4
    Explaination: We can pick characters from s1 as a subsequence from indices {0,3,4}, {0,3,12}, {0,11,12} and {8,11,12}.So total 4 subsequences of s1 that are equal to s2.
    
    Example 2:
    Input: s1 = problemoftheday, s2 = geek
    Output: 0
    Explaination: No subsequence of string s1 is equal to string s2.

    T.C : O(2^n)
*/
