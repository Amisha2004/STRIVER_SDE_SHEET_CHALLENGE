#include <bits/stdc++.h> 
using namespace std;
/************************MINIMUMPATH SUM********************************************/
//SOLUTION 1: RECURSION
int helper(int i,int j, vector<vector<int>> &grid){
    if(i==0&&j==0){
        return grid[0][0];
    }
    if(i<0||j<0){
        return 1e9;
    }
    int l= grid[i][j]+ helper(i,j-1,grid);
    int r= grid[i][j]+ helper(i-1,j,grid);
    return min(l,r);
}
int minSumPath1(vector<vector<int>> &grid) {
    int n=grid.size();
    int m=grid[0].size();
     return helper(n-1,m-1,grid);
}
// SOLUTION 2: TABULATION
int minSumPath2(vector<vector<int>> &grid) {
     int n=grid.size();
     int m=grid[0].size();
     vector<vector<int>> dp(n,vector<int>(m,0));
     for(int i=0;i<n;i++){
         for(int j=0;j<m;j++){
            
             if(i==0&&j==0){
                 dp[i][j]=grid[i][j];
             }
            else{
               int l=grid[i][j];
               if(i>0){
                   l+=dp[i-1][j];
               }
               else{
                   l+=1e9;
               }
               int r=grid[i][j];
               if(j>0){
                   r+=dp[i][j-1];
               }
               else{
                   r+=1e9;
               }
               dp[i][j]=min(l,r);
            }
        } 
     }
     return dp[n-1][m-1];
}
/***********************************COIN CHANGE***********************************************/
long countWaysToMakeChange(int *denominations, int n, int value)
{   
    // vector<vector<int>>dp(n,vector<int>(value+1,0));
    vector<long> prev(value+1,0);
    for(int j=0;j<=value;j++){
        if(j%denominations[0]==0){
            prev[j]= 1;
        }
    }    
    for(int i= 1;i<n;i++){
        vector<long> curr(value+1,0);
        for(int j=0;j<=value;j++){
            long pick=0;
            long non_pick;
            if (denominations[i] <= j) {
                 pick = curr[j-denominations[i]];
            }
             non_pick= prev[j];
            curr[j]=pick+non_pick;
        }
        prev=curr;
    }

    return prev[value];
}
/*****************************SUBSET SUM EQUAL TO K************************************************************/
// SOLUTION 1: RECURSION
bool helper_Subset(int n,int ind,int k, vector<int> &arr){
      if(k==0){
          return true;
      }
      if(ind==0){
          return (arr[0]==k);
      }
      bool non_pick=helper_Subset(n,ind-1,k,arr);
      bool pick=false;
      if(k>=arr[ind]){
          pick=helper_Subset(n,ind-1,k-arr[ind],arr);
      }
      return pick||non_pick;
}
bool subsetSumToK1(int n, int k, vector<int> &arr) {
     return  helper_Subset(n,n-1,k,arr);
}
// SOLUTION 2: MEMOIZATION
bool helper(int n,int ind,int k, vector<int> &arr,vector<vector<int>> &dp){
      if(k==0){
          return true;
      }
      if(ind==0){
          return (arr[0]==k);
      }
      if (dp[ind][k] != -1) {
        return dp[ind][k];
      }
      bool non_pick=helper(n,ind-1,k,arr,dp);
      bool pick=false;
      if(k>=arr[ind]){
          pick=helper(n,ind-1,k-arr[ind],arr,dp);
      }
      return dp[ind][k]=pick||non_pick;
}
bool subsetSumToK2(int n, int k, vector<int> &arr) {
     vector<vector<int>> dp(n,vector<int>(k+1,-1));
     return  helper(n,n-1,k,arr,dp);
}
//TABULATION
bool subsetSumToK3(int n, int k, vector<int> &arr) {
     vector<vector<bool>> dp(n,vector<bool>(k+1,false));
     for(int i=0;i<n;i++){
          dp[i][0]=true;
     }
     if (arr[0] <= k) {
       dp[0][arr[0]] = true;
     }
     for(int i=1;i<n;i++){
         for(int j=1;j<=k;j++){
            bool notTaken = dp[i-1][j];
    
            bool taken = false;
                if(arr[i]<=j)
                    taken = dp[i-1][j-arr[i]];
        
            dp[i][j]= notTaken||taken;
         }
     }
     return dp[n-1][k];
}
/***************************ROD CUTTING PROBLEM****************************************************/
// SOLUTION 1: RECURSION
int f_RECR(int i, int j, vector<int> &cuts,vector<vector<int>>&dp){
    // base case
    if(i>j)
        return 0;
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int mini = 1e9;  
    for(int ind=i; ind<=j; ind++){     
        int ans = cuts[j+1] - cuts[i-1] +
                    f_RECR(i,ind-1,cuts,dp) +
                    f_RECR(ind+1,j,cuts,dp);
        
        mini = min(mini, ans);
        
    }   
    return mini;
}
    int minCost1(int n, vector<int>& cuts) {
         int c= cuts.size();
         cuts.push_back(n);
         cuts.insert(cuts.begin(),0);
         sort(cuts.begin(),cuts.end());
         vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
         return f_RECR(1,c,cuts,dp);
    }
