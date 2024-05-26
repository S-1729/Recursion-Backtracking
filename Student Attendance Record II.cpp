class Solution {
public:
    int solve(int i,int n,int absent,int late){
        if(i>=n)
            return 1;
        int ans=0;
        ans+=solve(i+1,n,absent,0);
        if(absent<1)
            ans+=solve(i+1,n,absent+1,0);
        if(late<2)
            ans+=solve(i+1,n,absent,late+1);
        return ans;
    }
    int checkRecord(int n) {
        return solve(0,n,0,0);
    }
};

/*
    An attendance record for a student can be represented as a string where each character signifies whether the student was absent, late, or present on that day. The record only contains the following three characters:
      .  'A': Absent.
      .  'L': Late.
      .  'P': Present.
    Any student is eligible for an attendance award if they meet both of the following criteria:
      .  The student was absent ('A') for strictly fewer than 2 days total.
      .  The student was never late ('L') for 3 or more consecutive days.
    Given an integer n, return the number of possible attendance records of length n that make a student eligible for an attendance award. The answer may be very large, so return it modulo 109 + 7.
    
    Example 1:
    Input: n = 2
    Output: 8
    Explanation: There are 8 records with length 2 that are eligible for an award:
    "PP", "AP", "PA", "LP", "PL", "AL", "LA", "LL"
    Only "AA" is not eligible because there are 2 absences (there need to be fewer than 2).
    
    Example 2:
    Input: n = 1
    Output: 3
    
    Example 3:
    Input: n = 10101
    Output: 183236316

    T.C : O(3^n)
*/
