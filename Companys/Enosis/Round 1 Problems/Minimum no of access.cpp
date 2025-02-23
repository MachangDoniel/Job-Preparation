/*
Given a string s of length n contains characters only from 0-9. You can access the characters of the string sequentially. You can access the 2nd character exactly after the 1st character.
Given q queries. In each query there is a string of length m also contains characters only from 0-9.
You have to make this string from the string s. You can also permute the characters to make it.
Calculate the minimum number of characters you need to access. If is not possible print -1.
1<=n<=10^5
1<=q<=10^5
1<=sum of m<=10^5

S = 0865546300
M = 364
ans = 8
*/

#include<bits/stdc++.h>

using namespace std;

int num(char ch){
    return ch-'0';
}

bool good(int mid,string& ss,vector<vector<int>>&v){
    int m=ss.size();
    vector<int>mp(10);
    for(int i=0;i<m;i++){
        mp[num(ss[i])]++;
    }
    // cout<<"mp: "<<endl;
    // for(int i=0;i<10;i++){
    //     cout<<"  "<<i<<": "<<mp[i]<<endl;
    // }
    // cout<<endl;
    for(int i=0;i<10;i++){
        int count=mp[i];
        int has=v[mid][i];
        // cout<<i<<": "<<has<<" "<<count<<endl;
        if(has<count) return false;
    }
    return true;
}

int main(){
    string s; cin>>s;
    int n=s.size();
    vector<vector<int>>v(n+1,vector<int>(10,0));  // 1 based
    for(int i=0;i<n;i++){
        v[i+1]=v[i];
        v[i+1][num(s[i])]++;
    }
    // for(int i=0;i<=n;i++){
    //     cout<<i<<": "<<endl;
    //     for(int j=0;j<10;j++){
    //         cout<<"    "<<j<<": "<<v[i][j]<<endl;
    //     }
    //     cout<<endl;
    // }
    int q; cin>>q;
    for(int i=0;i<q;i++){
        string ss; cin>>ss;
        int high=n+1,low=0;
        while(high>low+1){
            int mid=low+(high-low)/2;
            if(good(mid,ss,v)) high=mid;
            else low=mid;
        }
        if(high==n+1) cout<<-1<<endl;
        else cout<<high<<endl;
    }
}