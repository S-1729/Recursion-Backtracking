class Solution {

  public:
    int solve(string x,string y,int costx,int costy,int i,int j){
        if(i>=x.size())
            return costy*(y.size()-j);
        if(j>=y.size())
            return costx*(x.size()-i);
        if(x[i]==y[j])
            return solve(x,y,costx,costy,i+1,j+1);
        return min(costx+solve(x,y,costx,costy,i+1,j),costy+solve(x,y,costx,costy,i,j+1));
    }
    int findMinCost(string x, string y, int costX, int costY) {
        return solve(x,y,costX,costY,0,0);
    }
};

/*
    Given two strings x and y, and two values costX and costY, the task is to find the minimum cost required to make the given two strings identical. You can delete characters from both the strings. The cost of deleting a character from string X is costX and from Y is costY. The cost of removing all characters from a string is the same.
    
    Example 1:
    Input: x = "abcd", y = "acdb", costX = 10 ,costY = 20.
    Output: 30
    Explanation: For Making both strings identical we have to delete character 'b' from both the string, hence cost will be = 10 + 20 = 30.
    
    Example 2:
    Input : x = "ef", y = "gh", costX = 10, costY = 20.
    Output: 60
    Explanation: For making both strings identical, we have to delete 2-2 characters from both the strings, hence cost will be = 10 + 10 + 20 + 20 = 60.

    T.C : O(2^n)
*/
