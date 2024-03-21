class Solution {
public:
    string solve(int n)
    {
        if(n==1)
            return "0";
        string s1=solve(n-1);
        string s2=s1;
        reverse(s2.begin(),s2.end());
        for(int i=0;i<s2.size();i++){
            if(s2[i]=='0')
            s2[i]='1';
            else
            s2[i]='0';
        }
        return s1+'1'+s2;
    }

    char findKthBit(int n, int k) {
        string ans=solve(n);
        return ans[k-1];
    }
};

/*
	Given two positive integers n and k, the binary string Sn is formed as follows:

		S1 = "0"
		Si = Si - 1 + "1" + reverse(invert(Si - 1)) for i > 1
	Where + denotes the concatenation operation, reverse(x) returns the reversed string x, and invert(x) inverts all the bits in x (0 changes to 1 and 1 changes to 0).
	
	For example, the first four strings in the above sequence are:	
	S1 = "0"
	S2 = "011"
	S3 = "0111001"
	S4 = "011100110110001"
	Return the kth bit in Sn. It is guaranteed that k is valid for the given n.

	T.C : O(n^2)
	S.C : O(n)
*/