// MEMOIZATION
     int f_memo(int i, int j, vector<int> &cuts,vector<vector<int>>&dp){
    
    // base case
    if(i>j)
        return 0;
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int mini = 1e9;
    
    for(int ind=i; ind<=j; ind++){
        
        int ans = cuts[j+1] - cuts[i-1] +
                    f_memo(i,ind-1,cuts,dp) +
                    f_memo(ind+1,j,cuts,dp);
        
        mini = min(mini, ans);
        
    }
    
    return dp[i][j]=mini;
}
    int minCost2(int n, vector<int>& cuts) {
         int c= cuts.size();
         cuts.push_back(n);
         cuts.insert(cuts.begin(),0);
         sort(cuts.begin(),cuts.end());
         vector<vector<int>>dp(c+1,vector<int>(c+1,-1));
         return f_memo(1,c,cuts,dp);
    }
// TABULATION
int minCost3(int n, vector<int>& cuts) {
         int c= cuts.size();
         cuts.push_back(n);
         cuts.insert(cuts.begin(),0);
         sort(cuts.begin(),cuts.end());
         vector<vector<int>>dp(c+2,vector<int>(c+2,0));
        for(int i=c;i>=1;i--){
            for(int j=1;j<=c;j++){
                if(i>j){
                    continue;
                }
                 int mini = 1e9;
                  for(int ind=i; ind<=j; ind++){
        int ans = cuts[j+1] - cuts[i-1] +
                   dp[i][ind-1] +
                    dp[ind+1][j];
        
        mini = min(mini, ans);
        
    }
        dp[i][j]=mini;
            }
        }
         return dp[1][c];
    }
/******************************CUT LOGS**************************************/
int helper_logs(int e,int f,vector<vector<int>>&dp) {
    if(f<=1 || e==1) {
        return dp[e][f]=f;
    }
    if(dp[e][f]!=-1) {
        return dp[e][f];
    }
    int ans=1e6,start=1,end=f;
    while(start<=end) {
        int mid=start+(end-start)/2;
        if(dp[e-1][mid-1]==-1) {
            dp[e-1][mid-1]=helper_logs(e-1,mid-1,dp);
        }
        int BREAK=dp[e-1][mid-1];
        if(dp[e][f-mid]==-1) {
            dp[e][f-mid]=helper_logs(e,f-mid,dp);
        }
        int SURVIVE=dp[e][f-mid];
        ans=min(ans,1+max(BREAK,SURVIVE));
        if(BREAK<SURVIVE) {
            start=mid+1;
        }
        else {
            end=mid-1;
        }
    }
    return dp[e][f]=ans;
}

