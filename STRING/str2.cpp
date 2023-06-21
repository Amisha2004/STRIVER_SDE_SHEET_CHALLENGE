#include<bits/stdc++.h>
using namespace std;
/**************************Z ALGORITHM***************************************/
// TC: O(n * m)
int zAlgorithm(string s, string p, int n, int m)
{
	int count = 0;
    for(int i=0;i<n;i++){
        if(s[i]==p[0]){
            if(s.substr(i,m)==p){
                count++;
            }
        }
    }
    return count;
}
/*********************FIND PATTERN IN STRING (KMP ALGORITHM)******************************/
//TC: O(N)
bool findPattern(string p, string s)
{
    int ind= s.find(p);
    // cout<<ind<<endl;
    if(ind!=-1){
        return 1;
    }
    return 0;
}
/****************************MINIMUM CHARACTERS FOR PALINDROME********************************/
// TC: O(N)
int minCharsforPalindrome(string str) {
	int n=str.length();
	int low=0;
	int high=n-1;
	int x=high;
	int cnt=0;
	// aabaaca
	// low=1 a
	// high=n-2 c
	while(low<high){
		if(str[low]==str[high]){
			low++;
			high--;
		}
		else{
			cnt++;
			low=0;
			x--;
			high=x;
		}
	}
	return cnt;
}
/******************************CHECK FOR ANAGRAMS*******************************************************/
//TC: O(s + t + max(s, t))
// t is length of string t and s is length of string s
bool areAnagram(string &s, string &t){
    unordered_map<char,int>mp1,mp2;
        for(int i=0;i<s.length();i++){
            mp1[s[i]]++;
        }
        for(int i=0;i<t.length();i++){
            mp2[t[i]]++;
        }
        // for(auto it: mp2){
        //     cout<<it.first<<endl;
        // }
        int cnt=0;
        if(s.length()>=t.length()){
        for(auto it: mp1){
            // cout<<it.first<<endl;
              if(mp2.find(it.first)!=mp2.end()){
                //   cout<<mp2[it.first]<<" "<<it.second<<endl;
                  if(mp2[it.first]==it.second){
                      cnt++;
                  }
              }
         }
         if(cnt==mp1.size()){
            return true;
        }
        else{
            return false;
        }
        }
        else{
              for(auto it: mp2){
            // cout<<it.first<<endl;
              if(mp1.find(it.first)!=mp1.end()){
                //   cout<<mp1[it.first]<<" "<<it.second<<endl;
                  if(mp1[it.first]==it.second){
                      cnt++;
                  }
              }
         }
        //  cout<<mp2.size()<<endl;
         if(cnt==mp2.size()){
            return true;
        }
        else{
            return false;
        }
        }
}
/***************************COUNT AND SAY***********************************/
// TC: exponential
string writeAsYouSpeak(int n) 
{
	if(n==1){
		return "1";
	}	
	if(n==2){
		return "11";
	}
	string s="11";
	for(int i=3;i<=n;i++){
		string t="";
		s=s+'$';
		int ct=1;
		for(int j=1;j<s.length();j++){
			if(s[j]==s[j-1]){
				ct++;
			}
			else{
				t=t+ to_string(ct);
				t=t+ s[j-1];
				ct=1;
			}
		}
		s=t;
	}
	return s;
}
/**************************COMPARE VERSION NUMBER*****************************************/
int compareVersions(string a, string b) 
{
     int n = a.size(), m = b.size();
    int i = 0, j = 0;
    while(i < n or j < m) {
        if(a[i] == '0') 
            while(i < n and a[i] == '0') i++;

        if(b[j] == '0')
            while(j < m and b[j] == '0') j++;

        long long num1 = 0, num2 = 0;

        while(i < n and a[i] != '.') 
            num1 = (num1 * 10) + (a[i++] - '0');

        while(j < m and b[j] != '.')  
            num2 = (num2 * 10) + (b[j++] - '0');

        if(num1 > num2) return 1;
        else if(num1 < num2) return -1;

        i++, j++;
    }

    return 0;
}