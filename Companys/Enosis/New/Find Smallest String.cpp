/*
Given a binary string Str and an integer maxSwap.

You can swap any consecutive pair.

Return the lexicographically smallest string you can make.

*/

#include<bits/stdc++.h>

using namespace std;

string FindSmallestString(string str,int maxSwap){
    vector<int>oneBeforeZero;
    int one=0;
    for(int i=0;i<str.size();i++){
        if(str[i]=='0') oneBeforeZero.push_back(one);
        else one++;
    }
    for(int i=0;i<oneBeforeZero.size();i++){
        if(maxSwap>=oneBeforeZero[i]){
            maxSwap-=oneBeforeZero[i];
            oneBeforeZero[i]=0;
        }
        else{
            oneBeforeZero[i]-=maxSwap;
            maxSwap=0;
            break;
        }
    }
    string ans;
    one=0;
    for(int i=0;i<oneBeforeZero.size();i++){
        while(one<oneBeforeZero[i]){
            ans+='1';
            one++;
        }
        ans+='0';
    }
    while(ans.size()<str.size()){
        ans+='1';
    }
    return ans;
}

int main(){
    string str="1010110";
    int maxSwap=5;
    // output: 0011011
    cout<<FindSmallestString(str,maxSwap)<<endl;
}