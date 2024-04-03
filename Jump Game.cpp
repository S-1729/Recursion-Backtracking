class Solution {
public:
    bool solve(int ind,vector<int>& nums){
        if(ind>=nums.size()-1)
            return true;
        for(int i=1;i<=nums[ind];i++){
            if(solve(ind+i,nums))
                return true;
        }
        return false;
    }
    bool canJump(vector<int>& nums) {
        return solve(0,nums);
    }
};

/*
	You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.
	Return true if you can reach the last index, or false otherwise.
	
	Example 1:
	Input: nums = [2,3,1,1,4]
	Output: true
	Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
	
	Example 2:	
	Input: nums = [3,2,1,0,4]
	Output: false
	Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.

	T.C : O(n^n)
*/
