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
/***********FIND INTERSECTION NODE OF Y LINKED LIST*****************/
// Time Complexity: O(2max(N1,N2))+O(abs(N1-N2))+O(min(N1,N2))
// N1- length of list 1
// N2- length of list 2
// Space Complexity: O(1);
    Node *getIntersectionNode(Node *headA, Node *headB) {
        Node* head1= headA;
        Node* head2= headB;
        int c1=0,c2=0;
        while(head1!=NULL){
            c1++;
            head1=head1->next;
        }
        while(head2!=NULL){
            c2++;
            head2=head2->next;
        }
        int diff;
        if(c1>c2){
           diff=c1-c2;
           head1=headA;
           head2=headB;
        }
        else{
           diff=c2-c1;
           head1=headB;
           head2=headA;
        }
        for(int i=0;i<diff;i++){
            head1=head1->next;
        }
        while(head1!=head2){
            head1=head1->next;
            head2=head2->next;
            if(head1==NULL||head2==NULL){
                return NULL;
            }
        }
        return head1;
    }
/*****************DETECT A CYCLE IN THE LINKED LIST***************/
//Time Complexity: O(N)
//Space Complexity: O(1)
    bool hasCycle(Node *head) {
        Node* slow= head;
        Node* fast= head;
        while(fast!=NULL&&fast->next!=NULL&&fast->next->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow){
                return 1;
            }
        }
        return 0;
    }
/******************REVERSE A LINKED LIST IN GROUP OF SIZE K*************/
    bool length(Node* head, int k)
    {
        while(k!=0 && head!=NULL)
        {
            head = head->next;
            k--;
        }
        return k==0;
    }
    Node* reverseKGroup(Node* head, int k) {
        Node* prev=NULL;
        Node* curr=head;
        Node* next;
        Node* first=head;
        if(k==1){
            return head;
        }
        if(!length(head, k)) return head;
        
        int cnt=0;
        while(curr!=NULL&&cnt<k){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            cnt++;
        }
        head->next= reverseKGroup(curr,k);

        return prev;
    }
/***************CHECK IF LINKED LIST IS PALINDROME OR NOT**********/
//BRUTE FORCE APPROACH: reverse the complete linked list and then reitrate throught complete list
//Time Complexity: O(N)+O(N)
//Space Complexity: O(1)
//BETTER APPROACH
//Time Complexity: O(N/2)+O(N/2)+O(N/2)
//Space Complexity: O(1)
    Node* reverse(Node* head){
        Node* prev=NULL;
        Node* curr=head;
        Node* next=NULL;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    bool isPalindrome(Node* head) {
    if(head==NULL||head->next==NULL) return true;

        Node* slow=head;
        Node* fast=head;
        while(fast->next!=NULL&&fast->next->next!=NULL){
             slow=slow->next;
             fast=fast->next->next;
         }
         slow->next = reverse(slow->next);
         slow = slow->next;
         Node* temp = head;
        
        while(slow!=NULL) {
            if(temp->data != slow->data) return false;
                temp=temp->next;
                slow = slow->next;
        }
       return true;
    }
/****************FIND THE STARTING POINT OF THE LOOP OF LINKED LIST********/
//Time Complexity: O(N)
//Space Complexity: O(1)
    Node *detectCycle(Node *head) {
        if(head == NULL||head->next == NULL) return NULL;
        Node* slow= head;
        Node* fast=head;
        Node* temp=head;
        while(fast->next!=NULL&&fast->next->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow){
                while(slow!=temp){
                    slow=slow->next;
                    temp=temp->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};