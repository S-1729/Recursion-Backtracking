class Solution
{
	public:
	  long long Pow(long long x,long long n,long long M){
	      if(n==0)
	        return 1;
	      long long val=Pow(x,n/2,M)%M;
	      if(n&1)
	          return (val%M*val%M*x%M)%M;
	      return (val%M*val%M)%M;
	  }
		long long int PowMod(long long int x,long long int n,long long int M)
		{
		    long long ans=Pow(x,n,M);
		    return ans%M;
		}
};

/*
    Implement pow(x, n) % M.
    In other words, for a given value of x, n, and M, find  (xn) % M.
     
    Example 1:
    Input:
    x = 3, n = 2, m = 4
    Output:
    1
    Explanation:
    32 = 9. 9 % 4 = 1.
    
    Example 2:
    Input:
    x = 2, n = 6, m = 10
    Output:
    4
    Explanation:
    26 = 64. 64 % 10 = 4.

    T.C : O(logn)
*/
