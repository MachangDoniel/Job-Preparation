/*
binary string ase,duita length l and r dewa oi duita length er mddhe 
kotogula substring jar consecutive element same na 
*/

#include<bits/stdc++.h>

using namespace std;



void countSubStrinRange(string str,int q){
    vector<int>pre(str.size(),0);
    for(int i=1;i<str.size();i++){
        pre[i]=pre[i-1]+(str[i-1]!=str[i]);
    }
    // for(int i=0;i<pre.size();i++){
    //     cout<<pre[i]<<" ";
    // }
    // cout<<endl;
    auto getAns = [&](int l,int r)->int{
        if(l>r) return 0;
        else if(l==r) return 1;
        else return pre[r]-pre[l];
    };
    // while(q--){
    //     int l,r; cin>>l>>r;
    //     l--,r--;
    //     getAns(l,r);
    // }
    cout<<getAns(2,4)<<endl;
    cout<<getAns(1,6)<<endl;
    cout<<getAns(2,6)<<endl;
    cout<<getAns(2,2)<<endl;
    cout<<getAns(3,2)<<endl;
}

int main(){
    string str="01001101";
    int q=5;
    countSubStrinRange(str,q);
}