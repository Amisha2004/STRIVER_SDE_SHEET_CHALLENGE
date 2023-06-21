
#include <bits/stdc++.h>
using namespace std;
/******************************PAIR SUM*************************************/
// BRUTE FORCE APPROACH: Generating all possible pair
// TC: O(n^2)+ O(sz logsz ) == O(n^2)
// sz: size of ans
vector<vector<int>> pairSum(vector<int> &arr, int s){
    vector<vector<int>>ans;
    for(int i=0; i<arr.size(); i++){
        for (int j=i+1; j<arr.size(); j++){
            if(arr[i]+arr[j]==s){
                vector<int> temp;
                temp.push_back(min(arr[i],arr[j]));
                temp.push_back(max(arr[i],arr[j]));
                ans.push_back(temp);
            }
        }
    }
    sort(ans.begin(),ans.end());
    return ans;
}
// BETTER :  using map
// TC: O(n)
vector<int> twoSum(vector<int>& nums, int target) {
         unordered_map<int,int>mp;
         for(int i=0;i<nums.size();i++){
             mp[nums[i]]=i;
         }

         for(int i=0;i<nums.size();i++){
             int x= nums[i];
             int y=target-x;
              if (mp.find(y) != mp.end() && mp[y]!=i) {
                    return {mp[y], i};
             }
         }
         return {-1,-1};
}
/******************************4 SUM***********************************************/
// BRUTE FORCE APPROACH: Using 3 loops
// TC: O(n^3)
string fourSum1(vector<int> arr, int target, int n) {
    sort(arr.begin(),arr.end());
   for(int i=0;i<n-3;i++){
      for(int j=i+1;j<n-2;j++){
          int left=j+1;
          int right=n-1;
          while(left<right){
              int sum=arr[i]+arr[j]+arr[left]+arr[right];
              if(sum==target){
                  return "Yes";
              }
              else if(sum<target){
                  left++;
              }
              else{
                  right--;
              }
          }
      }
  }
  return "No";
}
// BETTER SOLUTION
string fourSum(vector<int> nums, int target, int n) {

         sort(nums.begin(), nums.end());
        bool found=false;
         for(int i=0;i<n;i++){
             if(i>0&& nums[i]==nums[i-1]) continue;
             
             for(int j=i+1;j<n;j++){
                 if(j>i+1&&nums[j]==nums[j-1]) continue;
                 int k= j+1;
                 int l=n-1;
               while (k < l) {
                long long sum = nums[i];
                sum += nums[j];
                sum += nums[k];
                sum += nums[l];
                if (sum == target) {
                    found=true;
                    k++; l--;

                    while (k < l && nums[k] == nums[k - 1]) k++;
                    while (k < l && nums[l] == nums[l + 1]) l--;
                }
                else if (sum < target) k++;
                else l--;
             }
         }
         }
         if(found==true){
             return "Yes";
         }
         else{
             return "No";
         }
}
/***************************LONGEST CONSECUTIVE SEQUENCE *********************************************/
int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        for(int i=0;i<nums.size();i++){
           st.insert(nums[i]);
        }
         int lS = 0;
        for(int i=0;i<nums.size();i++){
            if(st.count(nums[i]-1)==0){
                  int cN = nums[i];
                  int cS = 1;
                while(st.count(cN+1)==1){
                    cN+=1;
                    cS+=1;
                }
                lS=max(lS,cS);
            }
        }
       return lS; 
}
/*****************************LONGEST SUBARRAY WITH ZERO SUM******************************************/
// BRUTE FORCE APPROACH
//TC: O(N^2)
int LongestSubsetWithZeroSum(vector < int > arr) {
    int maxi=0;
    for(int i=0;i<arr.size();i++){
        int sum=0;
        for(int j=i;j<arr.size();j++){
            sum+=arr[j];
            if(sum==0){
                maxi=max(maxi,j-i+1);
            }
        }
    }
    return maxi;
}
// BETTER APPROACH- using map
//TC: O(n)
int LongestSubsetWithZeroSum(vector < int > arr) {
    unordered_map<int,int> mp; 
    int maxi = 0;
    int sum = 0; 
    for(int i = 0;i<arr.size();i++) {
        sum += arr[i]; 
        if(sum == 0) {
            maxi = i + 1; 
        }
        else {
            if(mp.find(sum) != mp.end()) {
                maxi = max(maxi, i - mp[sum]); 
            }
            else {
                mp[sum] = i;
            }
        }   
    }

    return maxi;
}
/*******************COUNT SUBARRAYS WITH GIVEN XOR*************************************/
// BRUTE FORCE APPROACH: O(n^2)
int subarraysXor(vector<int> &arr, int x)
{  
    int n=arr.size();
    int cnt=0;
   for(int i=0;i<n;i++){
       int ans=0;
      for(int j=i;j<n;j++){
           ans= ans^arr[j];
           if(ans==x){
               cnt++;
           }
      }
   }
   return cnt;
}
/*******************LENGTH OF LONGEST SUBSTRING WITHOUT ANY REPEATING CHARACTER***********************************/
int uniqueSubstrings(string str)
{
     if(str.size()==0)
      return 0;
  int maxans = INT_MIN;
  unordered_set < int > set;
  int l = 0;
  for (int r = 0; r < str.length(); r++) 
  {
    if (set.find(str[r]) != set.end())
    {
      while (l < r && set.find(str[r]) != set.end()) {
        set.erase(str[l]);
        l++;
      }
    }
    set.insert(str[r]);
    maxans = max(maxans, r - l + 1);
  }
  return maxans;
}