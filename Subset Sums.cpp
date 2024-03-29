class Solution {
public:
    vector<int>ans;
    void solve(int ind,int sum,vector<int> arr, int N){
        if(ind>=N){
            ans.push_back(sum);
            return ;
        }
        solve(ind+1,sum,arr,N);
        solve(ind+1,sum+arr[ind],arr,N);
    }
    
    vector<int> subsetSums(vector<int> arr, int N)
    {
        solve(0,0,arr,N);
        return ans;
    }
};

/*
	Given a list arr of N integers, return sums of all subsets in it.
	
	Example 1:
	Input:
	N = 2
	arr[] = {2, 3}
	Output:
	0 2 3 5
	Explanation:
	When no elements is taken then Sum = 0.
	When only 2 is taken then Sum = 2.
	When only 3 is taken then Sum = 3.
	When element 2 and 3 are taken then 
	Sum = 2+3 = 5.
	
	Example 2:
	Input:
	N = 3
	arr = {5, 2, 1}
	Output:
	0 1 2 3 5 6 7 8
	
	T.C : O(2^n)
	S.C : O(2^n)
*/
