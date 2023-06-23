#include<bits/stdc++.h>
using namespace std;
struct TrieNode{
      TrieNode* links[26];
      bool isWord= false;
      bool containsKey(char ch){
          return links[ch-'a']!=NULL;
      }
      void putIntoReferenceNode(char ch,TrieNode* newNode){
          links[ch-'a']= newNode;
      }
      TrieNode* getReferenceNode(char ch){
           return links[ch-'a'];
      }
      void setEnd(){
          isWord=true;
      }
      bool getEnd(){
          return isWord;
      }
};

class Trie {
private: 
    TrieNode* root;
public:
    Trie() {
       root= new TrieNode();
    }
    void insert(string word) {
        TrieNode* temp=root;
        for(int i=0;i<word.length();i++){
            if(temp->containsKey(word[i])==false){
                TrieNode* newNode = new TrieNode();
                temp->putIntoReferenceNode(word[i],newNode);
            }
            temp=temp->getReferenceNode(word[i]);
        }
        temp->setEnd();
    }
    bool search(string word) {
          TrieNode* temp=root;
        for(int i=0;i<word.length();i++){
            if(temp->containsKey(word[i])==false){
                return false;
            }
            temp=temp->getReferenceNode(word[i]);
        }
        return temp->getEnd();
    }
    bool startsWith(string prefix) {
          TrieNode* temp=root;
        for(int i=0;i<prefix.length();i++){
            if(temp->containsKey(prefix[i])==false){
                return false;
            }
            temp=temp->getReferenceNode(prefix[i]);
        }
        return true;
    }
};