/*
Given a vector of string of m size. string format
model no: task : time
ie:
0:start:0
1:start:2
1:end:4
2:start:6
2:end:8
0:end:10

1<=n<=100(no of model)
1<=m<=500
time<=3000


if a new model arrives while a model running.
the running model got paused, new model runs, when new model ends, old model resumes.

count which model got how much time.
*/

#include<bits/stdc++.h>

using namespace std;

vector<int> getTimeForEachModel(int noOfModel,vector<string> &operations){
    int n=operations.size(),mxTime=-1;
    unordered_map<int,pair<int,string>>mp;
    for(int i=0;i<n;i++){
        string str=operations[i];
        int idx=0;
        string modelStr,task,timeStr;
        while(str[idx]!=':'){
            modelStr+=str[idx++];
        }
        idx++;
        while(str[idx]!=':'){
            task+=str[idx++];
        }
        idx++;
        while(idx<str.size()){
            timeStr+=str[idx++];
        }
        int model=stoi(modelStr);
        int time=stoi(timeStr);
        mxTime=max(time,mxTime);
        mp[time]={model,task};
    }
    vector<int>result(noOfModel,0);
    stack<int>st;
    st.push(-1);
    for(int i=0;i<=mxTime;i++){
        int time=i;
        if(mp.find(time)!=mp.end()){
            int model=mp[time].first;
            string task=mp[time].second;
            if(task=="start"){
                st.push(model);
                // cout<<time<<" "<<st.top()<<endl;
                if(st.top()!=-1){
                    result[st.top()]++;
                }
            }
            else{
                // cout<<time<<" "<<st.top()<<endl;
                if(st.top()!=-1){
                    result[st.top()]++;
                }
                st.pop();                
            }
        }
        else{
            // cout<<time<<" "<<st.top()<<endl;
            if(st.top()!=-1){
                result[st.top()]++;
            }
        }
    }
    return result;
}

int main(){
    int noOfModel=3;
    vector<string> operations={"0:start:0","1:start:2","1:end:4","2:start:6","2:end:8","0:end:10"};
    // output: 5 3 3 
    // vector<string> operations={"0:start:0","1:start:2","1:end:4","2:start:6","2:end:8","0:end:10","1:start:12","1:end:20"};
    // output: 5 12 3 
    vector<int>time=getTimeForEachModel(noOfModel,operations);
    for(auto it:time){
        cout<<it<<" ";
    }
    cout<<endl;
}