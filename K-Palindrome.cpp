class Solution{
public:
    int solve(string s,int i,int j){
        if(i>=j)
            return 0;
        if(s[i]==s[j])
            return solve(s,i+1,j-1);
        else
            return 1+min(solve(s,i+1,j),solve(s,i,j-1));
    }
    
    int kPalindrome(string str, int n, int k)
    {
        int ans=solve(str,0,str.size()-1);
        return ans<=k;
    }
};

/*
    Given a string str of length n, find if the string is K-Palindrome or not. A k-palindrome string transforms into a palindrome on removing at most k characters from it.
    
    Example 1:
    Input: str = "abcdecba"
    n = 8, k = 1
    Output: 1
    Explaination: By removing 'd' or 'e' 
    we can make it a palindrome.
    
    Example 2:
    Input: str = "abcdefcba"
    n = 9, k = 1
    Output: 0
    Explaination: By removing a single 
    character we cannot make it a palindrome.

    T.C : O(2^n)
*/
