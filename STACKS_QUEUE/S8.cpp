// THE CELEBRITY PROBLEM
#include <bits/stdc++.h> 
using namespace std;
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
