#include <bits/stdc++.h> 
using namespace std;
/***********************MAX PRODUCT SUBARRAY****************************************/
//TC: O(N)+O(N)
int maximumProduct(vector<int> &nums, int n)
{
     int maxLeft = nums[0];
    int maxRight = nums[0];
    
    int prod = 1;
    
    bool zeroPresent =  false;
    
    for(auto i:nums) {
        prod *= i;
        if(i == 0) {
            zeroPresent = true;
            prod = 1;
            continue;
        }
        maxLeft = max(maxLeft,prod);
    }
    
    prod = 1;
    
    for(int j=nums.size()-1;j>=0;j--) {
        prod *= nums[j];
        if(nums[j] == 0) {
            zeroPresent = true;
            prod = 1;
            continue;
        }
        maxRight = max(maxRight,prod);
    }
    
    if(zeroPresent) return max(max(maxLeft,maxRight),0);
    return max(maxLeft,maxRight);
}
/********************LONGEST INCREASING SUBSEQUENCE**********************************/
//SOLUTION 1: RECURSION
// TC: EXPONENTIAL
    int f(int ind,int prev_ind,vector<int>& nums,vector<vector<int>>&dp){
        if(ind==nums.size()){
            return 0;
        }
        int len =0+f(ind+1,prev_ind,nums,dp);
        if(prev_ind==-1||nums[ind]>nums[prev_ind]){
            len = max(len, 1+f(ind+1,ind,nums,dp));
        }
        return dp[ind][prev_ind+1]=len;
    }
    int lengthOfLIS1(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return f(0,-1,nums,dp);
    }
// SOLUTION 2: MEMOIZATION
    int f_memo(int ind,int prev_ind,vector<int>& nums,vector<vector<int>>&dp){
        if(ind==nums.size()){
            return 0;
        }
        if(dp[ind][prev_ind+1]!=-1){
            return dp[ind][prev_ind+1];
        }
        int len =0+f_memo(ind+1,prev_ind,nums,dp);
        if(prev_ind==-1||nums[ind]>nums[prev_ind]){
            len = max(len, 1+f(ind+1,ind,nums,dp));
        }
        return dp[ind][prev_ind+1]=len;
    }
    int lengthOfLIS2(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return f_memo(0,-1,nums,dp);
    }
// SOLUTION 3: TABULATION
// TC: O(N*N)
//SC: O(N*N) + O(N)
 int lengthOfLIS3(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int ind=n-1;ind>=0;ind--){
            for(int prev_ind=ind-1;prev_ind>=-1;prev_ind--){
                int notTake = 0 + dp[ind+1][prev_ind +1];
                int take = 0;
            if(prev_ind == -1 || nums[ind] > nums[prev_ind]){
                 take = 1 + dp[ind+1][ind+1];
            }
            dp[ind][prev_ind+1] = max(notTake,take);
        }
    }
        return dp[0][0];
    }
