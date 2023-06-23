#include <bits/stdc++.h> 
using namespace std;
/*************************TRAVERSAL OF BINARY TREE**********************************************/
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
    // INORDER TRAVERSAL
void helper_inorder(Node* root, vector<int>&ans){
        if(root==NULL){
            return;
        }
        helper_inorder(root->left,ans);
        ans.push_back(root->data);
        helper_inorder(root->right,ans);
}
    // PREORDER TRAVERSAL
void helper_preorder(Node* root, vector<int>&ans){
        if(root==NULL){
            return;
        }
        ans.push_back(root->data);
        helper_preorder(root->left,ans);
        helper_preorder(root->right,ans);
}
    // POSTORDER TRAVERSAL
void helper_postorder(Node* root, vector<int>&ans){
        if(root==NULL){
            return;
        }
        helper_postorder(root->left,ans);
        helper_postorder(root->right,ans);
        ans.push_back(root->data);
}
vector<vector<int>> getTreeTraversal(Node *root){
     vector<vector<int>>ans;
     vector<int>v;
     helper_inorder(root, v);
     ans.push_back(v);
     v.clear();
     helper_preorder(root, v);
     ans.push_back(v);
     v.clear();
     helper_postorder(root, v);
     ans.push_back(v);
     return ans;
}
/******************************MORRIS INORDER TRAVERSAL*****************************************/
vector < int > morrisinorderTraversal(Node * root) {
  vector < int > ans;

  Node * curr = root;
  while (curr != NULL) {
    if (curr -> left == NULL) {
      ans.push_back(curr -> data);
      curr = curr -> right;
    } else {
      Node * prev = curr -> left;
      while (prev -> right != NULL && prev -> right != curr) {
        prev = prev -> right;
      }

      if (prev -> right == NULL) {
        prev -> right = curr;
        curr = curr -> left;
      } else {
        prev -> right = NULL;
        ans.push_back(curr -> data);
        curr = curr -> right;
      }
    }
  }
  return ans;
}
/***************************MORRIS PREORDER TRAVERSAL*******************************************/
vector < int > morrispreorderTraversal(Node * root) {
  vector < int > ans;

  Node * curr = root;
  while (curr != NULL) {
    if (curr -> left == NULL) {
      ans.push_back(curr -> data);
      curr = curr -> right;
    } else {
      Node * prev = curr -> left;
      while (prev -> right != NULL && prev -> right != curr) {
        prev = prev -> right;
      }

      if (prev -> right == NULL) {
        prev -> right = curr;
        ans.push_back(curr -> data);
        curr = curr -> left;
      } else {
        prev -> right = NULL;
        curr = curr -> right;
      }
    }
  }
  return ans;
}
};