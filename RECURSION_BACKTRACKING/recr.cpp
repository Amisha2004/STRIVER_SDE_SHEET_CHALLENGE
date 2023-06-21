#include <bits/stdc++.h> 
using namespace std;
/**********************SUBSET SUM****************************************/
// TC: Exponential
void f(int i, vector<int> &num, vector<int>&ans,int n,int sum){
    if(i>=n){
       ans.push_back(sum);
       return;
    }
     // take the element
     f(i+1,num,ans,n,sum+num[i]);
     //  don't take the element
     f(i+1,num,ans,n,sum);
}
vector<int> subsetSum(vector<int> &num)
{
   vector<int>ans;
   int n=num.size();
   f(0,num,ans,n,0);
   sort(ans.begin(),ans.end());
   return ans;
}
/************************SUBSET SUM II ***************************************/
// TC: Exponential
void helper(int i,int n, vector<int> &arr , set<vector<int>>&s,vector<int>v){
     if(i>=n){
        sort(v.begin(),v.end());
        s.insert(v);
       return;
    } 
     // not take the element
     helper(i+1,n,arr,s,v);
     // take the element
     v.push_back(arr[i]);
     helper(i+1,n,arr,s,v);
}
vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    set<vector<int>>s;
    vector<vector<int>>ans;
    vector<int>v;
    helper(0,n,arr,s,v);
    for(auto it: s){
        ans.push_back(it);
    }
    return ans;
}
/****************************RETURN SUBSET SUM TO K**************************************/
// TC: Exponential
void helper(int i,int n, int k,vector<int> arr , vector<vector<int>>&ans,vector<int>v){
     if(i==n){
         if(k==0){
             ans.push_back(v);
         }
         return;
     }
        // take the element
         v.push_back(arr[i]);
         helper(i+1,n,k-arr[i],arr,ans,v);
         v.pop_back();
        // not take the element
         helper(i+1,n,k,arr,ans,v);
}
vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{   
    vector<vector<int>>ans;
    vector<int>v;
    helper(0,n,k,arr,ans,v);
    sort(ans.begin(),ans.end());
    return ans;
}
/*******************************COMBINATION SUM II***************************************************/
// TC: Exponential
 void findCombination(int ind, int target, vector < int > & arr, vector < vector < int >> & ans, vector < int > & ds) {
  if (target == 0) {
    ans.push_back(ds);
    return;
  }
  for (int i = ind; i < arr.size(); i++) {
    if (i > ind && arr[i] == arr[i - 1]) continue;
    if (arr[i] > target) break;
    ds.push_back(arr[i]);
    findCombination(i + 1, target - arr[i], arr, ans, ds);
    ds.pop_back();
  }
}
vector<vector<int>> combinationSum2(vector<int> &candidates, int n, int target)
{
	sort(candidates.begin(), candidates.end());
  vector < vector < int >> ans;
  vector < int > ds;
  findCombination(0, target, candidates, ans, ds);
  return ans;

}
/*******************************PALINDROME PARTIONING******************************************************/
//TC: Exponential
bool isPalindrome(int i, int j, string &s) {
    while (i < j) {
        if (s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}
void f(int i, int j,string &s, vector<vector<string>>&ans,vector<string>v){
       if(j==s.length()&& isPalindrome(i,j,s)!=true){
           return;
       }
       if(i>=s.length()||j>=s.length()){
           ans.push_back(v);
           v.clear();
           return;
       }
       if(isPalindrome(i,j,s)==true){
           f(i,j+1,s,ans,v);
           string temp="";
           for(int k=i;k<=j;k++){
               temp+=s[k];
           }
           v.push_back(temp);
           f(j+1,j+1,s,ans,v);
           v.pop_back();
       }
       else{
           f(i,j+1,s,ans,v);
       }
}
vector<vector<string>> partition(string &s) 
{
    vector<vector<string>>ans;
    vector<string>v;
    f(0,0,s,ans,v);
    return ans;
}
/****************************Kth PERMUTATION SEQUENCE***************************************************/
// TC: Exponential
// SOLUTION 1: RECURSION
void permutations(string &s,int l,int r, vector<string>&ans){
    if (l == r){
        ans.push_back(s);
    }
    else {
        for (int i = l; i <= r; i++) {
            swap(s[l], s[i]);

            permutations(s, l + 1, r,ans);
 
            swap(s[l], s[i]);
        }
    }
}
string kthPermutation(int n, int k) {
    vector<string>ans;
    string s="";
    for (int i = 1; i <= n; i++) {
      s.push_back(i + '0');
    }
    permutations(s,0,n-1,ans);
    sort(ans.begin(),ans.end());
    return ans[k-1];
}
//SOLUTION 2: 
//TC: O(n^2)
string kthPermutation(int n, int k) {
   int fact=1;
        vector<int>temp;
        for(int i=1;i<n;i++){
            temp.push_back(i);
            fact=fact*i;
        }
        temp.push_back(n);
        string ans="";
        k=k-1;
        while(true){
            ans= ans+ to_string(temp[k/fact]);
            temp.erase(temp.begin()+ k/fact);
            if(temp.size()==0){
                break;
            }
            k=k%fact;
            fact=fact/temp.size();
        }
        return ans;
}
/***************************PRINT PERMUTATIONS STRING********************************************/
//TC: Exponential
void permutations(string &s,int l,int r, vector<string>&ans){
    if (l == r){
        ans.push_back(s);
    }
    else {
        for (int i = l; i <= r; i++) {
            swap(s[l], s[i]);

            permutations(s, l + 1, r,ans);
 
            swap(s[l], s[i]);
        }
    }
}
vector<string> findPermutations(string &s) {
    int n = s.size();
    vector<string>ans;
    permutations(s, 0, n - 1,ans);
    return ans;
}