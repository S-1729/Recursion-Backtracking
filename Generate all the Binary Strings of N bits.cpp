class Solution {
public:
    vector<string>ans;
    void solve(string str,int n){
        if(str.size()>=n){
        	ans.push_back(str);
        	return ;
		}
        solve(str+"0",n);
        solve(str+"1",n);
    }
    
    int numTilings(int n) {
        solve("",n);
        return ans;
    }
};
