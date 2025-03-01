/*
Given N people and M information of debts in form of tuples (U, V, W) means U owes W tk from V. What is the minimum number of transaction should be made to clear all debts.
example: 
3 3  // N and M
0 1 10   // 0 owes 10 tk from 1
1 2 5
2 0 5
Ans: 1  // if 1 gives 5 tk to 0 then all debts are clear in one transaction.
1 <= N <= 9
1 <= M <= 1e5
1 <= W <= 1e9
*/

#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m; cin>>n>>m;
    vector<int>mp(n);
    vector<pair<int,int>>p(m);
    for(int i=0;i<m;i++){
        int u,v,w; cin>>u>>v>>w;
        p.push_back({u,v});
        mp[u]+=w;
        mp[v]-=w;
    }
    for(int i=0;i<m;i++){
        int u=p[i].first;
        int v=p[i].second;
        if(mp[u]!=0 && mp[v]!=0){
            int money=min(mp[u],-mp[v]);
        }
    }
}