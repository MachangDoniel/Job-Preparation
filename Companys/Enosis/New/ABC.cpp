/*
given a string containing a,b and c. ex:abb,ac.
how many insertion is needed to make the string a sequence of "abc"
abb->abcabc     ans=3
aa->abcabc     ans=4
*/

#include<bits/stdc++.h>

using namespace std;

int findMinInsertion(string str){
    vector<char>v;
    for(int i=0;i<str.size();i++){
        v.push_back(str[i]);
        if(v.size()>2 && v[v.size()-3]=='a' && v[v.size()-2]=='b' && v[v.size()-1]=='c'){
            v.pop_back(),v.pop_back(),v.pop_back();
        }
    }
    int count=0;
    for(int i=0;i<v.size();i++){
        if(i+1<=v.size()-1){
            if(v[i]=='a' && v[i+1]=='b') count++,i++;           // insert c
            else if(v[i]=='a' && v[i+1]=='c') count++,i++;      // insert b
            else if(v[i]=='b' && v[i+1]=='c') count++,i++;      // insert a
            else count+=2;
        }
        else count+=2;
    }
    // for(auto it:v){
    //     cout<<it;
    // }
    // cout<<endl;
    return count;
}

int main(){
    // string str="abb";
    string str="aa";
    cout<<findMinInsertion(str)<<endl;
}