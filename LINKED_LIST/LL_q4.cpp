#include<bits/stdc++.h>
using namespace std;
struct Node {
      int data;
      Node *next;
      Node(){
        data=0;
        next=NULL;
      }
      Node(int x){
        data=x;
        next=NULL;
      }
      Node(int x,  Node *next){
        data=x;
        next=next;
      }
 };
class Solution {
public:
/**********************ROTATE A LINKED LIST***********************/
// Time Complexity: O(N)+O(N- (N%k))
// Space Complexity: O(1)
 Node* rotateRight(Node* head, int k) {
        if(head == NULL||head->next == NULL||k == 0) return head;
        Node* temp=head;
        int cnt=0;
        while(temp!=NULL){
            temp=temp->next;
            cnt++;
        }
        Node* p=head;
         while(p->next!=NULL){
             p=p->next;
         }
         p->next=head;
         k=k%cnt;
         int len=cnt-k;
         int i=1;
         while(i<=len){
             p=p->next;
             i++;
         }
         head=p->next;
         p->next=NULL;
         return head;
    }
/******************************************************************/
};