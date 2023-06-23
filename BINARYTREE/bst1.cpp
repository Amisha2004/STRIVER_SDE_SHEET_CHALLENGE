
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
/*****************CONNECT NODES AT SAME LEVEL****************************************/
void connectNodes(Node *root) {
   if(root==NULL){
            return;
        } 
        queue<Node*>q;
        q.push(root);
        while(q.size()>0){
            int n= q.size();
            while(n--){
                Node* temp= q.front();
                q.pop();
                if(n==0){
                    temp->next=NULL;
                }
                else{
                   Node* prev=q.front();
                   temp->next=prev;
                }
                if(temp->left!=NULL){
                    q.push(temp->left);
                }
                if(temp->right!=NULL){
                    q.push(temp->right);
                }
            }
        }
}
/******************************SEARCH IN BST*************************************/
Node* searchBST(Node* root, int val) {
        if(root==NULL){
            return NULL;
        }
        if(root->data==val){
            return root;
        }
        if(root->data>val){
            return searchBST(root->left,val);
        }
        if(root->data<val){
            return searchBST(root->right,val);
        }
        return NULL;
}
/*******************************CONSTRUCT BST FROM GIVEN KEYS*******************/
Node* maker(vector<int>& v, int low , int high){
        if(low > high){
            return{};
        }
        if(low<=high){
        int mid = low +(high-low)/2;
        Node* root = new Node(v[mid]);
        root->left = maker(v,low,mid-1);
        root->right = maker(v,mid+1,high);
        return root;
        }
        return NULL;
    }
Node* sortedArrToBST(vector<int> &nums, int n)
{
        return maker(nums,0,n-1);
}
/********************CONSTRUCT A BST FROM PREORDER TRAVERSAL**********************/
Node * solve(vector<int>& preorder,long mini,long maxi, int &i){
        if(i>=preorder.size()){
            return NULL;
        }
        if(preorder[i]<mini||preorder[i]>maxi){
            return NULL;
        }
        Node * newnode = new Node (preorder[i++]);
        newnode->left = solve(preorder,mini,newnode->data,i);
        newnode->right = solve(preorder,newnode->data,maxi,i);
        return newnode ; 
   }
Node* preOrderTree(vector<int> &preorder){
         int i=0;
         long mini = LONG_MIN;
         long maxi  = LONG_MAX ;
         return solve(preorder,mini,maxi,i);
}
/**********************CHECK A BT IS BST OR NOT**********************************/
bool isPossible(Node * root, long long l, long long r){
    if(root == nullptr)  return true;
    if(root->data < r and root->data > l)
        return isPossible(root->left, l, root->data) &&
                                isPossible(root->right, root->data, r);
    else return false;
    }
    bool validateBST(Node *root) {
        long long int min = -1000000000000, max = 1000000000000;
          return isPossible(root, min, max);
    }
/**********************LCA OF TWO NODES IN A BST********************************/
Node* LCAinaBST(Node* root, Node* p, Node* q)
{
	  int current = root->data;
        if(p->data < current && q->data < current) {
            return LCAinaBST(root->left, p, q);
        }
        else if(p->data > current && q->data > current) {
            return LCAinaBST(root->right, p, q);
        }
        else{
            return root;
        }
}
/***********************PREDECESSOR AND SUCCESSOR IN A BST*******************/
void solve(Node* root,int key,int &pred, int &succ){
    if(root==NULL){
        return;
    }
    solve(root->left,key,pred,succ);
    if(root->data<key)
        {
            pred=root->data;
        }
    if(root->data>key and succ==-1)
        {
            succ=root->data;
        }
    solve(root->right,key,pred,succ);
}
pair<int,int> predecessorSuccessor(Node* root, int key)
{     
      int pred=-1;
      int succ=-1;
      if(root==NULL){
          return {-1,-1};
      }
      solve(root,key,pred,succ);
      return {pred,succ};

    //   return {-1,-1};
}

};