/*******************************LONGEST COMMON SUBSEQUENCE**********************************************/
// SOLUTION 1: RECURSION
int f_LCS(int i1,int i2,string s,string t){
	if(i1<0||i2<0){
		return 0;
	}
	if(s[i1]==t[i2]){
		return 1+f_LCS(i1-1,i2-1,s,t);
	}
	else{
		return 0+max(f_LCS(i1-1,i2,s,t),f_LCS(i1,i2-1,s,t));
	}
}
int lcs_RECR(string s, string t)
{
	return f_LCS(s.length()-1,t.length()-1,s,t);
}
// SOLUTION 2: MEMOIZATION
// TC: O(N*M)
// SC: O(N*M)+O(N+M)
int f_MEMO(int i1,int i2,string s,string t,vector<vector<int>>&dp){
	if(i1<0||i2<0){
		return 0;
	}
	if(s[i1]==t[i2]){
		return dp[i1][i2]=1+f_MEMO(i1-1,i2-1,s,t,dp);
	}
	else{
		return dp[i1][i2]=0+max(f_MEMO(i1-1,i2,s,t,dp),f_MEMO(i1,i2-1,s,t,dp));
	}
}
int lcs_MEMO(string s, string t)
{   
	int n=s.length();
	int m=t.length();
	vector<vector<int>>dp(n,vector<int>(m,-1));
	return f_MEMO(n-1,m-1,s,t,dp);
}
// SOLUTION 3: TABULATION
// TC: O(N*M)
// SC: O(N*M)
int lcs_TAB(string s, string t)
{   
	int n=s.length();
	int m=t.length();
	vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

	for(int i=0;i<=n;i++){
		dp[i][0]=0;
	}
	for(int j=0;j<=m;j++){
		dp[0][j]=0;
	}
	for(int ind1=1;ind1<=n;ind1++){
        for(int ind2=1;ind2<=m;ind2++){
            if(s[ind1-1]==t[ind2-1])
                dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
            else
                dp[ind1][ind2] = 0 + max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
        }
    }
    
    return dp[n][m];
}
/**********************************0 1 KNAPSACK**********************************************************/
int helper(int i,int n, int maxWeight, vector<int> &values, vector<int> &weights,vector<vector<int>>&dp){
	 if(i>=n){
		 return 0;
	 }
	 if(dp[i][maxWeight]!=-1){
		 return dp[i][maxWeight];
	 }
	 int non_take= 0+ helper(i+1,n,maxWeight,values,weights,dp);
	 int take=0;
	 if(weights[i]<=maxWeight){
		 take=values[i]+helper(i+1,n,maxWeight-weights[i],values,weights,dp);
	 }
	 return dp[i][maxWeight]=max(take,non_take);
}
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	// max weight= W
	// weight=[6, 1, 5, 3]
	// values=[3, 6, 1 ,4]
	// find a sequence of given sum = W in weight array
	// compare it by its values
	vector<vector<int>>dp(n,vector<int>(w+1,-1));
	return helper(0,n,w,values,weights,dp);

}
/*****************************EDIT DISTANCE *****************************************************/
  int minDistance(string str1, string str2) {
        int n = str1.size();
    int m = str2.size();
    
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    
    for(int i=0;i<=n;i++){
        dp[i][0] = i;
    }
    for(int j=0;j<=m;j++){
        dp[0][j] = j;
    }
    
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(str1[i-1]==str2[j-1])
                dp[i][j] = 0+dp[i-1][j-1];
            
            else dp[i][j] = 1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
        }
    }
    
    return dp[n][m];
    }
/*****************************MAXIMUM SUM INCREASING SUBSEQUENCE**********************************************/
int f(int i,int prev,vector<int> &rack, int n,vector<vector<int>>&dp){
	if(i>=n){
		return 0;
	}
	if(dp[i][prev+1]!=-1){
		return dp[i][prev+1];
	}
	int non_take= 0+ f(i+1,prev,rack,n,dp);
	int take=0;
	if(rack[i]>rack[prev]||prev==-1){
		take= rack[i]+ f(i+1,i,rack,n,dp);
	}
	return dp[i][prev+1]=max(take,non_take);
}
int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{   
	vector<vector<int>>dp(n,vector<int>(n+1,-1));
	return f(0,-1,rack,n,dp);
}
/********************************MATRIX CHAIN MULTIPLICATION**********************************/
//SOLUTION 1: MEMOIZATION
// TC: O(N*N*N)
// SC: O(N*N)+ O(N)
int f(int i,int j,vector<int> &arr,vector<vector<int>>&dp){
    if(i==j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int steps;
    int mini=1e9;
    for(int k=i;k<j;k++){
        steps=arr[i-1]*arr[k]*arr[j]+f(i,k,arr,dp)+f(k+1,j,arr,dp);
        mini=min(mini,steps);
    }
    return dp[i][j]=mini;
}
int matrixMultiplication(vector<int> &arr, int N)
{
    vector<vector<int>>dp(N,vector<int>(N,-1));
    return f(1,N-1,arr,dp);
}
