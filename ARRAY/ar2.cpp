#include<bits/stdc++.h>
using namespace std;
/*****************************ROTATE MATRIX*****************************************/
// CODING NINJAS PROBLEM: Given a 2D matrix of size n*m and rotate the element of matrix in clockwise direction
// TC: O(n * m)
void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    int lt = 0, rt = m - 1, tp = 0, bm = n - 1;

    while (lt< rt && tp < bm) {
        int temp = mat[tp][lt];

        // Shift elements in the top row to the left
        for (int col = lt + 1; col <= rt; col++) {
            int k = mat[tp][col];
            mat[tp][col] = temp;
            temp = k;
        }
        tp++;

        // Shift elements in the rightmost column upward
        for (int row = tp; row <= bm; row++) {
            int k = mat[row][rt];
            mat[row][rt] = temp;
            temp = k;
        }
        rt--;

        // Shift elements in the bottom row to the right
        for (int col = rt; col >= lt; col--) {
            int k = mat[bm][col];
            mat[bm][col] = temp;
            temp = k;
        }
        bm--;

        // Shift elements in the leftmost column downward
        for (int row = bm; row >= tp; row--) {
            int k = mat[row][lt];
            mat[row][lt] = temp;
            temp = k;
        }
        lt++;

        // Place the last remaining element in the matrix
        mat[tp - 1][lt - 1] = temp;
    }
}
// LEETCODE PROBLEM: rotate the image by 90 degrees (clockwise).
// TC: O(n*m)
 void rotate(vector<vector<int>>& matrix) {
       int n=matrix.size();
       for(int i=0;i<n;i++){
           for(int j=i+1;j<n;j++){
               swap(matrix[i][j],matrix[j][i]);
           }
       }
       for(int i=0;i<n;i++){
           reverse(matrix[i].begin(),matrix[i].end());
       }
    }

/**************************MERGE OVERLAPPING SUBINTERVALS*********************************************/
// TC:  O(n log n)
vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    sort(intervals.begin(),intervals.end());
    int n=intervals.size();
    vector<vector<int>>ans;
    ans.push_back(intervals[0]);
    for(int i=1;i<n;i++){
        if(ans[ans.size()-1][1]<intervals[i][0]){
             ans.push_back(intervals[i]);
        }
        else {
           ans[ans.size()-1][1]= max(ans[ans.size()-1][1],intervals[i][1]);
        }
    }
    return ans;
}
/*****************************MERGE TWO SORTED ARRAYS****************************************************/
// SOLUTION 1: using extra space 
// TC: O(m)+ O(n)+ o(m+n * log(m+n)) + O(m+n) = O((m + n) log (m + n))
// SC: O(1)

vector<int> MergeSortedArrays(vector<int>& nums1, vector<int>& nums2, int m, int n) {
	       vector<int>v;
            for(int i=0;i<m;i++){
              v.push_back(nums1[i]);
          }
           for(int i=0;i<n;i++){
              v.push_back(nums2[i]);
          }
          sort(v.begin(),v.end());
          nums1.clear();
          for(int i=0;i<m+n;i++){
              nums1.push_back(v[i]);
          }
		  return nums1;
}

/******************************FIND DUPLICATES IN AN ARRAY********************************/
// TC: O(n)
int findDuplicate(vector<int> &nums, int n){
	 map<int,int>mp;
         for(int i=0;i<n;i++){
             mp[nums[i]]++;
         }
         int ans;
         for(auto i:mp){
             if(i.second>1){
                ans=i.first;
             }
         }
         return ans;
}
/***********************MISSING AND REPEATING NUMBERS**********************************/
// SOLUTION 1: 
// TC: O(n*(logn))
pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	sort(arr.begin(),arr.end());
	int R,M=-1;
	for(int i=0;i<n-1;i++){
        if(arr[i]==arr[i+1]){
			R=arr[i];
		}
		if(arr[i+1]-arr[i]>1){
			M=arr[i]+1;
		}
	}
	if(M==-1){
		if(arr[0]>1){
			M=1;
		}
		else {
			M=n;
		}
	}
	pair<int,int>p=make_pair(M,R);
	return p;
	
}
// SOLUTION 2
// TC: O(n)
pair<int, int> missingAndRepeating(vector<int> &arr, int n) {
    unordered_set<int> st;
    int missing = 0;
    int repeated = 0;
    for (auto &it : arr) {

        if (st.count(it)) {
            repeated = it;
        } 
        else {
            st.insert(it);
        }
    }
    for (int num = 1; num <= n; num++) {
        if (st.count(num) == 0) {
            missing = num;
            break;
        }
    }
      return { missing, repeated };

}
/**********************************COUNT INVERSIONS*****************************************/
long long getInversions(long long *arr, int n) {
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++)
         if(arr[i]>arr[j]){
             cnt++;
         }
    }
    return cnt;
}
/******************************************************************************************/