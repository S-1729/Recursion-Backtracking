class Solution {
public:
    int solve(int source, int step, int dest)
    {
        if (abs(source) > (dest))
            return INT_MAX;
        if (source == dest)
            return step;
        int pos = solve(source + step + 1, step + 1, dest);
        int neg = solve(source - step - 1, step + 1, dest);
        return min(pos, neg);
    }

    int minSteps(int D)
    {
        return solve(0, 0, D);
    }
};

/*
    Given an infinite number line. You start at 0 and can go either to the left or to the right. The condition is that in the ith move, you must take i steps. Given a destination d, find the minimum number of steps required to reach that destination.
    
    Example 1:
    Input: d = 2
    Output: 3
    Explaination: The steps takn are +1, -2 and +3.

    Example 2:
    Input: d = 10
    Output: 4
    Explaination: The steps are +1, +2, +3 and +4.

    T.C : O(2^d)
*/
