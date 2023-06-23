#include<bits/stdc++.h>
using namespace std;
/*******************DFS TRAVERSAL OF GRAPH*****************************************/
// TC: O(E + V)
void dfs(int i,vector<int>adj[],vector<int>&v,vector<int>&vis){
      vis[i]=1;
      v.push_back(i);
       for(auto it: adj[i]){
           if(vis[it]==0){
               dfs(it,adj,v,vis);
           }
       }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{    
     vector<int>adj[V];
     for(int i=0;i<edges.size();i++){
         adj[edges[i][0]].push_back(edges[i][1]);
         adj[edges[i][1]].push_back(edges[i][0]);
     }
     vector<vector<int>>ans;
     vector<int>vis(V,0);
     for(int i=0;i<V;i++){
        if(vis[i]==0){
            vector<int>v;
            dfs(i,adj,v,vis);
            ans.push_back(v);
        }
     }
     return ans;
}
/***********************************BFS TRAVERSAL OF GRAPH**************************/
// TC: O(E + E * log(E) + V).
void bfs(int node,vector<int>adj[],vector<int>&vis,vector<int>&ans){
        queue<int>q;
         vis[node]=1;
         q.push(node);
         while(q.size()>0){
             int x= q.front();
             ans.push_back(x);
             q.pop();
             for(auto adjacent: adj[x]){
               if (vis[adjacent] != true) {
                 vis[adjacent] = 1;
                 q.push(adjacent);
               }
             }
         }
}
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
//    vector<int>ans;
   vector<int>adj[vertex];
   for(int i=0;i<edges.size();i++){
       int u= edges[i].first;
       int v= edges[i].second;
       adj[u].push_back(v);
       adj[v].push_back(u);
   } 
    for(int  i = 0;i<vertex;i++){
        sort(adj[i].begin(),adj[i].end());
    } 
    vector<int>vis(vertex,0);
     vector<int>ans;
       for(int i=0;i<vertex;i++){
        if(vis[i]==0){
           bfs(i,adj,vis,ans);
        }
       }
    return ans;
}
/******************DETECT A CYCLE IN UNDIRECTED GRAPH USING BFS***************************/
// TC: O(N+2*E)+O(N)
bool bfs_cycledetection(int i,int par,vector<int>adj[],vector<int>vis){
        queue<int>q;
        q.push(i);
        vis[i]=1;
        while(q.size()>0){
            int node= q.front();
            q.pop();
            for(auto it: adj[node]){
            if(vis[it]==0){
                if(bfs_cycledetection(it,node,adj,vis)==true){
                    return true;
                }
            }
            else{
                if(it!=par){
                    return true;
                }
            }
          }
        }
        
        return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
   vector<int>adj[n+1];
   for(int i=0;i<m;i++){
       int u= edges[i][0];
       int v= edges[i][1];
       adj[u].push_back(v);
       adj[v].push_back(u);
   }
   string ans="Yes";
   vector<int>vis(n+1,0);
   for(int i=1;i<=n;i++){
       if(vis[i]==0){
          if( bfs_cycledetection(i,-1,adj,vis)){
              return ans;
          }
       }
   }
   ans="No";
   return ans;
}
/******************DETECT A CYCLE IN UNDIRECTED GRAPH USING DFS***************************/
// TC: O(N+2*E)+O(N)
 bool dfs(int node, int parent, int vis[], vector<int> adj[]) {
        vis[node] = 1; 
        for(auto it: adj[node]) {
            if(!vis[it]) {
                if(dfs(it, node, vis, adj) == true) 
                    return true; 
            }
            else if(it != parent) return true; 
        }
        return false; 
    }
 bool isCycle(int V, vector<int> adj[]) {
       int vis[V] = {0}; 
       for(int i = 0;i<V;i++) {
           if(!vis[i]) {
               if(dfs(i, -1, vis, adj) == true) return true; 
           }
       }
       return false; 
    }
