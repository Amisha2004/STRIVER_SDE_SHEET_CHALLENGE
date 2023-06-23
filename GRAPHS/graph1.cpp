#include <bits/stdc++.h> 
using namespace std;
/******************************CLONE GRAPH*********************************************/

	// Class for graph node is as follows:

	class graphNode
	{
		public:
    		int data;
    	vector<graphNode *> neighbours;
    	graphNode()
    	{
        	data = 0;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val)
    	{
        	data = val;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val, vector<graphNode *> neighbours)
    	{
        	data = val;
        	this->neighbours = neighbours;
    	}
	};
unordered_map<graphNode*,graphNode*> mp;
void dfs(graphNode* node)
{
    graphNode* copy=new graphNode(node->data);
    mp[node]=copy;
    for (auto i:node->neighbours)
    {
        if (mp.find(i)!=mp.end())
        {
            copy->neighbours.push_back(mp[i]);
        }
        else
        {
            dfs(i);
            copy->neighbours.push_back(mp[i]);
        }
    }
}
graphNode *cloneGraph(graphNode *node)
{
    // Write your code here.
    if (!node)
    {
        return NULL;
    }
    dfs(node);
    return mp[node];
}