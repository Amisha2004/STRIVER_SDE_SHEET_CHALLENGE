#include <bits/stdc++.h> 
using namespace std;
/***************************MAXIMUM MEETINGS********************************************************/
// GREEDY APPROACH:   We then proceed to traverse through the array while keeping track of the previous 
//element. During this traversal, we check if the starting value of the current element is greater than
// the ending value of the previous element. If it is, we add the current element to the answer vector 
//using the push_back function and update the previous element to the current element.
// TC: O(n)+O(nlogn)+O(n) = O(nlogn)
vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    vector<int>ans;
    vector<pair<pair<int,int>,int>>v;
    for(int i=0;i<start.size();i++){
        v.push_back({{end[i],i+1},start[i]});
    }
    sort(v.begin(),v.end());
    int prev;
    for(int i=0;i<v.size();i++){
        auto it1=v[i];
        int e1= it1.first.first;
        int s1= it1.second;
        int ind1= it1.first.second;
        if(i>0){
             auto it2=v[prev];
             int e2= it2.first.first;
            if(s1>e2){
                ans.push_back(ind1);
                prev=i;
            }
         }
         else{
             ans.push_back(ind1);
             prev=i;
         }
    }
    return ans;
}
/*************************MINIMUM NUMBER OF PLATFORMS REQUIRED FOR A RAILWAY*****************************/
// GREEDY APPROACH: The approach involves sorting the arrival timing vector and departure timing vector separately.
// After sorting, we can traverse through the vectors using two pointers, i and j, for arrival and departure timings,
// respectively.
// During the traversal, if the arrival time is less than or equal to the departure time, it indicates that an extra
// platform is needed. In such cases, we increase the value of the i pointer. On the other hand, if the departure time
//  is less than the arrival time, it means that a platform has become vacant. We can then increase the value of the j
//  pointer.
// By using this method, we can efficiently determine the number of extra platforms required for a given set of arrival
//  and departure timings.
// TC: O(nlogn)+ O(nlogn)+ O(2*n) => O(2* nlogn)
int calculateMinPatforms(int at[], int dt[], int n) {
     sort(at,at+n);
     sort(dt,dt+n);
     int platform=0;
     int mini=0;
     int i=0;
     int j=0;
     while(i<n&&j<n){
         if(at[i]<=dt[j]){
             platform++;
             mini=max(mini,platform);
             i++;
         }
         else{
             platform--;
             j++;
         }
         
     }
     while(i<n){
         platform++;
         mini=max(mini,platform);
         i++;
     }
     while(j<n){
         platform--;
         j++;
     }
     return mini;
}
/************************JOB SEQUENCING PROBLEM*********************************************/
// GREEDY APPROACH: sort an 2D array on the basis of their profit and find the maximum deadline 
// now, create an vector of size maxdeadline+1 and traverse into the array and calculate the maximum profit
// TC: O(nlogn)
bool comp(vector <int> a,vector<int> b)
{
     return a[1]>b[1];
}
int jobScheduling(vector<vector<int>> &jobs)
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

/*****************************************/

