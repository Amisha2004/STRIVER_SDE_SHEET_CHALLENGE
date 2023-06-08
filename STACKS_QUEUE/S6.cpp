#include<bits/stdc++.h>
using namespace std;
// LRU Cache
// TC: O(N)
// SC: O(1)
class LRUCache {
public:
    class Node {
      public:
        int key;
      int val;
      Node * next;
      Node * prev;
      Node(int _key, int _val) {
        key = _key;
        val = _val;
      }
    };
    Node * head = new Node(-1, -1);
    Node * tail = new Node(-1, -1);
    int cap;
    unordered_map < int, Node * > mp;
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    void insertNode(Node * newNode){
       Node* temp= head->next;
       newNode->next=temp;
       newNode -> prev = head;
       head -> next = newNode;
       temp -> prev = newNode;
    }
    void deleteNode(Node * node){
        Node* temp1=node->next;
        Node* temp2=node->prev;
        temp2->next=temp1;
        temp1->prev=temp2;
    }
    int get(int _key) {
           if (mp.find(_key) != mp.end()) {
                Node * node = mp[_key];
                int ans = node -> val;
                mp.erase(_key);
                deleteNode(node);
                insertNode(node);
                mp[_key] = head -> next;
           return ans;
          }
        return -1;
}
    
    void put(int _key, int value) {
         if(mp.find(_key)!=mp.end()){
             Node* existing_Node = mp[_key];
             mp.erase(_key);
             deleteNode(existing_Node);
         }
         if(mp.size()==cap){
             mp.erase(tail->prev->key);
             deleteNode(tail->prev);
         }
         insertNode(new Node(_key,value));
         mp[_key]=head->next;
    }
};
