class Solution {
public:
    unordered_map<int,string>mp={{2,"abc"},{3,"def"},{4,"ghi"},{5,"jkl"},{6,"mno"},{7,"pqrs"},{8,"tuv"},{9,"wxyz"}};
    vector<string>ans;
    void solve(int idx,string s,string digits){
        if(idx>=digits.size()){
            ans.push_back(s);
            return ;
        }
        int num=digits[idx]-'0';
        string value=mp[num];
        for(int i=0;i<value.size();i++)
            solve(idx+1,s+value[i],digits);
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)
            return ans;
        solve(0,"",digits);
        return ans;
    }
};

/*
	Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. 
	Return the answer in any order.
	A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
	
	Example 1:
	Input: digits = "23"
	Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
	
	Example 2:
	Input: digits = ""
	Output: []
	
	Example 3:
	Input: digits = "2"
	Output: ["a","b","c"]
	
	T.C : O(3^n)
*/
