#include<bits/stdc++.h>
using namespace std;
/***************************SEARCH IN SORTED 2D MATRIX*******************************/
// BRUTE FORCE : The idea is siply traverse the matrix and if element found return true
// TC: O(n^2)
// SC: O(1)
bool searchMatrix1(vector<vector<int>>& mat, int target) {
       for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==target){
                    return true;
                }
            }
        }
        return false;  
}
// BETTER SOLUTION -> BINARY SEARCH APPROACH
// TC: O(m * n + log(m * n))
bool searchMatrix2(vector<vector<int>>& matrix, int target) {
        vector<int>v;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                v.push_back(matrix[i][j]);
            }
        }
        int lo = 0;
        if(!matrix.size()) return false;
        int hi = v.size()- 1;
        
        while(lo <= hi) {
            int mid = (lo + (hi - lo) / 2);
            if(v[mid] == target) {
                return true;
            }
            if(v[mid] < target) {
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }
        return false;
    }
// OPTIMAL SOLUTION: without using extra space
bool searchMatrix3(vector<vector<int>>& mat, int target) {
    int m=mat.size();
    int n=mat[0].size();
    int low=0;
    int high=n*m-1;
    int mid=(low+high)/2;
    while(low<=high){
        int row=mid/n;
        int col=mid%n;
        if(mat[row][col]==target){
            return true;
        } 
        else  if(mat[row][col]>target){
             high=mid-1;
        }
        else{
             low=mid+1;
        }
       mid=(low+high)/2;
   }
   return false;
}
/**************************************************************************/
/****************BINARY EXPONENTIATION****************************************************/
//1.recursive menthod
int binpow(int a,int b){
    if(b==0){
        return 1;
    }
    int res=binpow(a,b/2);
    if(b%2!=0){
        return res*res*a;
    }
    else{
        return res*res;
    }
}
//2.Iterative method
//if a<=10^9 , b<=10^9 , MOD<=10^9
const int MOD= 1e9+7;
int powIterative(int x,int y,int MOD){
    int res = 1;
    if (x == 0) return 0; // In case x is divisible by p;
    while (y > 0)
    {
        if (y & 1){
            res = (res* 1LL * x)%MOD;
        }
        x = (x*1LL*x)%MOD;
        y = y>>1;
    }
    return res;
}
//if a<=10^18 , MOD<=10^18
int binMultiply(long long x, long long y){
    int res = 0;
    if (x == 0) return 0; // In case x is divisible by p;
    while (y > 0)
    {
        if (y & 1){
            res = (res+x)%MOD;
        }
        x = (x+x)%MOD;
        y = y>>1;
    }
    return res;
}
int pow(int x,int y){
    int res = 1;
    if (x == 0) return 0; // In case x is divisible by p;
    while (y > 0)
    {
        if (y & 1){
            res = (res* 1LL * x)%MOD;
        }
        x = binMultiply(x,x);
        y = y>>1;
    }
    return res;
}
/********************MODULAR EXPONENTITATION*************************************/
int modularExponentiation(int x, int y, int m) {
	int res = 1;
    if (x == 0) return 0; // In case x is divisible by p;
    while (y > 0)
    {
        if (y & 1){
            res = (res* 1LL * x)%m;
        }
        x = (x*1LL*x)%m;
        y = y>>1;
    }
    return res;
}
/*****************************Majority element (>N/2 times)*******************************/
// BRUTE FORCE APPROACH
// TC: O(n^2)
int findMajorityElement(vector<int>v, int n) {
	 for(int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (v[j] == v[i]) {
                cnt++;
            }
        }
         if (cnt > (n / 2))
            return v[i];
    
    return -1;
    }
}
// BETTER APPROACH : using map
// TC: O(n)
// SC: O(n)
int findMajorityElement(int arr[], int n) {
	unordered_map<int, int> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        for(auto it:mp){
            if(it.second>n/2){
                return it.first;
            }
        }
        return -1;
}
// OPTIMAL APPROACH=>Moore’s Voting Algorithm
//TC: O(N)
// SC: O(1)
int findMajorityElement(vector<int>arr, int n) {
	int cnt = 0;
    int element;
    for (int i = 0; i < n; i++) {
        if (cnt == 0) {
            cnt = 1;
            element = arr[i];
        }
        else if (element == arr[i]){
            cnt++;
        } 
        else {
            cnt--;
        }
    }
    int cnt_check = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == element) {
            cnt_check++;
        }
    }

    if (cnt_check > (n / 2)) {
        return element;
    }
    return -1;
}
/*******************************Majority element (>N/3 times)*********************************************/
// solution 1: brute fotrce
// solution2: using map
// O(n)
vector<int> majorityElementII(vector<int> &arr)
{
    // Write your code here.
        int x= floor(arr.size()/3);
         vector<int>v;
         unordered_map<int,int>mp;
         for(int i=0;i<arr.size();i++){
             mp[arr[i]]++;
         }
         for(auto it:mp){
             if(it.second>x){
                v.push_back(it.first);
             }
         }
         return v;
}
/***********************************GRID UNIQUE PATH********************************************************/
//SOLUTION 1: using recursion
// TC: exponential
int helper(int i,int j,int m,int n){
	if(i==0&&j==0){
		return 1;
	}
	if(i>m||j>n){
		return 0;
	}
	int l=0,r=0;
	if(i-1>=0){
		l +=helper(i-1,j,m,n);
	}
	if(j-1>=0){
		r +=helper(i,j-1,m,n);
	}
	return l+r;
}                                                                                                                                                                                                                                         
int uniquePaths(int m, int n) {
	 return helper(m-1,n-1,m,n);
}
// SOLUTION : using dp
// TC: O(m*n)
// SC: O(m*n)
int uniquePaths(int m, int n) {
	vector<vector<int>>dp(m,vector<int>(n,0));
    dp[0][0]=1;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			
	        if(i-1>=0){
		       dp[i][j]  +=dp[i-1][j];
         	}
        	if(j-1>=0){
		        dp[i][j] +=dp[i][j-1];
	        }
		}
	}
	 return dp[m-1][n-1];
}
/***********************************REVERSE PAIRS**********************************************/
// BRUTE FORCE APPROACH
// TC: O(n^2)
int reversePairs(vector<int> &nums, int n){
	  int cnt=0;
         for(int i=0;i<nums.size();i++){
             for(int j=i+1;j<nums.size();j++){
                 if(nums[i]>2*nums[j]){
                     cnt++;
                 }
             }
         }
         return cnt;	
}
// BETTER APPROACH USING MERGE SORT
// TC: O(2N*logN)
void Merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; 
    int left = low;    
    int right = mid + 1;  
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}
int countReversePairs(vector<int> &nums, int low, int mid, int high){
        int right = mid + 1;
        int cnt = 0;
        for(int i = low;i<=mid;i++){
           while(right <= high &&  (long)nums[i] > (long)2*nums[right]) right++;
           cnt += (right - (mid + 1));
        }
        return cnt;
}
int MergeSort(vector<int> &nums,int low,int high){
     int cnt = 0;
      if(low<high){
          int mid= low+(high-low)/2;
          cnt+=MergeSort(nums, low,mid);
          cnt+=MergeSort(nums, mid+1, high);
          cnt += countReversePairs(nums, low, mid, high);
          Merge(nums,low,mid,high);
      }
       return cnt;
}
    int reversePairs(vector<int>& nums) {
         int cnt =  MergeSort(nums,0, nums.size()-1);
      return cnt;
    }
/*******************************************************************/