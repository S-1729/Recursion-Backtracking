class Solution
{
    public:
    const int MOD=1e9+7;
    int solve(int n){
        if(n<3)
            return 1;
        return (solve(n-2)%MOD+solve(n-3)%MOD)%MOD;
    }

    int padovanSequence(int n)
    {
       return solve(n)%MOD;
    }  
};

/*
    Given a number n, find the nth number in the Padovan Sequence. 
    A Padovan Sequence is a sequence which is represented by the following recurrence relation
    P(n) = P(n-2) + P(n-3)
    P(0) = P(1) = P(2) = 1
    Note: Since the output may be too large, compute the answer modulo 10^9+7.
    
    Examples :
    
    Input: n = 3
    Output: 2
    Explanation: We already know, P1 + P0 = P3 and P1 = 1 and P0 = 1
    
    Input: n = 4
    Output: 2
    Explanation: We already know, P4  = P2 + P1 and P2 = 1 and P1 = 1

    T.C : O(2^n)
  */
