#include<bits/stdc++.h>
using namespace std;
/**************************REVERSE WORD IN A STRING*****************************************/
// TC: O(N) , N => LENGTH OF STRING
// SC: O(N)
string reverseString(string &str){
	string ans="";
	string temp="";
	vector<string>v;
	for(int i=0;i<str.length();i++){
		if((str[i]>='a'&&str[i]<='z') || (str[i]>='A'&&str[i]<='Z')){
            temp+=str[i];
		}
		else{
			v.push_back(temp);
			temp="";
		}
	}	
	v.push_back(temp);
	reverse(v.begin(),v.end());
	for(int i=0;i<v.size()-1;i++){
		if(v[i].size()>0){
			ans+=v[i];
	    	ans+=" ";
		}
	}
	ans+=v[v.size()-1];
	return ans;
}
/****************************LONGEST PALINDROMIC SUBSTRING************************************************/
// TC: O(N^2)
string longestPalinSubstring(string s)
{
         int start=0;
         int end= 1;
         for(int i=1;i<s.length();i++){
             int low=i-1;
             int high=i;
             while(low>=0&&high<s.length()&&s[low]==s[high]){
                 if(high-low+1>end){
                     start=low;
                     end=high-low+1;
                 }
                 low--;
                 high++;
             }
             low=i-1;
             high=i+1;
             while(low>=0&&high<s.length()&&s[low]==s[high]){
                 if(high-low+1>end){
                     start=low;
                     end=high-low+1;
                 }
                 low--;
                 high++;
             }

         }
         return s.substr(start,end);
    
}
/************************ROMAN NUMERAL TO INTEGRAL**********************************************/
//TC: O(n)
int romanToInt(string str) {
    unordered_map<char,int> mp;
    mp['I'] = 1;
    mp['V'] = 5;
    mp['X'] = 10;
    mp['L'] = 50;
    mp['C'] = 100;
    mp['D'] = 500;
    mp['M'] = 1000;
    int ans=0;
    for(int i=0; i < str.length();i++){
        if(mp[str[i]] < mp[str[i+1]]){
            ans-=mp[str[i]];
        }
        else{
            ans+=mp[str[i]];
        }
    }
    return ans;
}
/***********************************IMPLEMENT ATOI FUNCTION******************************************/
// TC: O(N)
int atoi(string str) {
 bool negative=false;
        int ans;
       for(int i=0;i<str.length();i++){
           if(i==0&&str[i]==45){
               negative=true;
               continue;
           }
           if(str[i]>='0'&&str[i]<='9'){
               if(i==0){
                   ans= str[i]-48;
               }
               else{
                   ans=ans*10+ (str[i]-48);
               }
           }
           else{
               return -1;
           }
       }
       if(negative==true){
           ans=0-ans;
       }
       return ans;
}
/****************************LONGEST COMMON PREFIX*************************************/
//TC: O(nlogn+k)
string longestCommonPrefix(vector<string> &strs, int n)
{
      sort(strs.begin(),strs.end());
        string s=strs[0],m=strs[n-1],ans="";
        for(int i=0;i<s.size();i++){
            if(s[i]==m[i]){
                ans+=s[i];
            }
            else break;
        }
        return ans;
}
/********************************SEARCH PATTERN (RABIN KARP ALGORITHM)******************************/
// BRUTE FORCE: 
// TC:   O((n - pat.size()) * m)
vector<int> stringMatch(string &str, string &pat) {
    int ind;
    ind= str.find(pat);
    vector<int>ans;
    if(ind!=-1){
        ans.push_back(ind);
        str[ind]='1';
        for(int i=0;i<=str.length()-pat.size();i++){
             if(str.find(pat)!=-1){
                 ans.push_back(str.find(pat));
                 str[str.find(pat)]='1';
             }
        }
    }
    return ans;
}
