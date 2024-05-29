class Solution {
  public:
    int solve(int n,int x,int y){
        if(n<=0)
            return false;
        bool a=true,b=true,c=true;
        if(n>=x)
            a=solve(n-x,x,y);
        if(n>=y)
            b=solve(n-y,x,y);
        if(n>=1)
            c=solve(n-1,x,y);
        return (!a||!b||!c);
    }
    int findWinner(int n, int x, int y) {
        memset(dp,-1,sizeof dp);
        return solve(n,x,y);
    }
};

//Code-2
class Solution {
  public:
    int solve(int n,int x,int y){
        if(n<=1)
            return n;
        int ans=1;
        if(n>=x)
            ans=ans&solve(n-x,x,y);
        if(n>=y)
            ans=ans&solve(n-y,x,y);
        ans=ans&solve(n-1,x,y);
        return ans^1;
    }
    int findWinner(int n, int x, int y) {
        return solve(n,x,y);
    }
};

/*
    Given three numbers n, x, and y, Geek and his friend are playing a coin game. In the beginning, there are n coins. In each move, a player can pick x, y, or 1 coin. Geek always starts the game. The player who picks the last coin wins the game. The task is to determine whether Geek will win the game or not if both players play optimally.
    
    Example 1:
    Input: 
    n = 5
    x = 3
    y = 4
    Output: 
    1
    Explanation:
    There are 5 coins, every player can pick 1 or 3 or 4 coins on his/her turn. Geek can win by picking 3 coins in first chance. Now 2 coins will be left so his friend will pick one coin and now Geek can win by picking the last coin.
    
    Example 2:
    Input:
    n = 2
    x = 3
    y = 4
    Output:
    0
    Explanation: 
    Geek picks 1 coin and then his friend picks 1 coin.

    T.C : O(3^n)
*/
