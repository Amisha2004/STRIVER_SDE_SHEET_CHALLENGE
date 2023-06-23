#include <bits/stdc++.h> 
using namespace std;
void helper(int i,vector<int>&v,vector<int>ans,vector<vector<int>>&res){
    if(i==v.size()){
       res.push_back(ans);
       return;
    }
    ans.push_back(v[i]);
    helper(i+1,v,ans,res);
    ans.pop_back();
    helper(i+1,v,ans,res);
}
vector<vector<int>> pwset(vector<int>v){
    vector<vector<int>>res;
    vector<int>ans;
    helper(0,v,ans,res);
    return res;
}
/********************************************************************/
vector<vector<int>> AllPossibleStrings(vector<int>v) {
	int n = v.size();
	vector<vector<int>>ans;
	for (int num= 0; num < (1 << n); num++) {
		vector<int>temp;
		for (int i = 0; i < n; i++) {
			if (num & (1 << i)) {
				temp.push_back(v[i]);
			}
		}
		if (temp.size() > 0) {
			ans.push_back(temp);
		}
	}
	sort(ans.begin(), ans.end());
	return ans;
}