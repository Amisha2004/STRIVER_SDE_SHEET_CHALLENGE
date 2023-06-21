#include <bits/stdc++.h>
using namespace std;
/************************FRACTIONAL KNAPSACK**************************************/
// GREEDY APPROACH: The approach is to create a vector that stores two values: one as a double 
//representing the value/weight ratio, and the other as a pair consisting of the weight and value.
// This allows us to sort the vector based on the value/weight ratio. We can then traverse the vector
// and select the elements with higher ratios first.
// TC: O(nlogn)
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
     double ans=0;
     vector<pair<double,pair<int, int>>>temp;
         for(int i=0;i<n;i++){
             auto it= items[i];
             int weight= it.first;
             int value=it.second;
            temp.push_back({(double)value/(double)weight,{weight,value}});
         }
     sort(temp.begin(),temp.end());
     int currWeight=0;
     for(int i=temp.size()-1;i>=0;i--){
         if(currWeight+ temp[i].second.first<=w){
             ans+=(temp[i].second.second);
             currWeight+=temp[i].second.first;
         }
         else{
             int remain= w- currWeight;
             ans+= (temp[i].first) * remain;
             break;
         }
     }
     return ans;
}
/***********************FIND MINIMUM NUMBER OF COINS*********************************/
// TC: O(n) => n is number of types of coin
int findMinimumCoins(int amount) 
{
     int arr[9]={1000,500,100,50,20,10,5,2,1};
     int cnt=0;
     int i=0;
    while(amount!=0&&i<9){
        if(amount<arr[i]){
            i++;
            continue;
        }
          cnt++;
          amount=amount-arr[i];
    }
    return cnt;
}
/***********************MAXIMUM ACTIVITIES*******************************************/
// GRREDY APPROACH: The idea is to sort the intervals according to their end times and traverse through
//  the vector, we can maintain a variable to keep track of the previous interval's end time.
// During traversal, we compare the starting time of the current interval with the end time of 
//the previous interval. If the starting time of the current interval is greater than or equal
// to the ending time of the previous interval, we increase the count and change the prev to curernt.
// TC: O(nlogn)
int maximumActivities(vector<int> &start, vector<int> &end) {
    vector<pair<int,int>>v;
    for(int i=0;i<start.size();i++){
        v.push_back({end[i],start[i]});
    }
    sort(v.begin(),v.end());
    int prev;
    int cnt=0;
    for(int i=0;i<v.size();i++){
        auto it1=v[i];
        int e1= it1.first;
        int s1= it1.second;
        if(i>0){
             auto it2=v[prev];
             int e2= it2.first;
            if(s1>=e2){
                 cnt++;
                prev=i;
            }
         }
         else{
             cnt++;
             prev=i;
         }
    }
    return cnt;
}
/****************************************************************************************/