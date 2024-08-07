class Solution {
public:
    unordered_map<int, string> belowTen = { {0, ""}, {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"}, {6, "Six"}, {7, "Seven"}, {8, "Eight"}, {9, "Nine"} };
    unordered_map<int, string> belowTwenty = { {10, "Ten"}, {11, "Eleven"}, {12, "Twelve"}, {13, "Thirteen"}, {14, "Fourteen"}, {15, "Fifteen"}, {16, "Sixteen"}, {17, "Seventeen"}, {18, "Eighteen"}, {19, "Nineteen"} };
    unordered_map<int, string> belowHundred = { {1, "Ten"}, {2, "Twenty"}, {3, "Thirty"}, {4, "Forty"}, {5, "Fifty"}, {6, "Sixty"}, {7, "Seventy"}, {8, "Eighty"}, {9, "Ninety"} };

    string solve(int num) {
        if(num<10)
            return belowTen[num];
        else if(num<20)
            return belowTwenty[num];
        else if(num<100)
            return belowHundred[num/10]+(num%10!=0 ? " "+belowTen[num%10] : "");
        else if(num<1000)
            return solve(num/100)+" Hundred"+(num%100!=0 ? " "+solve(num%100) : "");
        else if(num<1000000)
            return solve(num/1000)+" Thousand"+(num%1000!=0 ? " "+solve(num%1000) : "");
        else if(num<1000000000)
            return solve(num/1000000)+" Million"+(num%1000000!=0 ? " "+solve(num%1000000) : "");
        return solve(num/1000000000)+" Billion"+(num%1000000000!=0 ? " "+solve(num%1000000000) : "");
    }

    string numberToWords(int num) {
        if(num==0)
            return "Zero";
        return solve(num);
    }
};

/*
    Convert a non-negative integer num to its English words representation.
      
    Example 1:
    Input: num = 123
    Output: "One Hundred Twenty Three"
    
    Example 2:
    Input: num = 12345
    Output: "Twelve Thousand Three Hundred Forty Five"
    
    Example 3:
    Input: num = 1234567
    Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
    
    T.C : O(log10(n))
*/
