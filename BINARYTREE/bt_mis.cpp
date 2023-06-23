
#include <bits/stdc++.h> 
using namespace std;
class Node {
       public:
        int data;
        Node *left;
        Node *right;
        Node* next;
        Node(){
            left=NULL;
            right=NULL;
        }
        Node(int d) {
            this->data = d;
            left = NULL;
            right = NULL;
            next= NULL;
        }
};
class Solution {
    public: 
      Node* root = new Node();
/****************************CONVERT GIVEN BINARY TREE INTO DOUBLE LINKED LIST*************/
      void inordertraversal(Node* root,vector<int>&ans){
        if(root==NULL){
            return;
        }
        
        inordertraversal(root->left,ans);
        ans.push_back(root->data);
        inordertraversal(root->right,ans);
}
Node* BTtoDLL(Node* root) {
    // Write your code here
     if(root==NULL){
            return NULL;
        }
        vector<int>ans;
        inordertraversal(root,ans);
        Node* dummy=new Node(ans[0]);
         Node* head= dummy;
         Node* prev = NULL;
        for(int i=1;i<ans.size();i++){
             head->left=prev;
             head->right= new Node(ans[i]);
             prev=head;
             head=head->right;
        }
        return dummy;
}
/***************************MEDIAN IN STREAM********************************/
vector<int> findMedian(vector<int> &arr, int n){
	
	vector<int>res;
	priority_queue<int>pq;
    priority_queue<int,vector<int>,greater<int>>qq;
	for(int i=0;i<n;i++){
        pq.push(arr[i]);
        int temp = pq.top();
        pq.pop();
        qq.push(temp);
        if(qq.size() > pq.size()){
            temp = qq.top();
            qq.pop();
            pq.push(temp);
        }
        if(pq.size() != qq.size())  res.push_back(pq.top());

        else res.push_back((pq.top()+qq.top())/2);
    }

    return res;
}
/****************************Kth LARGEST ELEMENT IN STREAM**************************************/
class Kthlargest {
public:
    int len;
     priority_queue<int,vector<int>,greater<int>> pq;
    Kthlargest(int k, vector<int> &nums) {
       len=k;
          for(auto &i: nums){
              pq.push(i);
              if(pq.size()>len){
                  pq.pop();
              }
          }
    }

    void add(int num) {
         pq.push(num);
          if(pq.size()>len){
            pq.pop();
        }
      
    }

    int getKthLargest() {
        return pq.top();
    }

};
/*********************COUNT DISTINCT ELEMENT IN EVERY K SIZE WINDOW*********************************/
vector<int> countDistinctElements(vector<int> &arr, int k) 
{
     unordered_map<int,int>  mp;

   int i = 0 , n = arr.size();

   vector<int> ans;
	for(int j=0;i<=n-k;j++){
        mp[arr[j]]++;
        if(j>=k-1){
            ans.push_back(mp.size());
            mp[arr[i]]--;
            if(mp[arr[i]]==0){
                mp.erase(arr[i]);
            }
            i++;
        }
    }
    return ans;
  
}
/***********************Kth LARGEST ELEMENT IN A UNSORTED ARRAY**********************************/
int kthLargest(vector<int>& nums, int size, int K)
{
	  sort(nums.begin(),nums.end());
        return nums[size-K];
}
/************************FLOOD FILL ALGORITHM****************************************************/
vector<vector<int>> floodFill(vector<vector<int>> &image,int sr, int sc, int color )
{
   int m=image.size();
         int n=image[0].size();
         queue<pair<int,int>>q;
         vector<vector<int>>ans=image;
         q.push({sr,sc});
         int drow[4]={1,-1,0,0};
         int dcol[4]={0,0,1,-1};
         while(q.size()>0){
             int r= q.front().first;
             int c= q.front().second;
             int oldcolor=image[r][c];
             ans[r][c]=color;
             q.pop();
              for(int i=0;i<4;i++){
                  for(int j=0;j<4;j++){
                      int nrow=r+drow[i];
                      int ncol=c+dcol[i];
                      if(nrow>=0&&nrow<m&&ncol>=0&&ncol<n&&image[nrow][ncol]==oldcolor&&ans[nrow][ncol]!=color){
                           ans[nrow][ncol]=color;
                           q.push({nrow,ncol});
                      }
                  }
              }
         }
         return ans;
}
};