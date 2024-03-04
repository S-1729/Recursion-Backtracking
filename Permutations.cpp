class Solution {
public:
    vector<vector<int>>ans;
    void solve(vector<int>&nums,int idx)
    {
        if(nums.size()==idx){
            ans.push_back(nums);
            return ;
        }
        for(int i=idx;i<nums.size();i++){
            swap(nums[i],nums[idx]);
            solve(nums,idx+1);
            swap(nums[i],nums[idx]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        solve(nums,0);
        return ans;
    }
};

/*
	Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
	
	Example 1:
	Input: nums = [1,2,3]
	Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
	
	Example 2:
	Input: nums = [0,1]
	Output: [[0,1],[1,0]]
	
	Example 3:
	Input: nums = [1]
	Output: [[1]]
	
	T.C : O(n!)
*/
