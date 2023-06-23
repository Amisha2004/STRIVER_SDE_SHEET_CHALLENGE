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
/*************************************MAXIMUM PATH SUM**********************************/
long long int findMaxPathSumhelper(Node * root, long long int & maxi) {
  if (root == NULL) return 0;

  long long int leftMaxPath =  findMaxPathSumhelper(root -> left, maxi);
  long long int rightMaxPath = findMaxPathSumhelper(root -> right, maxi);
  maxi = max(maxi, (leftMaxPath + rightMaxPath) + root->data);
  return max(leftMaxPath, rightMaxPath) + root->data;

}
long long int findMaxSumPath(Node *root) {
    if(root==NULL || root->left==NULL || root->right==NULL) return -1;
    long long int maxi=INT_MIN;
    long long int ans= findMaxPathSumhelper(root, maxi);
    return maxi;
}
/**************CONSTRUCT BINARY TREE FROM INORDER AND PREORDER TRAVERSAL***************/
Node* constructTrees(vector<int>& preorder, vector<int>& inorder,int inStart,int inEnd,int preStart,int preEnd,map<int,int>&mp){
        if (preStart > preEnd || inStart > inEnd) return NULL;

       Node * root= new Node(preorder[preStart]);
        int ind = mp[root->data];
        int pE= ind-inStart;
        root->left=constructTrees(preorder,inorder,inStart,ind-1,preStart+1,preStart+pE,mp);
        root->right=constructTrees(preorder,inorder,ind+1,inEnd,preStart+1+pE,preEnd,mp);

        return root;
    }
Node *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
	int preStart = 0, preEnd = preorder.size() - 1;
         int inStart = 0, inEnd = inorder.size() - 1;
        map<int,int>mp;
        for(int i=inStart;i<=inEnd;i++){
            mp[inorder[i]]=i;
        }
       return constructTrees(preorder,inorder,inStart,inEnd,preStart,preEnd,mp);
}
/************CONSTRUCT BINARY TREE FROM INORDER AND POSTORDER TRAVERSAL*********************/
int post_ind;
Node* constructTrees(vector<int>& postorder, vector<int>&inorder,int start, int end,  map<int,int>&mp){
          if(start>end){
              return NULL;
          }
           int val=postorder[post_ind];
           post_ind--;
           int ind= mp[val];
           Node* root= new Node(val);
             root->right=constructTrees(postorder,inorder,ind+1,end,mp);
           root->left=constructTrees(postorder,inorder,start,ind-1,mp);

           return root;
    }
Node* getTreeFromPostorderAndInorder(vector<int>& postorder, vector<int>& inorder) 
{
	// Write your code here.
     int n=inorder.size();
         map<int,int>mp;
         for(int i=0;i<n;i++){
             mp[inorder[i]]=i;
         }
        post_ind= n-1;
         return constructTrees(postorder, inorder, 0, n-1,mp);
}
/***********************SYMMETRICAL TREE***************************************************/
bool isSymmetric(Node* root)
{
      if(root==NULL|| (root->left==NULL&&root->right==NULL)){
          return true;
      }                       
       queue<Node *>q;
       q.push(root);
       vector<vector<int>>ans;
       while(q.size()>0){
              int n=q.size();
              vector<int>v;
              while(n--){
                  auto it=q.front();
                 Node* temp= it;
                  v.push_back(temp->data);
                  q.pop();
                  if(temp->left!=NULL){
                      q.push(temp->left);
                  }
                  if(temp->right!=NULL){
                      q.push(temp->right);
                  }
              }
             ans.push_back(v);
       }
       for(int i=0;i<ans.size();i++){
            // vector<int>v = ans[i];
            // reverse(v.begin(),v.end());
            int x= ans[i].size();
            for(int j=0;j<=(x/2);j++){
                if(ans[i][j]!=ans[i][x-1-j]){
                    return false;
                }
            }
       }
       return true;
}/******************************FLATTEN BINARY TREE TO LINKED LIST*************************************/
void preorder(Node* root,vector<int>&ans){
        if(root==NULL){
            return;
        }
        ans.push_back(root->data);
        preorder(root->left,ans);
        preorder(root->right,ans);
}
Node *flattenBinaryTree(Node *root)
{
      if(root==NULL){
            return NULL;
        }
        vector<int>ans;
        preorder(root,ans);
        // for(int i=0;i<ans.size();i++){
        //     cout<<ans[i]<<" ";
        // }
        // cout<<endl;
        Node* dummy= new Node(0);
        Node* head= dummy;
        for(int i=0;i<ans.size();i++){
             head->left==NULL;
             head->right= new Node(ans[i]);
             head=head->right;
        }
        return dummy->right;
}
/**********************************INVERT A BINARY TREE*******************************************/
bool storParents(Node *root, stack<Node *> &parents,
                 Node *leaf) {
  parents.push(root);

  if (!root->left and !root->right) {
    if (root->data == leaf->data)
      return true;
    else
      parents.pop();
    return false;
  }

  if (root->left) {
    if (storParents(root->left, parents, leaf))
      return true;
  }

  if (root->right) {
    if (storParents(root->right, parents, leaf))
      return true;
  }

  parents.pop();
  return false;
}
Node * invertBinaryTree(Node *root, Node *leaf)
{
	 if (!root)
    return NULL;

     stack<Node *> parents;
  storParents(root, parents, leaf);

  Node *head = parents.top();
  parents.pop();

  Node *par = head;
  while (!parents.empty()) {
    auto p = parents.top();
    parents.pop();

    if (p->right == head) {
      p->right = p->left;
      p->left = NULL;
    } else {
      p->left = NULL;
    }

    head->left = p;
    head = p;
  }

  return par;
}
/***************************CHILDREN SUM PROPERTY*************************************/
void changeTree(Node * root) {
    if(root==NULL){
        return;
    }
    int child=0;
    if(root->left!=NULL){
        child+= root->left->data;
    }
    if(root->right!=NULL){
        child+= root->right->data;
    }
    if(child>=root->data){
        root->data=child;
    }
    else{
    if(root->left!=NULL){
        root->left->data= root->data;
    } else if (root->right != NULL) {
      root->right->data = root->data;
    }
    }
    changeTree(root->left);
    changeTree(root->right);
    int ans=0;
    if(root->left){
        ans+=root->left->data;
    }
    if(root->right){
        ans+=root->right->data;
    }
    if(root->left||root->right){
        root->data=ans;
    }
}  
};