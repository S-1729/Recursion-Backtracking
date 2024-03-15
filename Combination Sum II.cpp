class Solution {
public:
    vector<vector<int>>ans;
    void solve(int ind,vector<int>&v,vector<int>&nums,int k){
        if(k==0){
            ans.push_back(v);
            return ;
        }
        for(int i=ind;i<nums.size();i++){
            if(i>ind && nums[i]==nums[i-1])
                continue;
            if(nums[i]>k)
                break;
            v.push_back(nums[i]);
            solve(i+1,v,nums,k-nums[i]);
            v.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>v;
        solve(0,v,candidates,target);
        return ans;
    }
};

/*
	Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.
	Each number in candidates may only be used once in the combination.
	Note: The solution set must not contain duplicate combinations.

	Example 1:
	Input: candidates = [10,1,2,7,6,1,5], target = 8
	Output: 
	[
		[1,1,6],
		[1,2,5],
		[1,7],
		[2,6]
	]
	
	Example 2:
	Input: candidates = [2,5,2,1,2], target = 5
	Output: 
	[
		[1,2,2],
		[5]
	]
	
	T.C : O(2^n)
	S.C : O(n)
*/
