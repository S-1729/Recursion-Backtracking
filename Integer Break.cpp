class Solution {
public:
    int solve(int n){
        if(n==1)
            return 1;
        int ans=1;
        for(int i=1;i<=n-1;i++){
            int product=i*max(n-i,solve(n-i));
            ans=max(ans,product);
        }
        return ans;
    }
    
    int integerBreak(int n) {
        return solve(n);
    }
};

/*
	Given an integer n, break it into the sum of k positive integers, where k >= 2, and maximize the product of those integers.
	Return the maximum product you can get.

	Example 1:
	Input: n = 2
	Output: 1
	Explanation: 2 = 1 + 1, 1 × 1 = 1.
	
	Example 2:
	Input: n = 10
	Output: 36
	Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.

	T.C : O(n^n)
*/ 
