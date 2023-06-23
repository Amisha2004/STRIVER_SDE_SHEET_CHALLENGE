#include<bits/stdc++.h>
using namespace std;
/******************************STRONGLY CONNECTED COMPONENTS*****************************/
// TC: O(V+E) + O(V+E) + O(V+E) = O(V+E)
void dfs1(int node,vector<int>adj[],vector<int>&vis,stack<int>&s){
    vis[node] = 1;
    for(auto i: adj[node]) {
        if(!vis[i])
            dfs1(i,adj,vis,s);
    }
    s.push(node);
}
void dfs2(int node,vector<int>adj[],vector<int>&vis,vector<int>&ans){
    vis[node] = 1;
    ans.push_back(node);
    for(auto i: adj[node]) {
        if(!vis[i])
            dfs2(i,adj,vis,ans);
    }
}
vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    vector<int>adj1[n],adj2[n];
    for(auto i: edges) 
        adj1[i[0]].push_back(i[1]);
    //  for(int i=0;i<n;i++){
    //      adj1[edges[i][0]].push_back(edges[i][1]);
    //  }
    vector<int>vis(n);
    stack<int>s;
    for(int i=0;i<n;i++) {
        if(!vis[i])
            dfs1(i,adj1,vis,s);
    }
    for(int i=0;i<n;i++) {
        vis[i] = 0;
        for(auto j: adj1[i])
            adj2[j].push_back(i);
    }
    vector<vector<int>>res;
    while(!s.empty()) {
        auto node = s.top();
        s.pop();
        vector<int>ans;
        if(!vis[node]) {
            dfs2(node,adj2,vis,ans);
        }
        res.push_back(ans);
    }
    return res;
}
/**************************DIJKSTRA SHORTEST PATH**************************************************/
// TC:  O( E log(V) ) { for Dijkstra’s Algorithm } + O(V) { for backtracking in order to find the parent for each node }
// Where E = Number of edges and V = Number of Nodes.
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
     vector<pair<int,int>>adj[vertices];
     for(int i=0;i<edges;i++){
         int u=vec[i][0];
         int v=vec[i][1];
         int wt=vec[i][2];
         adj[u].push_back({v,wt});
         adj[v].push_back({u,wt});
     }
     vector<int>dist(vertices,1e15);
     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
     pq.push({0,source});
     dist[source]=0;
     while(pq.size()>0){
          auto it=pq.top();
          int node=it.second;
          int dis= it.first;
          pq.pop();
          for(auto it: adj[node]){
               int x= it.first;
               int wt=it.second;
               if (dis + wt < dist[x]) {
                    dist[x]= dis+wt;
                    pq.push({dis+wt,x});
               }
          }
     }
     return dist;
}
/********************************BELLMON FORD****************************************/
// TC: O(V*E)
int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    vector<int>dist(n+1,1e9);
    dist[src]=0;
    for(int i=1;i<=n;i++){
        for(int j=0; j<m; j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];

            if(dist[u] != 1e9 && (dist[u] + w) < dist[v]){
                dist[v] = dist[u]+w;
            }
        }
		}
    bool flag = 0;
    for(int j=0; j<m; j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];

            if(dist[u] != 1e9 && (dist[u] + w) < dist[v]){
                flag = 1;
            }
    }
    if(flag == 0)
        return dist[dest];
    return -1;
}
/**************************************FLOYD WARSHALL ALGORITHM*********************************/
// TC:  O(V^3)
int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) { 
        vector<vector<int>>matrix(n+1,vector<int>(n+1,-1));
        for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(i==j){
                matrix[i][j]=0;
            }
            else{
                matrix[i][j]=INT_MAX;
            }
        }
       }
        for(auto it:edges) {
        matrix[it[0]][it[1]]=it[2];
       }
        for(int k=1;k<=n;k++)
        {
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    // int val = matrix[i][j];
                    // int m1 = matrix[i][k];
                    // int m2 = matrix[k][j];
                    if(i!=k && j!=k && matrix[i][k]!=INT_MAX && matrix[k][j]!=INT_MAX) {
                    matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
                    }
                }
            }
        }
        return matrix[src][dest]==INT_MAX?1e9:matrix[src][dest];
}
/***************************MST USING PRIM'S ALGORITHM****************************************/
//TC: O(E*logE) + O(E*logE)~ O(E*logE)
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{   
      unordered_map<int,vector<vector<int>>>adj;
    for(auto it:g) {
        int u = it.first.first;
        int v = it.first.second;
        int w = it.second;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    vector<int>vis(n+1,0);
    vector<pair<pair<int,int>,int>>ans;
    // v = {weight,source,destination}
    priority_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int>>,greater<pair<pair<int,int>,int>>>pq;
    pq.push({{0,-1},1});
      while(!pq.empty()) {
        auto it=pq.top();
        pq.pop();
        int wt=it.first.first,src=it.first.second,node=it.second;
        if(vis[node]) {
            continue;
        }
        vis[node]=1;
        if(src!=-1) {
            ans.push_back({{src,node},wt});
        }
        for(auto it:adj[node]) {
            if(!vis[it[0]]) {
                pq.push({{it[1],node},it[0]});
            }
        }
    }
    return ans;
}
/*************************MST USING KRUSKAL ALGORITHM*************************************/
// TC: O(N+E) + O(E logE) + O(E*4α*2)
class Disjoint {
    vector<int> parent, size;
    public: 
        Disjoint(int n) {
            parent.resize(n+1);
            size.resize(n+1,1);
            for(int i=1;i<=n;i++)
                parent[i] = i;
        }
        int find(int node) {
            if(node == parent[node])
                return node;
            return parent[node] = find(parent[node]);
        }
        void unionBySize(int u, int v) {
            int pu = find(u), pv = find(v);
            if(size[pu] < size[pv]) {
                parent[pu] = pv;
                size[pv] += size[pv];
            }
            else {
                parent[pv] = pu;
                size[pu] += size[pv];
            }
        }
};
int kruskalMST(int n, int m, vector<vector<int>> &graph) {
	vector<pair<int,pair<int,int>>>edges;
    for(auto i: graph) {
        int u = i[0], v = i[1], wt = i[2];
        edges.push_back({wt,{u,v}});
        edges.push_back({wt,{v,u}});
    }
    sort(edges.begin(), edges.end());
    Disjoint d(n);
	   int sum = 0;
	 for(auto i: edges) {
        int wt = i.first, u = i.second.first, v = i.second.second;
        if(d.find(u) != d.find(v)) {
            sum += wt;
            d.unionBySize(u,v);
        }
    }
    
    return sum;
}