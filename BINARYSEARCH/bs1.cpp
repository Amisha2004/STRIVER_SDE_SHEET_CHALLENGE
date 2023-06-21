#include<bits/stdc++.h>
using namespace std;
/****************************FIND Nth ROOT OF M*********************************************/
// TC: O(log(m))
int NthRoot(int n, int m) {
   int low = 1;
  int high = m;

  while(low <= high)
  {
    int mid = low + (high-low)/2;

    if(pow(mid, n) == m)
      return mid;
    else if(pow(mid, n) > m)
      high = mid - 1;
    else
      low = mid + 1;
  }

  return -1;
}
/********************************MATRIX MEDIAN**************************************/
// TC:  O(n * m * log(n * m))
int getMedian(vector<vector<int>> &matrix)
{
      vector<int>v;
      for(int i=0;i<matrix.size();i++){
          for(int j=0;j<matrix[i].size();j++){
              v.push_back(matrix[i][j]);
          }
      }
      sort(v.begin(),v.end());
      int low=0;
      int high= (matrix.size()*matrix[0].size()) -1;
      int mid=  low+(high-low)/2;
      
      return v[mid];
}
/***************************SINGLE ELEMENT IN A SORTED ARRAY************************************************/
// TC: O(logn)
int singleNonDuplicate(vector<int>& nums)
{
	        int low = 0;
            int high = nums.size() - 2;       
            while (low <= high) {
                int mid = low +(high-low) / 2;               
                if (mid % 2 == 0) {
                    if (nums[mid] != nums[mid + 1]) {
                           high = mid - 1; 
                    }
                    else{
                           low = mid + 1;
                    }       
                }
                 else {
                    if (nums[mid] == nums[mid + 1]) {
                         high = mid - 1;
                    }
                    else{
                        low = mid + 1; 
                    }
                }
            }
            return nums[low];
}
/****************************SEARCH IN ROTATED SORTED ARRAY**************************************/
int search(int* nums, int n, int target) {
//    int size=nums.size();
       int low=0,high=n-1,mid=0;
        while(low<=high){
                mid=low+(high-low)/2;
                if(nums[mid]==target) return mid;
                if(nums[mid]>=nums[low]){
                     if(nums[mid]>=target && nums[low]<=target){
                          high=mid-1;
                     }
                     else {
                         low=mid+1;
                     }
                }
                else{
                    if(nums[mid]<=target && nums[high]>=target){
                         low=mid+1;
                    }
                    else{
                          high=mid-1;
                    } 
                }
        }
        return -1;
}
