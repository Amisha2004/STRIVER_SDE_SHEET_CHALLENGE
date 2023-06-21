#include <bits/stdc++.h> 
using namespace std;
/*************************IMPLEMENTATION OF HEAP*******************************************/
// MIN HEAP
// TC: O(log(n))
void minHeapify(int i,vector<int>&heap){
    int leftChild=2*i+1;
    int rightChild= 2*i+2;
    int smallest=i;
    if(heap[leftChild]<heap[i]&&leftChild<heap.size()){
        smallest=leftChild;
    }
    if(heap[rightChild]<heap[i]&&heap[rightChild]<heap[leftChild]&&rightChild<heap.size()){
        smallest=rightChild;
    }
    if(smallest!=i){
        swap(heap[smallest],heap[i]);
        minHeapify(smallest,heap);
    }
    return;
}
// TC: O(log(n))
void insert(vector<int>&heap,int x){
    heap.push_back(x);
    int index=heap.size()-1;
    int parent= (index-1)/2;
    while(heap[parent]>heap[index]){
        minHeapify(parent,heap);
        index=parent;
        parent=(parent-1)/2;
    }
}
// TC: O(log(n))
int deletehead(vector<int>&heap){
    int ans=heap[0];
    swap(heap[0],heap[heap.size()-1]);
    heap.pop_back();
    minHeapify(0, heap);
    return ans;
}
vector<int> minHeap(int n, vector<vector<int>>& q) {
     vector<int>heap;
    vector<int>ans;
    for(int i=0;i<q.size();i++){
        if(q[i][0]==0){
            insert(heap,q[i][1]);
        }
        else{
            ans.push_back(deletehead(heap));
        }
    }
    return ans;
}
/************************Kth SMALLEST AND LARGEST ELEMENT OF ARRAY***********************************************/
//TC: O(log(n))
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
	sort(arr.begin(),arr.end());
	return {arr[k-1],arr[n-k]};
}
/************************K MAX SUM COMBINATIONS******************************************************************/
// TC: O(n^2 + k log n)
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
	priority_queue<int>pq;
	for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            pq.push(a[i] + b[j]);

        }
    }
	int i=0;
	 vector<int> ans;
    for(int i=0;i<k;i++){
        int it = pq.top();
        pq.pop();
        ans.push_back(it);
    }
    return ans;
}
/*******************************RUNNING MEDIAN*******************************************************************/
// TC: O(n * log n) 
// SC: O(n)
void findMedian(int *arr, int n)
{
   priority_queue<int>pq_max;
   priority_queue<int,vector<int>,greater<int>>pq_min;
   for(int i=0;i<n;i++){
       if(pq_max.size()==0){
           pq_max.push(arr[i]);
       }
       else if(arr[i]>pq_max.top()){
           pq_min.push(arr[i]);
       }
         else{
             pq_max.push(arr[i]);
         }
         if(pq_max.size()==pq_min.size()+2){
             int front= pq_max.top();
             pq_max.pop();
             pq_min.push(front);
         }
         else if(pq_min.size()==pq_max.size()+1){
             pq_max.push(pq_min.top());
             pq_min.pop();
         }
         if(pq_max.size()==pq_min.size()){
             int res= (pq_min.top() + pq_max.top() )/2;
             cout<<res<<" ";
         }
         else{
              cout<< pq_max.top()<<" ";
         }
   }
   
}
/********************************MERGE K SORTED ARRAYS**********************************************/
// TC: O(k * m + log n)
// m => maximum size of arrays
// n => total number of element in priority queue
// SC: O(N)
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0;i<k;i++){
        for(int j=0;j<kArrays[i].size();j++){
            pq.push(kArrays[i][j]);
        }
    }
    vector<int>ans;
    while( pq.size()>0){
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}
/*****************************K MOST FREQUENT ELEMENTS***************************************************/
// TC: O(n + m log m + k log m + k log k)
// m-> size of mp
// 
vector<int> KMostFrequent(int n, int k, vector<int> &nums)
{
    unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto it: mp){
            pq.push({it.second,it.first});
        }
        vector<int>ans;
        for(int i=0;i<k;i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
}
/******************************************************************************************************/