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
/************REVERSE A LINKED LIST***************/
// Time Complexity: O(N)
// Space Complexity: O(1)
    Node* reverseList(Node* head) {
        Node* prev=NULL;
        Node* curr=head;
        Node* next;
        while(curr!=NULL){
          next=curr->next;
          curr->next=prev;
          prev=curr;
          curr=next;
       }
        return prev;
    }
/******************************************************/
/********FIND MIDDLE ELEMENT IN A LINKED LIST*********/
// Time Complexity: O(N)
// Space Complexity: O(1)
    Node* middleNode(Node* head) {
        if(head==NULL) return NULL;
       Node* slow=head;
       Node* fast=head;
       while(fast!=NULL&&fast->next!=NULL){
           fast=fast->next->next;
           slow=slow->next;
       }
       return slow;
    }
/***********************************************************/
/********MERGE TWO SORTED LINKED LIST IN SORTED ORDER*******/
    Node* mergeTwoLists(Node* list1, Node* list2) {
         Node *newNode= new Node();
         Node *temp = newNode;
        
        while (list1!=NULL && list2!=NULL) {
            if (list1->data < list2->data) {
                temp->next = list1;
                list1 = list1->next;
            } 
            else {
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }
        if(list1!=NULL){
            temp->next= list1;
        }
        else{
            temp->next= list2;
        }
        temp= newNode->next;
        delete newNode;
        return temp;
    }
/*************************************************************************/
/*********REMOVE Nth NODE FROM THE BACK OF THE LINKED LIST***************/
    Node* removeNthFromEnd(Node* head, int n) {
         Node* start = new Node();
         start -> next = head;
         Node* p = start;
         Node* q = start;
        int i=1;
        while(i<=n){
            p=p->next;
            i++;
        }
        while(p!=NULL&&p->next!=NULL){
            p=p->next;
            q=q->next;
        }
        q->next=q->next->next;
        return start->next;
    }
/***************************************************************/
/************ADD TWO NUMBERS AS A LINKED LIST******************/
    Node* addTwoNumbers(Node* l1, Node* l2) {
        Node *newNode = new Node(); 
        Node *temp = newNode; 
        int carry = 0;
        while( (l1 != NULL || l2 != NULL) || carry!=0) {
            int sum = 0; 
            if(l1 != NULL) {
                sum += l1->data; 
                l1 = l1 -> next; 
            }
            if(l2 != NULL) {
                sum += l2 -> data; 
                l2 = l2 -> next; 
            }
            sum += carry; 
            carry = sum / 10; 
            Node *node = new Node(sum % 10); 
            temp -> next = node; 
            temp = temp -> next; 
        }
        temp=newNode -> next;
        return temp; 
    }
/******************DELETE A GIVEN NODE*********************/
    void deleteNode(Node* node) {
        *node = *node ->next;
    }
/***********************************************************/
};