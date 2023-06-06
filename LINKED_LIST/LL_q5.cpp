#include<bits/stdc++.h>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
class Solution {
public:
/**********CLONE LINKED LIST WITH RANDOM AND NEXT POINTER*************/
// BRUTE FORCE APPROACH: 
// IDEA: create a unordered_map which store copy of real node so that we can further iterate and use it.
// Time Complexity: O(N)+O(N)
// Space Complexity: O(N) 
Node *cloneRandomList(Node *head){
    unordered_map<Node*,Node*>mp;
    Node *temp=head;
    while(temp!=NULL){
        Node *newNode = new Node (temp->val);
        mp[temp]=newNode;
        temp=temp->next;
    }
    Node *t= head;
    while(t!=NULL){
        Node *newN = mp[t];
        if(t->next!=NULL){
            newN->next=mp[t->next];
        }
        else{
            newN->next=NULL;
        }
        if(t->random!=NULL){
            newN->random=mp[t->random];
        }
        else{
            newN->random=NULL;
        }
        t=t->next;
    }
    return mp[head];
}
/*************************************************************************/
// BETTER APPROACH
// IDEA: first, insert a node (which is copy of previous node) between every two node
// Secondly,iterate through the list and point the random pointer of inserted node to 
// the next of random pointer of previous node
// at last point the next pointer 
// Time Complexity: O(N)+O(N)+O(N)
// Space Complexity: O(1)
Node* copyRandomList(Node* head) {
    Node* temp=head;
    while(temp!=NULL){
        Node* newNode= new Node(temp->val);
        newNode->next=temp->next;
        temp->next=newNode;
        temp=temp->next->next;
    }
    Node* t=head;
    while(t!=NULL){
        if(t->random!=NULL){
        t->next->random= t->random->next;
        }
        t=t->next->next;
    }
    Node* ans= new Node(0);
    t=head;
    temp=ans;
    Node* fast;
    while(t!=NULL){
        fast=t->next->next;
        temp->next=t->next;
        t->next=t->next->next;
        temp=temp->next;
        t=fast;
    }
    return ans->next;
}
};