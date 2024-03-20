class Solution {
public:
    int solve(vector<int>&nums,int ind,int prev){
        if(ind>=nums.size())
            return 0;
        int take=0;
        if(nums[ind]>prev)
            take=1+solve(nums,ind+1,nums[ind]);
        int not_take=solve(nums,ind+1,prev);
        return max(take,not_take);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        return solve(nums,0,INT_MIN);
    }
};

/*
	Given an integer array nums, return the length of the longest strictly increasing subsequence.
	
	Example 1:
	Input: nums = [10,9,2,5,3,7,101,18]
	Output: 4
	Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
	
	Example 2:
	Input: nums = [0,1,0,3,2,3]
	Output: 4
	
	Example 3:
	Input: nums = [7,7,7,7,7,7,7]
	Output: 1
	
	T.C : O(2^n)
*/
