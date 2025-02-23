/*
given n edges. Find maximum difference between 2 the connected component.
3
1 2
2 3
4 5
ans: 2
1->2->3 : 3-1 => 2
4->5    : 5-4 => 1
*/

#include<bits/stdc++.h>

using namespace std;

// if range (10^5)
vector<vector<int>>adj(100000);
vector<bool>vis(100000,false);
int mn,mx;

void getMaxDiff(int parent){
    vis[parent]=true;
    mn=min(mn,parent);
    mx=max(mx,parent);
    for(int i=0;i<adj[parent].size();i++){
        if(!vis[adj[parent][i]]) getMaxDiff(adj[parent][i]);
    }
}

int main(){
    int n; cin>>n;
    for(int i=0;i<n;i++){
        int x,y; cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int ans=0;
    for(int i=0;i<100000;i++){
        mn=INT_MAX,mx=-INT_MAX-1;
        if(!vis[i]){
            getMaxDiff(i);
            ans=max(ans,mx-mn);
        }
    }
    cout<<ans<<endl;
}