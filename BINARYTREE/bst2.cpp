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
/*******************************FLOOR IN A BST********************************/
void helper(Node * root, int X,int &mini){
    if(root->data==X||root->data>mini&&root->data<X){
        mini=root->data;
    }
    if(root->data>X&&root->left!=NULL){
        helper(root->left,X,mini);
    }
    if(root->data<X&&root->right!=NULL){
        helper(root->right,X,mini);
    }
}
int floorInBST(Node * root, int X)
{
    if(root==NULL){
        return 0;
    }
    Node *temp=root;
    int mini=INT_MIN;
    helper(root,X,mini);
    return mini;
}
/********************************CEIL FROM BST *********************************/
void helper_Ceil(Node *root, int X,int &maxi){
    if(root->data==X||root->data>X&&root->data<maxi){
        maxi=root->data;
    }
    if(root->data>X&&root->left!=NULL){
        helper_Ceil(root->left,X,maxi);
    }
    if(root->data<X&&root->right!=NULL){
        helper_Ceil(root->right,X,maxi);
    }
}
int findCeil(Node *node, int x){
    if(node==NULL){
        return 0;
    }
    int maxi=INT_MAX;
    helper_Ceil(node,x,maxi);
    if(maxi==INT_MAX){
        maxi=-1;
    }
    return maxi;
}
/**********************FIND Kth SMALLEST ELEMENT IN BST***********************/
int kthSmallest(Node *root, int k)
{
	    vector<int>mini;
        queue<Node *>q;
        q.push(root);
        while(q.size()>0){
            int n=q.size();
            while(n--){
            auto it=q.front();
            q.pop();
            mini.push_back(it->data);
             if(it->left!=NULL){
                 q.push(it->left);
             }
             if(it->right!=NULL){
                 q.push(it->right);
             }
            }
        }
        sort(mini.begin(),mini.end());
        return mini[k-1];
}
/********************FIND Kth LARGEST ELEMENT IN A BST**********************/
int KthLargestNumber(Node* root, int k) 
{
     vector<int>maxi;
        queue<Node *>q;
        q.push(root);
        while(q.size()>0){
            int n=q.size();
            while(n--){
            auto it=q.front();
            q.pop();
            maxi.push_back(it->data);
             if(it->left!=NULL){
                 q.push(it->left);
             }
             if(it->right!=NULL){
                 q.push(it->right);
             }
            }
        }
        sort(maxi.begin(),maxi.end());
        if(k>maxi.size()){
            return -1;
        }
   
       return maxi[maxi.size()-k];
}
/*************************FIND PAIR WITH GIVEN SUM IN BST*************************************/
bool pairSumBst(Node *root, int k)
{
        vector<int>v;
        queue<Node *>q;
        q.push(root);
        while(q.size()>0){
            int n=q.size();
            while(n--){
            auto it=q.front();
            q.pop();
            v.push_back(it->data);
             if(it->left!=NULL){
                 q.push(it->left);
             }
             if(it->right!=NULL){
                 q.push(it->right);
             }
            }
        }
        sort(v.begin(),v.end());
        int i=0,j=v.size()-1;
        while(i<j){
            if(v[i]+v[j]==k){
                return true;
            }
            else if(v[i]+v[j]>k){
                j--;
            }
            else if(v[i]+v[j]<k){
                i++;
            }
        }
        return false;
}
/*****************************BST ITERATOR********************************/
class BSTiterator
{  public:
    vector<int>ans;
    int i;
    BSTiterator(Node *root) {
        inorder(root,ans);
        i=0;
    }
     void inorder(Node *root,vector<int>&ans){
        if(root==NULL){
            return;
        }
        inorder(root->left,ans);
        ans.push_back(root->data);
        i++;
        inorder(root->right,ans);
    }
    int next() {
         if(i<ans.size()){
            return ans[i++];
        }
    }
    bool hasNext(){
          if(i<ans.size()){
            return true;
           }
        return false;
    }
};
/**********************SIZE OF LARGEST BST IN A BINARY TREE**************************************/
class NodeValue{
    public:
    int maxNode, minNode, maxSize;
    
    NodeValue(int minNode, int maxNode, int maxSize) {
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->maxSize = maxSize;
    }
};
NodeValue largestBSTSubtreeHelper(Node* root) {
        if (!root) {
            return NodeValue(INT_MAX, INT_MIN, 0);
        }
        auto left = largestBSTSubtreeHelper(root->left);
        auto right = largestBSTSubtreeHelper(root->right);
        
        if (left.maxNode < root->data && root->data < right.minNode) {
            return NodeValue(min(root->data, left.minNode), max(root->data, right.maxNode), 
                            left.maxSize + right.maxSize + 1);
        }
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
    }
int largestBST(Node* root) 
{
     return largestBSTSubtreeHelper(root).maxSize;
}
/********************SERIALIZE AND DESERIALIZE BINARY TREE************************************/
string serializeTree(Node *root)
{
   string s="";
         if(root==NULL){
             return s;
         }
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
           Node* curNode = q.front();
           q.pop();
           if(curNode==NULL) s.append("#,");
           else s.append(to_string(curNode->data)+',');
           if(curNode != NULL){
               q.push(curNode->left);
               q.push(curNode->right);            
           }
        }
        return s;

}

Node* deserializeTree(string &data)
{
       if(data.size()==0){
            return NULL;
        }
        stringstream s(data);
        string str; 
        getline(s, str, ',');
        Node* root= new Node(stoi(str));
       queue<Node*> q; 
        q.push(root); 
        while(!q.empty()) {
            
            Node *node = q.front(); 
            q.pop(); 
            
            getline(s, str, ',');
            if(str == "#") {
                node->left = NULL; 
            }
            else {
                Node* leftNode = new Node(stoi(str)); 
                node->left = leftNode; 
                q.push(leftNode); 
            }
            
            getline(s, str, ',');
            if(str == "#") {
                node->right = NULL; 
            }
            else {
                Node* rightNode = new Node(stoi(str)); 
                node->right = rightNode;
                q.push(rightNode); 
            }
        }
        return root; 

}
};