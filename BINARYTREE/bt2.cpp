
#include <bits/stdc++.h> 
using namespace std;
class Node {
       public:
        int data;
        Node *left;
        Node *right;
        Node(){
            left=NULL;
            right=NULL;
        }
        Node(int d) {
            this->data = d;
            left = NULL;
            right = NULL;
        }
};
class Solution {
    public: 
      Node* root = new Node();
/******************************LEFT VIEW OF BINARY TREE********************************************/
// METHOD 1:
// TC : O(n), where n is number of nodes
// SC : O(n)
    void helper_left(Node *root,int level, vector<int> &ans){
      if(root==NULL){
          return;
      }
      if(ans.size()==level){
          ans.push_back(root->data);
      }
      helper_left(root->left,level+1,ans);
      helper_left(root->right,level+1,ans);
    }
    vector<int> getLeftView(Node *root){
     vector<int>ans;
     helper_left(root,0,ans);
     return ans;
    }
// METHOD 2: LEVEL ORDER TRAVERSAL
// In the worst case scenario, where the binary tree is skewed and resembles a linked list,
// the number of nodes visited will be equal to the number of nodes in the tree, 
// resulting in a time complexity of O(n). However, in a balanced binary tree,
// the time complexity will be closer to O(log n).
    vector<int> getLeftView(Node *root){   
     queue<Node *>q;
     q.push(root);
     vector<int>ans;
      if(root==NULL){
        return ans;
    }
     while(q.size()>0){
         int n=q.size();
         while(n--){
             Node *temp= q.front();
             q.pop();
             if (n == 0) {
               ans.push_back(temp->data);
             }
             if(temp->right!=NULL){
                 q.push(temp->right);
             }
             if (temp->left != NULL) {
               q.push(temp->left);
             }
         }
     }
     return ans;
}
/********************RIGHT VIEW OF BINARY TREE******************************/
// SOLUTION 1:
// TC: O(n), where n is number of nodes
// SC: O(n)
    void helper_right(Node *root,int level, vector<int> &ans){
      if(root==NULL){
          return;
      }
      if(ans.size()==level){
          ans.push_back(root->data);
      }
      helper_right(root->right,level+1,ans);
      helper_right(root->left,level+1,ans);
    }
    vector<int> getRightView(Node *root){
     vector<int>ans;
     helper_right(root,0,ans);
     return ans;
    }
// SOLUTION 2:
// TC: O(n)
// SC: O(n)
vector<int> bottomView(Node * root){
    vector<int>ans;
    queue<pair<Node *,int>>q;
    map<int,int>mp;
    q.push({root,0});
    while(q.size()>0){
        Node* temp= q.front().first;
        int Horizontal_Dist = q.front().second;
        q.pop();
        mp[Horizontal_Dist]= temp->data;
        if(temp->left!=NULL){
            q.push({temp->left,Horizontal_Dist-1});
        }
        if(temp->right!=NULL){
            q.push({temp->right,Horizontal_Dist+1});
        }
    }
    for(auto it: mp){
        ans.push_back(it.second);
    }
    return ans;
}
/***********************BOTTOM VIEW OF BINARY TREE***********************************************/
vector<int> bottomView(Node * root){

    // Write your code here.
    vector<int>ans;
    queue<pair<Node *,int>>q;
    map<int,int>mp;
    q.push({root,0});
    while(q.size()>0){
        Node * temp= q.front().first;
        int Horizontal_Dist = q.front().second;
        q.pop();
        mp[Horizontal_Dist]= temp->data;
        if(temp->left!=NULL){
            q.push({temp->left,Horizontal_Dist-1});
        }
        if(temp->right!=NULL){
            q.push({temp->right,Horizontal_Dist+1});
        }
    }
    for(auto it: mp){
        ans.push_back(it.second);
    }
    return ans;
}

/***************************TOP VIEW OF BINARY TREE****************************************/
// TC: O(n)
vector<int> getTopView(Node *root) {

  vector<int> ans;
  if (root == NULL){
      return ans;
  }
    queue<pair<Node *,int>>q;
    map<int,int>mp;
    q.push({root,0});
    while(q.size()>0){
        Node* temp= q.front().first;
        int Horizontal_Dist = q.front().second;
        q.pop();
        if(mp.find(Horizontal_Dist)==mp.end()){
            mp[Horizontal_Dist]= temp->data;
        }
        if(temp->left!=NULL){
            q.push({temp->left,Horizontal_Dist-1});
        }
        if(temp->right!=NULL){
            q.push({temp->right,Horizontal_Dist+1});
        }
    }
    for(auto it: mp){
        ans.push_back(it.second);
    }
    return ans;
}
/***************************VERTICAL ORDER TRAVERSAL ************************************/
vector<int> verticalOrderTraversal(Node*root)
{
    vector<int>ans;
       map<int,map<int,vector<int>>>mp;
        queue<pair<Node*,pair<int,int>>>q;
        q.push({root,{0,0}});
        while(q.size()>0){
            Node* temp= q.front().first;
            int col= q.front().second.first;
            int row= q.front().second.second;
            mp[col][row].push_back(temp->data);
            q.pop();
            if(temp->left!=NULL){
                q.push({temp->left,{col-1,row+1}});
            }
            if(temp->right!=NULL){
                q.push({temp->right,{col+1,row+1}});
            }
        }
       
        for(auto it: mp){
            vector<int>v;
            for(auto ite: it.second){
                vector<int> &x = ite.second;
                // sort(x.begin(),x.end());
                // v.insert(v.end(),x.begin(),x.end());
                for(int i=0;i<x.size();i++){
                    v.push_back(x[i]);
                }
            }
              for(int i=0;i<v.size();i++){
                  ans.push_back(v[i]);
              }
            // ans.push_back(v);
        }
        return ans;
}
/**********************ROOT TO NODE PATH IN A BINARY TREE*****************************************/
// TC: O(n)
bool helper_Path(Node * root, vector < int > & ans, int x) {
      if(root==NULL){
		  return false;
	  }
       ans.push_back(root->data);
       if (root -> data == x){
		   return true;
	   }
      if(helper_Path(root -> left, ans, x)||
	  helper_Path(root -> right, ans, x)){
          return true;
	  }
	  ans.pop_back();
	  return false;
}


vector<int> pathInATree(Node *root, int x)
{  
	vector < int > ans;
    bool res= helper_Path(root, ans, x);
    return ans;
}
/****USING LEVEL ORDER TRAVERSAL******/
vector<int> pathInATree(Node *root, int x)
{
    queue<pair<Node *,int>>q;
    map<int,int>mp;
	q.push({root,-1});
	while(q.size()>0){
		auto it= q.front();
		q.pop();
		Node *temp= it.first;
		int parent=it.second;
		mp[temp->data]=parent;
		if(temp->left!=NULL){
			q.push({temp->left,temp->data});
		}
		if(temp->right!=NULL){
			q.push({temp->right,temp->data});
		}
	}
	vector<int>ans;
	ans.push_back(x);
	for(auto it: mp){
		x=mp[x];
		if(x==-1){
			break;
		}
        ans.push_back(x);
	}
	reverse(ans.begin(),ans.end());
	return ans;
}

/*************************MAXIMUM WIDTH OF BINARY TREE*********************************/
//In the worst case scenario, where the binary tree is skewed and resembles a linked list,
// the number of nodes visited will be equal to the number of nodes in the tree, resulting
// in a time complexity of O(n). However, in a balanced binary tree, the time complexity will be closer to O(log n).
int getMaxWidth(Node *root)
{
       if(!root) 
       return 0;
    queue<Node*>q;
    int ans=INT_MIN;
    q.push(root);
    while(!q.empty()){
        int s=q.size();
        ans=max(ans,s);
        while(s--){
            auto it=q.front();
            q.pop();
            if(it->left) q.push(it->left);
            if(it->right) q.push(it->right);
        }
    }
    return ans;
}
};