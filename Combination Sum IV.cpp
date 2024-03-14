class Solution {
public:
    int ans=0;
    void solve(int idx,vector<int>&nums,int target){
        if(target<0 || idx>=nums.size())
            return ;
        if(target==0){
            ans++;
            return ;
        }
        for(int i=0;i<nums.size();i++){
            solve(i,nums,target-nums[i]);
        }
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        solve(0,nums,target);
        return ans;
    }
};

/*
	Given an array of distinct integers nums and a target integer target, return the number of possible combinations that add up to target.
	The test cases are generated so that the answer can fit in a 32-bit integer.

	Example 1:
	Input: nums = [1,2,3], target = 4
	Output: 7
	Explanation:
	The possible combination ways are:
	(1, 1, 1, 1)
	(1, 1, 2)
	(1, 2, 1)
	(1, 3)
	(2, 1, 1)
	(2, 2)
	(3, 1)
	Note that different sequences are counted as different combinations.
	
	Example 2:
	Input: nums = [9], target = 3
	Output: 0
	
	T.C : O(2^n)
*/
