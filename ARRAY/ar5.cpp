#include <bits/stdc++.h> 
using namespace std;
/*****************************3 SUM*****************************************/
// TC: O(n^2)
vector<vector<int>> findTriplets(vector<int>num, int n, int K) {
       sort(num.begin(),num.end());
       vector<vector<int>>res;
        for (int i = 0; i < n-2; i++) {
            
            if (i == 0 || (i > 0 && num[i] != num[i-1])) {
                
                int lo = i+1, hi = n-1, sum = K - num[i];
                
                while (lo < hi) {
                    if (num[lo] + num[hi] == sum) {
                        
                        vector<int> temp; 
                        temp.push_back(num[i]); 
                        temp.push_back(num[lo]); 
                        temp.push_back(num[hi]); 
                        res.push_back(temp);
                        
                        while (lo < hi && num[lo] == num[lo+1]) lo++;
                        while (lo < hi && num[hi] == num[hi-1]) hi--;
                        
                        lo++; hi--;
                    } 
                    else if (num[lo] + num[hi] < sum) lo++;
                    else hi--;
               }
            }
        }
        return res;
}
/**************************************TRAPPING RAINWATER*****************************************************/
// BRUTE FORCE: 
//TC: O(n^2)
long getTrappedWater(long *height, int n){
     long ans=0;
        for(int i=0;i<n;i++){
            long leftMax=0;
            long rightMax=0;
            int j=i;
            while(j>=0){
                leftMax=max(leftMax,height[j]);
                j--;
            }
            j=i;
            while(j<n){
                rightMax=max(rightMax,height[j]);
                j++;
            }
            ans+= (min(leftMax,rightMax)-height[i]);
        } 
        return ans;
}
// BETTER APPROACH: 
// TC: O(n)
long getTrappedWater(long *height, int n){
        long ans=0;
        long prefix[n];
        long suffix[n];
        prefix[0]=height[0];
        for(int i=1;i<n;i++){
            prefix[i]= max(prefix[i-1],height[i]);
        }
        suffix[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
          suffix[i] = max(suffix[i + 1], height[i]);
        }

        long waterTrapped = 0;
        for (int i = 0; i < n; i++) {
            waterTrapped += min(prefix[i], suffix[i]) - height[i];
        }
        return waterTrapped;
}
/********************************REMOVE DUPLICATES FROM SORTED ARRAY*******************************************/
// TC: O(N logN )
// SC: O(N)
int removeDuplicates(vector<int> &arr, int n) {
	set<int>s;
	for(int i=0;i<n;i++){
		s.insert(arr[i]);
	}
	return s.size();
}
// TC: O(N)
// SC: O(1)
int removeDuplicates(vector<int> &arr, int n) {
	int cnt=1;
	for(int i=1;i<arr.size();i++){
		if(arr[i]==arr[i-1]){
			continue;
		}
		else{
			cnt++;
		}
	}
	return cnt;
}
/****************************MAX CONSECUTIVE ONE***************************************/
// TC: O(n)
// Where n is size of array
int findMaxConsecutiveOnes(vector<int>& nums) {
            int cnt=0;
            int max_cnt=0;
           for(int i=0;i<nums.size();i++){
               if(nums[i]==1){
                  cnt++;
               }
               else if(nums[i]==0){
                   max_cnt=max(max_cnt,cnt);
                   cnt=0;
               }
           }
           max_cnt=max(max_cnt,cnt);
           return max_cnt;
    }