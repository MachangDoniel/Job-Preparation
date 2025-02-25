/*
arrange all characters a-z in a cycle.
Distance between two characters is the minimum distance if we travel one character to another clockwise or anticlockwise.
example: 
distance from 'a' to 'c' is 2
distance from 'a' to 'z' is 1

distance between two strings of length n is the sum of character by character difference.

given a string S of size n and K.
find the lexicographically smallest string T of size n such that distance between S and T does not exceed K.

input:
    S = deft 
    K = 5
output: acft

input:
    S = qstd
    K = 1000

output: aaaa
*/

#include<bits/stdc++.h>

using namespace std;

int main(){
    string s; cin>>s;
    int k; cin>>k;
    string ans;
    for(int i=0;i<s.size();i++){
        if(k>0){
            ans+=s[i]-min(s[i]-'a',k);
            k-=min(s[i]-'a',k);
        }
        else ans+=s[i];
    }
    cout<<ans<<endl;
}