/********************DETECT A CYCLE IN DIRECTED GRAPH USING DFS******************************/
bool dfs_directedgraph(int i,int par,vector<int>adj[],vector<int>vis,vector<int>pathVis){
        vis[i]=1;
        pathVis[i]=1;
        for(auto it: adj[i]){
            if(vis[it]==0){
                if(dfs_directedgraph(it,i,adj,vis,pathVis)==true){
                    return true;
                }
            }
            else{
                if(pathVis[it]==1){
                    return true;
                }
            }
        }
        pathVis[i]=0;
        return false;
}
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
     vector<int>adj[n+1];
   for(int i=0;i<edges.size();i++){
       int u= edges[i].first;
       int v= edges[i].second;
       adj[u].push_back(v);
   }
   vector<int>pathVis(n+1,0);
   vector<int>vis(n+1,0);
   for(int i=1;i<=n;i++){
       if(vis[i]==0){
          if( dfs_directedgraph(i,-1,adj,vis,pathVis)){
              return 1;
          }
       }
   }
   return 0;
}
/**********************************TOPOLOGICAL SORT BFS**********************************************/
vector<int> topo_SORT(int N, vector<int> adj[]) {
        queue<int> q; 
	    vector<int> indegree(N, 0); 
	    for(int i = 0;i<N;i++) {
	        for(auto it: adj[i]) {
	            indegree[it]++; 
	        }
	    }
	    
	    for(int i = 0;i<N;i++) {
	        if(indegree[i] == 0) {
	            q.push(i); 
	        }
	    }
	    vector<int> ans;
	    while(!q.empty()) {
	        int node = q.front(); 
	        q.pop(); 
	        ans.push_back(node);
	        for(auto it : adj[node]) {
	            indegree[it]--;
	            if(indegree[it] == 0) {
	                q.push(it); 
	            }
	        }
	    }
	    return ans;
	}
/***********************************TOPOLOGICAL SORT DFS*********************************************/
void findTopoSort(int node, vector < int > & vis, stack < int > & s, vector < int > adj[]) {
    vis[node] = 1;

    for (auto it: adj[node]) {
      if (!vis[it]) {
        findTopoSort(it, vis, s, adj);
      }
    }
    s.push(node);
  }
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e) {
    vector<int>adj[v];
    for(int i=0;i<e;i++){
        adj[edges[i][0]].push_back(edges[i][1]);
    }
     stack < int > s;
      vector < int > vis(v, 0);
      for (int i = 0; i < v; i++) {
        if (vis[i] == 0) {
          findTopoSort(i, vis, s, adj);
        }
      }
      vector < int > topo;
      while (!s.empty()) {
        topo.push_back(s.top());
        s.pop();
      }
      return topo;
}
/***************************FIND NUMBER OF ISLANDS**************************************************/
void bfs(int** arr, int n, int m,int i,int j,vector<vector<int>>&vis){
          int dr[8]={-1,1,0,0,1,1,-1,-1};
          int dc[8]={0,0,-1,1,1,-1,1,-1};
           queue<pair<int,int>>q;
            if(arr[i][j]==1&&vis[i][j]==0){
               q.push({i,j});
            }
            vis[i][j]=1;
            while(q.size()>0){
               int x=q.front().first;
               int y=q.front().second;
               q.pop();
               for(int k=0;k<8;k++){
                  int nx= x+ dr[k];
                  int ny= y+dc[k];
                  if(nx>=0&&nx<n&&ny>=0&&ny<m&&arr[nx][ny]==1&&vis[nx][ny]==0){
                     q.push({nx,ny});
                     vis[nx][ny]=1;
                  }
               }
      }
}
int getTotalIslands(int** arr, int n, int m)
{   
   vector<vector<int>>vis(n,vector<int>(m,0));
   int cnt=0;
    for(int i=0;i<n;i++){
       for(int j=0;j<m;j++){
           if(vis[i][j]==0&&arr[i][j]==1){
              bfs(arr,n,m,i,j,vis);
              cnt++;
           } 
           
       }
    }
    return cnt;
}
/********************************CHECK BIPARTITE GRAPH USING DFS********************************************/
bool dfs_bipartite(int i,int col,vector<int>&colour,vector<int>adj[]){
      colour[i]=col;
      for(auto it: adj[i]){
		  if(colour[it]==-1){
			  colour[it]= !colour[i];
			  if(dfs_bipartite(it,colour[it],colour,adj)==false){
				  return false;
			  }
            } 
			else if (colour[it] == colour[i]) {
                    return false;
             }
         }
          return true;
}
bool isGraphBirpatite(vector<vector<int>> &edges) {
	int n=edges.size();
	int m=edges[0].size();
	vector<int>adj[n];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(edges[i][j]==1){
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}
	vector<int>colour(n,-1);
	for(int i=0;i<n;i++){
		if(colour[i]==-1){
                 if(dfs_bipartite(i,0,colour,adj)==false){
                     return false;
                 }
            }
	}
	  return true;
}