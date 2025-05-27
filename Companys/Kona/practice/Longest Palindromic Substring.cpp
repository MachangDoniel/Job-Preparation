// Longest Palindromic Substring

// Link: https://leetcode.com/problems/longest-palindromic-substring/description/

// Given a string s, return the longest palindromic substring in s.

 

// Example 1:

// Input: s = "babad"
// Output: "bab"
// Explanation: "aba" is also a valid answer.
// Example 2:

// Input: s = "cbbd"
// Output: "bb"
 

// Constraints:

// 1 <= s.length <= 1000
// s consist of only digits and English letters.

#include<bits/stdc++.h>

using namespace std;



class Solution {
public:

    bool good(int num,string s){
        for(int i=0;i<=s.size()-num;i++){
            bool flag=true;
            for(int j=0;j<num/2;j++){
                if(s[i+j]!=s[i+num-j-1]){
                    flag=false;
                    break;
                }
            }
            if(flag) return true;
        }
        return false;
    }
    string longestPalindrome(string s) {
        int high=s.size()+1,low=-1;
        while(high>low+1){
            int mid=(high+low);
            if(good(mid,s)) low=mid;
            else high=mid;
        }
        cout<<"length: "<<low<<endl;
        string ss;
        for(int i=0;i<=s.size()-low;i++){
            bool flag=true;
            for(int j=0;j<low/2;j++){
                if(s[i+j]!=s[i+low-j-1]){
                    flag=false;
                    break;
                }
            }
            
            if(flag){
                for(int j=i;j<i+low;j++){
                    ss+=s[j];
                }
                break;
            }
        }
        return ss;
    }
};