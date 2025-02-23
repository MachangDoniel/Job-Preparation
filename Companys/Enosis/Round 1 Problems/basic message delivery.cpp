/*
A basic message delivery service is to be implemented that has a rate-limiting algorithm that drops any message that has already been delivered in the last k seconds.

Given the integer k, a list of messages as an array of n strings, messages, and a sorted integer array timestamps representing the time at which the message arrived, for each message report the string "true" if the message is delivered and "false" otherwise.

Example:

Suppose n = 6, timestamps = [1, 4, 5, 10, 11, 14], messages = ["hello", "bye", "bye", "hello", "bye", "hello"], and k=5.
output: true true false true true false 

link: https://www.coursesidekick.com/computer-science/2938345
*/

#include<bits/stdc++.h>

using namespace std;

bool canDeliver(int timestamp, string message,unordered_map<string,int>&mp,int k){
    if(mp.find(message)!=mp.end() && timestamp-mp[message]<=k) return false;
    mp[message]=timestamp;
    return true;
}

int main(){
    int n; cin>>n;
    vector<int> timestamps(n);
    vector<string> messages(n);
    unordered_map<string,int>mp;
    for(int i=0;i<n;i++) cin>>timestamps[i];
    for(int i=0;i<n;i++){
        cin>>messages[i];
    }
    int k; cin>>k;
    cout<<boolalpha;
    for(int i=0;i<n;i++){
        cout<<canDeliver(timestamps[i],messages[i],mp,k)<<" ";
    }
    cout<<endl;
}