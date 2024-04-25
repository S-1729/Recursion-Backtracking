class Solution {
public:
    int solve(int i,string s,int k,int prev){
        if(i>=s.size())
            return 0;
        int take=0,not_take=0;
        if(prev==-1 || abs((s[i]-'a')-prev)<=k){
            take=1+solve(i+1,s,k,(s[i]-'a'));
        }
        not_take=solve(i+1,s,k,prev);
        return max(take,not_take);
    }
    
    int longestIdealString(string s, int k) {
        return solve(0,s,k,-1);
    }
};

/*
	You are given a string s consisting of lowercase letters and an integer k. We call a string t ideal if the following conditions are satisfied:
		.t is a subsequence of the string s.
		.The absolute difference in the alphabet order of every two adjacent letters in t is less than or equal to k.
	Return the length of the longest ideal string.
	A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.
	Note that the alphabet order is not cyclic. For example, the absolute difference in the alphabet order of 'a' and 'z' is 25, not 1.

	Example 1:
	Input: s = "acfgbd", k = 2
	Output: 4
	Explanation: The longest ideal string is "acbd". The length of this string is 4, so 4 is returned.
	Note that "acfgbd" is not ideal because 'c' and 'f' have a difference of 3 in alphabet order.
	
	Example 2:
	Input: s = "abcd", k = 3
	Output: 4
	Explanation: The longest ideal string is "abcd". The length of this string is 4, so 4 is returned.

	T.C : O(2^n)
*/
