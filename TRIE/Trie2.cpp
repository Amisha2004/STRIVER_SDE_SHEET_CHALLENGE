#include <bits/stdc++.h> 
using namespace std;
struct TrieNode{
    TrieNode *links[26];
    int cntWord=0;
    int cntPrefix=0;
    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    void putIntoReferenceNode(char ch, TrieNode* newNode){
        links[ch-'a']= newNode;
    }
    TrieNode *getReferenceNode(char ch){
        return links[ch-'a'];
    }
    void increasecntword(){
          cntWord++;
    }
    void increasecntprefix(){
          cntPrefix++;
    }
    void reducecntWord(){
        cntWord--;
    }
    void reducecntPrefix(){
         cntPrefix--;
    }
    int getwordCount(){
        return cntWord;
    }
    int getPrefixCount(){
        return cntPrefix;
    }
};
class Trie{
    private: 
        TrieNode *root;
    public:

    Trie(){
        root= new TrieNode();
    }

    void insert(string &word){
        TrieNode *temp=root;
        for(int i=0;i<word.length();i++){
            if(temp->containsKey(word[i])==false){
                TrieNode* newNode= new TrieNode();
                temp->putIntoReferenceNode(word[i], newNode);
            }
            temp=temp->getReferenceNode(word[i]);
            temp->increasecntprefix();
        }
        temp->increasecntword();
    }

    int countWordsEqualTo(string &word){
        TrieNode *temp=root;
        for(int i=0;i<word.length();i++){
            if(temp->containsKey(word[i])==false){
                return 0;
            }
            temp=temp->getReferenceNode(word[i]);
        }
        return temp->getwordCount();
    }

    int countWordsStartingWith(string &word){
         TrieNode *temp=root;
        for(int i=0;i<word.length();i++){
            if(temp->containsKey(word[i])==false){
                return 0;
            }
            temp=temp->getReferenceNode(word[i]);
        }
        return temp->getPrefixCount();
    }

    void erase(string &word){
        TrieNode *temp=root;
        for(int i=0;i<word.length();i++){
            if(temp->containsKey(word[i])==true){
                 temp=temp->getReferenceNode(word[i]);
                 temp->reducecntPrefix();
            }
            else{
                return;
            }
           
        }
        temp->reducecntWord();
    }
};
