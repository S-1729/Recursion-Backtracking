class Solution{   
public:
    bool solve(int ind,vector<int>arr, int sum){
        if(sum==0)
            return true;
        if(ind>=arr.size() || sum<0)
            return false;
        return solve(ind+1,arr,sum)|solve(ind+1,arr,sum-arr[ind]);
    }
    
    bool isSubsetSum(vector<int>arr, int sum){
        return solve(0,arr,sum);
    }
};

/*
	Given an array of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum. 
	
	Example 1:
	Input:
	N = 6
	arr[] = {3, 34, 4, 12, 5, 2}
	sum = 9
	Output: 1 
	Explanation: Here there exists a subset with sum = 9, 4+3+2 = 9.
	
	Example 2:
	Input:
	N = 6
	arr[] = {3, 34, 4, 12, 5, 2}
	sum = 30
	Output: 0 
	Explanation: There is no subset with sum 30.
	
	T.C : O(2^n)
*/