int cutLogs(int k, int n) {
    vector<vector<int>>dp(k+1,vector<int>(n+1,-1));
    return helper_logs(k,n,dp);
}
/*******************************WORD BREAK**************************************************/
bool solve(int ind,string str,set<string> st,vector<int>&dp){
        if(ind==str.size()) return true;
        if(dp[ind]!=-1){
            return dp[ind];
        }
        string temp="";
        for(int i=ind;i<str.size();i++){
            temp+=str[i];
            if(st.find(temp)!=st.end()){
                if(solve(i+1,str,st,dp)){
                    return dp[ind]=true;
                }
            }
        }
        return dp[ind]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        for(auto x:wordDict) st.insert(x);
        vector<int>dp(s.length(),-1);
        return solve(0,s,st,dp);
    }
/********************************PALINDROME PARTIONING***********************************************/
// RECURSION
bool isPalindrome(int i, int j, string &s) {
    while (i < j) {
        if (s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}
int f_Palindrome(int i,int n,string str){
      if(i==n){
          return 0;
      }

      int mini=1e9;
      for(int j=i;j<n;j++){
          if(isPalindrome(i, j, str)==true){
            int cost= 1+f_Palindrome(j+1,n,str);
            mini=min(mini,cost);
          }
      }
      return mini;
}
int palindromePartitioning1(string str) {
    return f_Palindrome(0,str.length(),str)-1;
}
//MEMOIZATION
bool isPalindrome(int i, int j, string &s) {
    while (i < j) {
        if (s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}
int f_memo_palindrome(int i,int n,string str,vector<int>&dp){
      if(i==n){
          return 0;
      }
       if(dp[i]!=-1){
           return dp[i];
       }
      int mini=1e9;
      for(int j=i;j<n;j++){
          if(isPalindrome(i, j, str)==true){
            int cost= 1+f_memo_palindrome(j+1,n,str,dp);
            mini=min(mini,cost);
          }
      }
      return dp[i]=mini;
}
int palindromePartitioning2(string str) {
    int n=str.length();
    vector<int>dp(n,-1);
    return f_memo_palindrome(0,str.length(),str,dp)-1;
}
/********************************JOB SEQUENCING PROBLEM*****************************************************/
// MEMOIZATION
int f_job(int i,int tm,vector<vector<int>> &jobs,vector<vector<int>>&dp){
     if(i>=jobs.size()){
         return 0;
     }
     if(dp[i][tm]!=-1){
         return dp[i][tm];
     }
     int not_pick= 0+ f_job(i+1,tm,jobs,dp);
     int pick=0;
     if(jobs[i][0]>tm){
         pick= jobs[i][1]+ f_job(i+1,tm+1,jobs,dp);
     }
     return dp[i][tm]=max(pick,not_pick);
}
int jobScheduling1(vector<vector<int>> &jobs)
{   
    sort(jobs.begin(),jobs.end());
    int n=jobs.size();
    int sz=jobs[n-1][0];
    vector<vector<int>>dp(n,vector<int>(sz+1,-1));
    return f_job(0,0,jobs,dp);
}
// GREEDY APPROACH
bool comp(vector <int> a,vector<int> b)
{
     return a[1]>b[1];
}
int jobScheduling2(vector<vector<int>> &jobs)
{   
    sort(jobs.begin(),jobs.end(),comp);
    int n=jobs.size();
    int tm=0;
    int maxdead=INT_MIN;
    for (int i = 0; i < n; i++) {
      maxdead = max(jobs[i][0], maxdead);
    }
    vector<int> ans(maxdead+1,-1); 
    int profit=0;    
      for (int i=0;i<n;i++)
     {
         int currdead=jobs[i][0];
         int currprofit=jobs[i][1];
         for (int k=currdead;k>0;k--)
         {
             if(ans[k]==-1)
             {
                 profit+=currprofit;
                 ans[k]=1;
                 break;
             }
         }
     }
    return profit;
}

