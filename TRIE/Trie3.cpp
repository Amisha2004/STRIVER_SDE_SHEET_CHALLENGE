//Complete string problem
#include <bits/stdc++.h> 
using namespace std;
struct TrieNode{
     TrieNode *links[26];
     bool isWord=false;
     bool containsKey(char ch){
        return (links[ch-'a']!=NULL);
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
class Trie{
private: TrieNode* root;
public: 
     Trie(){
        root= new TrieNode();
     }
    void insert(string word){
        TrieNode* temp=root;
        for(int i=0;i<word.length();i++){
            if(temp->containsKey(word[i])==false){
                TrieNode *newNode= new TrieNode();
                temp->putIntoReferenceNode(word[i],newNode);
            }
            temp=temp->getReferenceNode(word[i]);
        }
        temp->setEnd();
    }
public:
    bool checkIfPrefixExists(string word){
        bool flag=true;
        TrieNode* temp=root;
        for(int i=0;i<word.length();i++){
            if(temp->containsKey(word[i])){
               temp=temp->getReferenceNode(word[i]);
               if(temp->getEnd()==false){
                   return false;
               }
            }
            else {
              return false;
            }
        }
        return flag;
    }
   
};
string completeString(int n, vector<string> &a){
    Trie trie;
    for(auto &it: a){
        trie.insert(it);
    }
    string ans="";
    // cout<<trie.checkIfPrefixExists("ninja")<<endl;
    for(auto &it : a){
        // cout<<it<<endl;
        if(trie.checkIfPrefixExists(it)){
            if(it.length()>ans.length()){
                ans=it;
            }
            else if(it.length()==ans.length() && it< ans){
                ans=it;
            }
        }
    }
    if(ans==""){
        return "None";
    } else {
      return ans;
    }
}
