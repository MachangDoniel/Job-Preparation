/*
Given some usernames and a dictionary of size n and m respectively. Both are array of strings. An username is tagged weak if it falls under anyone of the following criterions :
1. All characters are Uppercase
2. All are lower case.
3. Length is less than 6
4. All are numbers
5. Any substring of the username is available in the dictionary. 
Otherwise it is strong. Return a vector of strings for each username if it is weak or strong.

1<= n <= 1000
1<=m<=100000
Each strings maximum size is 20
*/

#include<bits/stdc++.h>

using namespace std;

bool CheckStatus(string username,unordered_set<string> &dictSet){
    // 1
    bool allupper=true;
    for(char ch:username){
        if(!('A'<=ch && ch<='Z')) allupper=false;
    }
    if(allupper) return false;
    // 2
    bool alllower=true;
    for(char ch:username){
        if(!('a'<=ch && ch<='z')) alllower=false;
    }
    if(alllower) return false;
    // 3
    if(username.size()<6) return false;
    // 4
    bool allnumber=true;
    for(char ch:username){
        if(!('0'<=ch && ch<='9')) allnumber=false;
    }
    if(allnumber) return false;
    // 5
    bool issubstr=false;
    for(int i=0;i<username.size();i++){
        for(int len=1;len<username.size()-i;len++){
            if(dictSet.count(username.substr(i,len))){
                issubstr=true;
                return false;
            }
        }
    }

    return true;
}

vector<bool> findEntityStatus(vector<string> &usernames, vector<string> &dictionary){
    int n=usernames.size();
    vector<bool>result(n);
    unordered_set<string>dictSet(dictionary.begin(),dictionary.end());
    for(int i=0;i<n;i++){
        result[i]=CheckStatus(usernames[i],dictSet);
    }
    return result;
}

int main(){
    vector<string> usernames={"doniel","Tripura","maChang","RIMIRANI","chakma8","Ok","123456"};
    // vector<string> usernames = {"Tripura"};
    vector<string> dictionary={"trip","rimi"};
    vector<bool> result=findEntityStatus(usernames,dictionary);

    for(int i=0;i<result.size();i++){
        cout<<usernames[i]<<" -> ";
        if(result[i]) cout<<"strong"<<endl;
        else cout<<"weak"<<endl;
    }
    cout<<endl;
}