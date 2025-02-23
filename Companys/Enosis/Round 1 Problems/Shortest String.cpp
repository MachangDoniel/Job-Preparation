/*
Given a string S, output the length of shortest possible string of whose anagram can be added to create the given string. 

Constraints: 
1<=size(S)<=1e5

Sample Input: abccbacababc
Sample Ouput: 3

[abc]+[cba]+[cab]+[abc] : each part is a anagram of "abc". 
*/

#include <bits/stdc++.h>

using namespace std;


// Approach:
// 1. Find all the divisors of the length of the string & sort them.
// 2. For each divisor, check if the string can be divided into parts of that length such that each part is an anagram of the other.
// 3. If such a divisor is found, output the divisor and break.
// Total Time complexity O(n*sqrt(n))

vector<int> getDivisor(int n){
    vector<int>div;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            if(i!=n/i){
                div.push_back(i);
                div.push_back(n/i);
            }
            else{
                div.push_back(i);
            }
        }
    }
    return div;
}

bool check(string s,int len){
    int n=s.size();
    map<char,int>target;
    for(int i=0;i<len;i++){
        target[s[i]]++;
    }
    for(int i=len;i<n;i+=len){
        map<char,int>temp;
        for(int j=i;j<i+len;j++){
            temp[s[j]]++;
        }
        if(target!=temp){
            return false;
        }
    }
    return true;
}

int main(){
    string s; cin>>s;
    int n=s.size();
    // max n=10^5, max div.size()=128 (n=10^5)
    vector<int>div=getDivisor(n);
    sort(div.begin(),div.end());
    for(int i=0;i<div.size();i++){
        if(check(s,div[i])){
            cout<<div[i]<<endl;
            break;
        }
    }
    return 0;
}