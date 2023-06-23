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
/************************LEVEL ORDER TRAVERSAL*******************************/
// TC: O(n)
    vector<int> getLevelOrder(Node *root){
    vector<int>ans;
        if(root==NULL){
            return ans;
        }
        queue<Node *>q;
        q.push(root);
        while(q.size()>0){
            int n=q.size();
            while(n--){
                Node * temp=q.front();
                ans.push_back(temp->data);
                q.pop();
                if(temp->left!=NULL){
                    q.push(temp->left);
                }
                if(temp->right!=NULL){
                    q.push(temp->right);
                }
            }
        }
        return ans;
}
/****************HEIGHT OF BINARY TREE FROM INORDER AND LEVEL ORDER TRAVERSAL***************************/
// CODING NINJAS
int heightOfTheTree(vector<int>& inorder, vector<int>& levelOrder, int N){
	   unordered_map<int, int> map;
    for(int i = 0;i < N; i++) {
        map[inorder[i]] = i;
    }
            queue<pair<int,pair<int,int>>>q;
		q.push({0,{0,N-1}});
		int maxx= INT_MIN;
		for(int i=0;i<N;i++){
			auto it=q.front();
			int height=it.first;
			maxx=max(maxx,height);
			int start=it.second.first;
			int end=it.second.second;
			q.pop();
			// for(int j=0;j<N;j++){
				// if(levelOrder[i]==inorder[j]){
				int j= map[levelOrder[i]];
					if(j-1>=start){
						q.push({height+1,{start,j-1}});
					}
					if(j+1<=end){
						q.push({height+1,{j+1,end}});
					}
				// }
			// }
		}
		return maxx;
}
// LEETCODE
int maxDepth(Node* root) {
        // vector<vector<int>>ans;
        if(root==NULL){
            return 0;
        }
        queue<pair<Node*,int>>q;
        q.push({root,1});
        int max_depth= INT_MIN;
        while(q.size()>0){
            int n=q.size();
            vector<int>v;
            while(n--){
                Node* temp=q.front().first;
                int level=q.front().second;
                max_depth= max(max_depth,level);
                q.pop();
                if(temp->left!=NULL){
                    q.push({temp->left,level+1});
                }
                if(temp->right!=NULL){
                    q.push({temp->right,level+1});
                }
            }
        }
        return max_depth;
    }
/************************DIAMETER OF BINARY TREE***************************************/
// TC: O(N)
int height(Node * root,int& dia){
           if(root==NULL){
               return 0;
           }
           int leftHeight= height(root->left,dia);
           int rightHeight= height(root->right,dia);
           dia = max(dia,leftHeight+rightHeight);

           return 1+max(leftHeight,rightHeight);
}
int diameterOfBinaryTree(Node *root){
	int dia =0;
    height(root,dia);
    return dia;
}
/******************IS HEIGHT BALANCED BINARY TREE***************************************/
// TC: O(N)
int heights(Node* root,int& diff){
     if(root==NULL){
         return 0;
     }
     int leftHeight= heights(root->left,diff);
     int rightHeight= heights(root->right,diff);
     diff= max(diff, abs(leftHeight-rightHeight));
     return 1+max(leftHeight,rightHeight);
}
bool isBalancedBT(Node* root) {
   int diff=0;
   heights(root,diff);
//    cout<<diff<<endl;
   if(diff<=1){
       return true;
   }
   else{
       return false;
   }
}
/********************LCA IN BINARY TREE***************************************************/
//TC: O(N)
int lowestCommonAncestor(Node *root, int x, int y)
{   
    if(root == NULL) return -1;
    if(root->data == x) return x;
    if(root->data == y) return y;
    int left = lowestCommonAncestor(root->left, x, y);
    int right = lowestCommonAncestor(root->right, x, y);
    if(left != -1 && right != -1) return root->data;
    return max(left, right);
}
/**************************CHECK IDENTICAL TREES*****************************************/
// TC: O(n)
bool identicalTrees(Node* p, Node * q) {
       if(p==NULL&&q==NULL){
            return true;
        }
        if(p==NULL){
            return false;
        }
        if(q==NULL){
            return false;
        }
        if(p->data==q->data){
            return identicalTrees(p->left,q->left)&& identicalTrees(p->right,q->right);
        }
        return false;	 
}
/**********************BINARY TREE ZIG ZAG TRAVERSAL ************************************/
// TC: O(n)
vector<int> zigZagTraversal(Node *root)
{
     vector<int>ans;
        if(root==NULL){
            return ans;
        }
        queue<pair<Node*,int>>q;
        q.push({root,0});
        while(q.size()>0){
            int n=q.size();
            vector<int>v;
            int level;
            while(n--){
                auto it=q.front();
                Node *temp=it.first;
                v.push_back(temp->data);
                level=it.second;
                q.pop();

                    if(temp->left!=NULL){
                        q.push({temp->left,level+1});
                    }
                    if(temp->right!=NULL){
                        q.push({temp->right,level+1});
                    }
            }
            if(level%2==0){
                 for(int i=0;i<v.size();i++){
                     ans.push_back(v[i]);
                 }
            }
            else{
                // reverse(v.begin(),v.end());
                 for(int i=v.size()-1;i>=0;i--){
                     ans.push_back(v[i]);
                 }
            }
            v.clear();
        }
        return ans;
}
/**************************BOUNDARY TRAVERSAL OF BINARY TREE***********************************/
// TC: O(N)
void leftNode(Node *root,vector<int>&ans){
    if(root==NULL||(!root->left&&!root->right)){
        return;
    }
    if(root->left!=NULL){
        ans.push_back(root->data);
       leftNode(root->left,ans);
    }
    else if(root->right!=NULL){
        ans.push_back(root->data);
        leftNode(root->right, ans);
    }

}
void printLeafNodes(Node *root,vector<int>&ans)
{
    if (!root)
        return;
    if (!root->left && !root->right)
    {
       ans.push_back(root->data);
        return;
    }
    if (root->left) {
      printLeafNodes(root->left,ans);
    }
    if (root->right) {
      printLeafNodes(root->right, ans);
    }
}
void rightNode(Node *root, vector<int> &ans)
{
  if (root == NULL||(!root->left&&!root->right)) {
    return;
  }
    if(root->right!=NULL){
        // ans.push_back(root->data);
        rightNode(root->right, ans);
    }
    else if(root->left!=NULL){
        // ans.push_back(root->data);
        leftNode(root->left, ans);
    }
     ans.push_back(root->data);
}
vector<int> traverseBoundary(Node* root){
     vector<int>ans;
     if(root==NULL){
         return ans;
     }
     ans.push_back(root->data);
     if(root->left==NULL&&root->right==NULL){
         return ans;
     }
     leftNode(root->left,ans);
     printLeafNodes(root, ans);
     rightNode(root->right, ans);
     return ans;
}
};