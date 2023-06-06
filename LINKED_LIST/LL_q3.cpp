#include<bits/stdc++.h>
using namespace std;
struct Node {
      int data;
      Node *next;
      Node *bottom;
      Node(){
        data=0;
        next=NULL;
        bottom=NULL;
      }
      Node(int x){
        data=x;
        next=NULL;
        bottom=NULL;
      }
      Node(int x,  Node *next){
        data=x;
        next=next;
      }
 };
class Solution {
public:
/****************FLATTENING OF LINKED LIST**************/
// Time Complexity: O(Number of nodes present)
// Space Complexity: O(1)
    Node *mergeTwoList(Node* l1, Node* l2){
        Node* temp= new Node(0);
        Node* res=temp;
        while(l1!=NULL&&l2!=NULL){
            if(l1->data<l2->data){
               temp->bottom=l1;
               temp=temp->bottom;
               l1=l1->bottom;
            }
            else{
               temp->bottom=l2;
               temp=temp->bottom;
               l2=l2->bottom;
            }
        }
        if(l1!=NULL){
            temp->bottom=l1;
        }
        else{
            temp->bottom=l2;
        }
      return res->bottom;
   }
    Node *flatten(Node *root){  
        if(root==NULL||root->next==NULL){
            return root;
        }
        Node *down= root;
        Node *right = root->next;
        right= flatten(right);
        down->next= NULL;
        Node *ans=mergeTwoList(down,right);

      return ans;
    }
/*****************************************************/

};