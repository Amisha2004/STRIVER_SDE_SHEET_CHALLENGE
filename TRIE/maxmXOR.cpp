#include <bits/stdc++.h> 
using namespace std;
struct Node {
  Node * links[2];
 
  bool containsKey(int ind) {
    return (links[ind] != NULL);
  }
  Node * get(int ind) {
    return links[ind];
  }
  void put(int ind, Node * node) {
    links[ind] = node;
  }
};
/****************************Maximum XOR of Two Numbers in an Array*********************************************/
class Trie {
  private: Node * root;
  public:
    Trie() {
      root = new Node();
    }
 
  public:
    void insert(int num) {
      Node * node = root;
      // cout << num << endl; 
      for (int i = 31; i >= 0; i--) {
        int bit = (num >> i) & 1;
        if (!node -> containsKey(bit)) {
          node -> put(bit, new Node());
        }
        node = node -> get(bit);
      }
    }
  public:
    int findMax(int num) {
      Node * node = root;
      int maxNum = 0;
      for (int i = 31; i >= 0; i--) {
        int bit = (num >> i) & 1;
        if (node -> containsKey(!bit)) {
          maxNum = maxNum | (1 << i);
          node = node -> get(!bit);
        } else {
          node = node -> get(bit);
        }
      }
      return maxNum;
    }
};
// class Solution {
// public:

    int maximumXor(vector<int>& nums) {
        Trie trie;
        int n=nums.size();
  for (int i = 0; i < n; i++) {
    trie.insert(nums[i]);
  }
  int maxi = 0;
  for (int i = 0; i < n; i++) {
    maxi = max(maxi, trie.findMax(nums[i]));
  }
  return maxi;
    }
// };
/********************Maximum XOR With an Element From Array******************************/
vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
	   int n = arr.size();
  int m = queries.size();
  vector < int > ans(m, -1);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (arr[j] <= queries[i][1]) {
        ans[i] = max(ans[i], arr[j] ^ queries[i][0]);
      }
    }
  }
  return ans;
}