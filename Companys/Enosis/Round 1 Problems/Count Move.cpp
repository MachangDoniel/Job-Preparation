/*
You are given n points (1, 2, ... , n) and m segments. 
Each segments is already taken. No two segments overlap with each other. 
In a move you can take 2^x (x=0, 1, 2, .. ) continuous points (that is not already taken). 
Now, you have to count the minimum number of moves required to take all the points. 

Input Format: 
    n m
    l1 r1
    l2 r2
    .. ..
    .. ..
    .. ..
    lm rm

Output Format: ans

Contraints: 
    1<=n<=1e18
    0<=m<=1e5
    1<=li<=ri<=n

Sample input:
    14 2
    5 5
    7 9
Sample output: 4
*/

#include<bits/stdc++.h>

using namespace std;

int need(int num){
    int d=pow(2,int(log2(num)));
    // cout<<"for: "<<num<<" "<<d<<endl;
    if(num==0) return 0;
    return 1+need(num%d);
}

int main(){
    int n,m; cin>>n>>m;
    vector<pair<int,int>>v;
    for(int i=0;i<m;i++){
        int l,r; cin>>l>>r;
        v.push_back({l,r});
    }
    sort(v.begin(),v.end());
    int last=0;
    vector<int>nums;
    for(int i=0;i<m;i++){
        int l=v[i].first;
        if(l-1>last){
            nums.push_back(l-1-last);
        }
        last=v[i].second;
    }
    if(last!=n) nums.push_back(n-last);
    int count=0;
    // for(auto it:nums){
    //     cout<<it<<" ";
    // }
    // cout<<endl;
    for(auto it:nums){
        int need2=need(it);
        // cout<<it<<" "<<need2<<endl;
        count+=need2;
    }
    cout<<count<<endl;
    return 0;
}
