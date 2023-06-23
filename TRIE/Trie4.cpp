// Count distinct substring
#include<bits/stdc++.h>
using namespace std;
struct TrieNode{
     TrieNode *links[26];
     bool isWord=false;
     bool containsKey(char ch){
        return links[ch-'a']!=NULL;
     }
     void putIntoReferenceNode(char ch, TrieNode *newNode){
        links[ch-'a'] = newNode;
     }
     TrieNode *getReferenceNode(char ch){
        return links[ch-'a'];
     }
     void setEnd(){
        isWord=true;
     }
     bool getEnd(){
        return isWord;
     }
};
int countDistinctSubstrings(string &s)
{
  TrieNode * root = new TrieNode();
  int count = 0;
  int n = s.size();
  for (int i = 0; i < n; i++) {
    TrieNode * node = root;

    for (int j = i; j < n; j++) {
      if (node -> containsKey(s[j])==false) {
        TrieNode *newNode = new TrieNode();
        node -> putIntoReferenceNode(s[j], newNode);
        count++;
      }
      node = node -> getReferenceNode(s[j]);
    }

  }
  return count + 1;
}