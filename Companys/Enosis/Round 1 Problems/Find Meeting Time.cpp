/*
given n events.
each event has [person, work_title, start_time, end_time]
given an integer K.
find the earliest time when everyone is free for a meeting of K minutes.
if impossible return "-1"
n <= 1e5
K <= 1440
total person <= 5000

sample:
n = 2
k = 1
Adam Sleep 00:00 12:00
Bob homework 10:00 23:59

ans: -1

n = 2
k = 1
Adam Sleep 01:00 12:00
Bob homework 13:00 23:59

ans: 00:00
p2: Same as Arnob's Problem 1
p3:
Given an String S and a dictionary of n Strings.
from the given n strings find the lexicographically smallest one which is a subsequence of S.
*/

#include<bits/stdc++.h>

using namespace std;

int getTime(string s){
    string h=s.substr(0,2);
    string m=s.substr(3,5);
    return stoi(h)*60+stoi(m);
}

string getStr(int ans){
    int h=ans/60;
    int m=ans%60;
    string t;
    t+=('0'+h/10);
    t+=('0'+h%10);
    t+=':';
    t+=('0'+m/10);
    t+=('0'+m%10);
    return t;
}

int main(){
    int n,k; cin>>n>>k;
    map<int,int>mp;
    for(int i=0;i<n;i++){
        string name,task,start,end; cin>>name>>task>>start>>end;
        mp[getTime(start)]++;
        mp[getTime(end)+1]--;
        mp[getTime(start)+1440]++;
        mp[getTime(end)+1+1440]--;
    }

    vector<int>v(2880); // tells how many no of active person in ith time

    for(int i=0;i<2880;i++){
        if(!i) v[i]=mp[i];
        else v[i]=v[i-1]+mp[i];
    }
    int activeTime=0,ans=-1;
    for(int i=0;i<2880;i++){
        if(v[i]==0){
            if(activeTime==0) ans=i;
            activeTime++;
            if(activeTime==k){
                break;
            }
        }
        else activeTime=0,ans=-1;
    }
    if(ans==-1) cout<<ans<<endl;
    else cout<<getStr(ans)<<endl;
}