/*
given an array and  an int k. Find the number unique of pairs {a[i], a[j]} where a[i]+k = a[j].
a[i]-a[j]=k
value + k = some value
intput: v={1,2,3,4,5,2,2}, k=2
output: 3
*/

#include<bits/stdc++.h>

using namespace std;

int main(){
    int n; cin>>n;
    vector<int>v(n);
    map<int,int>mp;
    for(int i=0;i<n;i++){
        cin>>v[i];
        mp[v[i]]++;
    }
    int k; cin>>k;
    int total_pair=0,unique_pair=0;
    for(auto it:mp){
        int value=it.first;
        int count=it.second;
        // cout<<value<<" "<<count<<endl;
        if(mp.find(value+k)!=mp.end()){
            total_pair+=(count*mp[value+k]);
            unique_pair+=((count*mp[value+k])!=0);
        }
    }
    cout<<unique_pair<<" "<<total_pair<<endl;
}