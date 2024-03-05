class Solution {
public:
    vector<vector<int>>ans;
    void solve(int idx,vector<int>&nums,vector<int>&v){
        if(idx>=nums.size()){
            ans.push_back(v);
            return ;
        }
        solve(idx+1,nums,v);
        v.push_back(nums[idx]);
        solve(idx+1,nums,v);
        v.pop_back();
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>v;
        solve(0,nums,v);
        return ans;
    }
};

/*
	Given an integer array nums of unique elements, return all possible subsets (the power set).
	The solution set must not contain duplicate subsets. Return the solution in any order.

	Example 1:
	Input: nums = [1,2,3]
	Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
	
	Example 2:
	Input: nums = [0]
	Output: [[],[0]]
	
	T.C : O(2^n)
	S.C : O(n)
*/
