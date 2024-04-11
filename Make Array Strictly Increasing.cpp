class Solution {
public:
    int solve(int ind,vector<int>& arr1, vector<int>& arr2,int prev){
        if(ind>=arr1.size())
            return 0;
        int ans1=1e9+1,ans2=1e9+1;
        if(arr1[ind]>prev)
            ans1=solve(ind+1,arr1,arr2,arr1[ind]);
        auto it=upper_bound(begin(arr2),end(arr2),prev);
        if(it!=end(arr2)){
            int j=it-begin(arr2);
            ans2=1+solve(ind+1,arr1,arr2,arr2[j]);
        }
        return min(ans1,ans2);
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(begin(arr2),end(arr2));
        int ans=solve(0,arr1,arr2,INT_MIN);
        return ans==(1e9+1)?-1:ans;
    }
};

/*
	Given two integer arrays arr1 and arr2, return the minimum number of operations (possibly zero) needed to make arr1 strictly increasing.
	In one operation, you can choose two indices 0 <= i < arr1.length and 0 <= j < arr2.length and do the assignment arr1[i] = arr2[j].
	If there is no way to make arr1 strictly increasing, return -1.

	Example 1:
	Input: arr1 = [1,5,3,6,7], arr2 = [1,3,2,4]
	Output: 1
	Explanation: Replace 5 with 2, then arr1 = [1, 2, 3, 6, 7].
	
	Example 2:
	Input: arr1 = [1,5,3,6,7], arr2 = [4,3,1]
	Output: 2
	Explanation: Replace 5 with 3 and then replace 3 with 4. arr1 = [1, 3, 4, 6, 7].
	
	Example 3:
	Input: arr1 = [1,5,3,6,7], arr2 = [1,6,3,3]
	Output: -1
	Explanation: You can't make arr1 strictly increasing.

	T.C : O(2^n)
*/
