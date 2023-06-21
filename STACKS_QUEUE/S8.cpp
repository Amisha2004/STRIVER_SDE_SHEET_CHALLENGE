#include <bits/stdc++.h> 
using namespace std;
/********************STOCK SPAN PROBLEM************************************/
vector<int> findSpans(vector<int> &arr) {
    stack<pair<int,int>>s;
    int n=arr.size();
    vector<int>ans;
    for(int i=0;i<n;i++){
        if(s.size()==0){
            ans.push_back(-1);
        }
        else if(s.size()>0 && (s.top().first)>arr[i]){
            ans.push_back(s.top().second);
        }
        else if(s.size()>0&&s.top().first<=arr[i]){
            while(s.size()>0&&s.top().first<=arr[i]){
                s.pop();
            }
            if(s.size()==0){
                ans.push_back(-1);
            }
            else {
                ans.push_back(s.top().second);
            }
        }
        s.push({arr[i],i});
    }
    for(int i=0;i<ans.size();i++){
        ans[i]=i-ans[i];
    }
    return ans;
}
/************************MAXIMUM OF MINIMUM FOR EVERY WINDOW SIZE*************************/
vector<int> maxMinWindow(vector<int> arr, int n) {
    stack<int> s;
    vector<int>left(n+1,-1) ;
    vector<int>right(n+1,n);

    for (int i = 0; i < n; i++) {
      while (!s.empty() && arr[s.top()] >= arr[i]) {
        s.pop();
      }
      if (!s.empty()) {
        left[i] = s.top();
      }
        s.push(i);
    }

    while (!s.empty()) {
      s.pop();
    }
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && arr[s.top()] >= arr[i])
            s.pop();
 
        if (!s.empty())
            right[i] = s.top();
 
        s.push(i);
    }
    vector<int>ans(n+1,INT_MIN),res(n);
    for (int i = 0; i < n; i++) {
        int len = right[i] - left[i] - 1;
        ans[len] = max(ans[len], arr[i]);
    }
    for (int i = n - 1; i >= 1; i--)
        ans[i] = max(ans[i], ans[i + 1]);
 
     for (int i = 1; i <= n; i++)
    res[i - 1] = ans[i];

  return res;
}
/*****************************THE CELEBRITY PROBLEM***************************************/
/*****************GIVEN IN THE QUESTION********************/
vector<vector<int>>check;
bool knows(int i,int j){
    if(check[i][j]==0){
        return false;
    }
    else{
        return true;
    }
}
// BRUTE FORCE APPROACH
int findCelebrity1(int n) {
	int x=0;
	int ind;
 	for(int i=0;i<n;i++){
		  int cnt=0;
		 for(int j=0;j<n;j++){
			if(knows(i,j)==false&& i!=j){
				cnt++;
			 }
		 }
        if(cnt==n-1){
			x++;
			ind=i;
		 }
	 }
	 if(x==1){
		 return ind;
	 }
	 return -1;
}
// USING GRAPH CONCEPT
// IDEA: Thinking every index from 0 to n as a nodes of graph and if knows(i,j)==1 
// that means i know j , so there will be a edge between i and j.
// as i know j therefore, outdegree[i] increases and indegree[j] increases.
// as a result i is celebrity if indegree[i]==n-1 and outdegree[i]==0
// that implies all n-1 person know i but i don't know anyone.
int findCelebrity2(int n) {
	 int outdegree[n]={0};
     int indegree[n] = { 0 }; 
     for(int i=0;i<n;i++){
		 for(int j=0;j<n;j++){
			 if(knows(i,j)==true){
				 outdegree[i]++;
				 indegree[j]++;
			 }
		 }
	 }
	 for(int i=0;i<n;i++){
		 if(indegree[i]==n-1&&outdegree[i]==0){
			 return i;
		 }
	 }
	 return -1;
}
// USING STACKS
// IDEA: First push every index in a stack
// now, we just want to have one element in stack , we are just rejecting the index that can't be a celebrity
// and adding back that index to stack which can be a celebrity.
// now, after that check only that element
int findCelebrity3(int n) {
	 stack<int>s;
	 for(int i=0;i<n;i++){
		 s.push(i);
	 }
	 while(s.size()>1){
		 int A= s.top();
		 s.pop();
		 int B=s.top();
		 s.pop();
		 if(knows(A,B)==false){
			 // A can be a celebrity
             s.push(A);
		 }
		 else {
			 // B can be a celebrity
			  s.push(B);
		 }
	 }
	 int ans=s.top();
	 s.pop();
	 // check in a row
	 for(int i=0;i<n;i++){
		 if(ans==i){
			  continue;
		  }
          if(knows(ans,i)==true){
			  return -1;
		  }
	 }
	 // check in a col
	 for(int i=0;i<n;i++){
		  if(ans==i){
			  continue;
		  }
          if(knows(i,ans)==false){
			  return -1;
		  }
	 }
	 return ans;
}
