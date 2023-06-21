#include<bits/stdc++.h>
using namespace std;
/************************MEDIAN OF TWO SORTED ARRAY****************************************/
// SOLUTION 1: using merge 
// TC: O(N+M)
void merge(vector<int>& nums1, vector<int>& nums2,vector<int>&ans){
         int i=0;
         int j=0;
         while(i<nums1.size()&&j<nums2.size()){
             if(nums1[i]<=nums2[j]){
                  ans.push_back(nums1[i]);
                  i++;
             }
             else{
                 ans.push_back(nums2[j]);
                 j++;
             }
         }
         while(i<nums1.size()){
             ans.push_back(nums1[i]);
                  i++; 
         }
         while(j<nums2.size()){
             ans.push_back(nums2[j]);
                  j++; 
         }
    }
double median1(vector<int>& nums1, vector<int>& nums2) {
	  vector<int>ans;
        merge(nums1,nums2,ans);
        int mid=  0+ (ans.size()-1)/2;
        float res;
        if(ans.size()%2==0){
            res= ((float)ans[mid]+(float)ans[mid+1])/2;
          
        }
        else{
            res= ans[mid];
        }
        return res;
}
// SOLUTION 2: using inbuilt function
//TC: O((n + m) log(n + m))
double median2(vector<int>& a, vector<int>& b) {
	 vector<int> m;
       
        m.insert(m.begin(), a.begin(), a.end());
        m.insert(m.end(), b.begin(), b.end());
        
        sort(m.begin(),m.end());
        
        return (m[m.size()/2]+m[(m.size()-1)/2])/2.00;
}
// SOLUTION 3: BINARY SEARCH
// TC: O(log(min(n1, n2)))
double median3(vector<int>& a, vector<int>& b) {
	if(a.size() > b.size()) median3(b, a);
    int n1 = a.size();
    int n2 = b.size();
    int l = 0, r = n1;
    while(l <= r){
        int m1 = l + (r - l) / 2;
        int m2 = (n1 + n2 + 1) / 2 - m1;
        int l1 = m1 == 0 ? INT_MIN : a[m1 - 1];
        int l2 = m2 == 0 ? INT_MIN : b[m2 - 1];
        int r1 = m1 == n1 ? INT_MAX : a[m1];
        int r2 = m2 == n2 ? INT_MAX : b[m2]; 
        if(l1 <= r2 and l2 <= r1){
            if((n1 + n2) % 2 == 0){
                return ((max(l1, l2)) + (min(r1, r2))) / 2.0;
            }else{
                return max(l1, l2);
            }
        }else if(l1 > r2){
            r = m1 - 1; 
        }else{
            l = m1 + 1;
        }
    }
}
/***********************************Kth ELEMENT OF TWO SORTED ARRAY******************************************/
// SOLUTION 1: using merge
void merge(vector<int>& nums1, vector<int>& nums2,vector<int>&ans){
         int i=0;
         int j=0;
         while(i<nums1.size()&&j<nums2.size()){
             if(nums1[i]<=nums2[j]){
                  ans.push_back(nums1[i]);
                  i++;
             }
             else{
                 ans.push_back(nums2[j]);
                 j++;
             }
         }
         while(i<nums1.size()){
             ans.push_back(nums1[i]);
                  i++; 
         }
         while(j<nums2.size()){
             ans.push_back(nums2[j]);
                  j++; 
         }
    }
    int Kthelement1(vector<int> &row1, vector<int> &row2, int m, int n,
                       int k){
           vector<int>ans;
           merge(row1,row2,ans);
           return ans[k-1];
 }
 // SOLUTION 2: USING BINARY SEARCH
 // TC: O(log(min(n, m)))
 int Kthelement2(vector<int> &row1, vector<int> &row2, int n, int m, int k) {
  if (n > m)
    return Kthelement2(row2, row1, m, n, k);

  int low = max(0, k - m), high = min(n, k); // cannot take all elements 
  while (low <= high) {
    int cut1 = (low + high) >> 1;
    int cut2 = k - cut1;

    int l1 = cut1 == 0 ? INT_MIN : row1[cut1 - 1];
    int l2 = cut2 == 0 ? INT_MIN : row2[cut2 - 1];
    int r1 = cut1 == n ? INT_MAX : row1[cut1];
    int r2 = cut2 == m ? INT_MAX : row2[cut2];

    if (l1 <= r2 and l2 <= r1)
      return max(l1, l2);
    else if (l1 > r2)
      high = cut1 - 1;
    else
      low = cut1 + 1;
  }

  return 1;
}
/************************ALLOCATED MINIMUM NUMBER OF PAGES*********************************************/
//TC: O(NlogN)
bool isPossible(int n, int m, vector<int>& arr, long long int mid) {
    int dayCount = 1;
    long long int timeCount = 0;

    for (int i = 0; i < m; i++) {
        if (timeCount + arr[i] <= mid) {
            timeCount += arr[i];
        } else {
            dayCount++;
            if (dayCount > n || arr[i] > mid) {
                return false;
            } else {
                timeCount = arr[i];
            }
        }
    }
    return true;
}

long long int Allocatedbooks(int n, int m, vector<int>& time) {
    long long int low = 0;
    long long int sum = 0; // Calculate sum of time values
    for(int i=0;i<m;i++){
        sum+=time[i];
    }
    long long int high = sum;
    long long int ans = -1;

    while (low <= high) {
        long long int mid = low + (high-low) / 2;
        if (isPossible(n, m, time, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}
/*********************************AGGRESIVE COWS*********************************************/
// TC: O(NlogM)
// M is range of posible distance of stalls
bool canPlaceCows(vector<int> &stalls,int n, int cows, int dist){
    int coord= stalls[0];
    int cnt=1;
    for(int i=1;i<n;i++){
        if(stalls[i]-coord>=dist){
            coord=stalls[i];
            cnt++;
        }
        if(cows==cnt){
            return true;
        }
    }
    return false;
}
int aggressiveCows(vector<int> &stalls, int k)
{   
    sort(stalls.begin(),stalls.end());
    int low=1;
    int high= stalls[stalls.size()-1]-stalls[0];
    int res=-1;
    while(low<=high){
        int mid= (low+high)>>1;
        if(canPlaceCows(stalls, stalls.size(), k, mid)==true){
            res=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return res;

}