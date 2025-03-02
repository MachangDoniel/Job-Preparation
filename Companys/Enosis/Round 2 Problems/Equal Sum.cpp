/*

There are two teams consisting of n,m members. 
Skills of members are given by array A[1].....A[n], B[1]....B[m].

If skill is 0 of any position, you need to assign a skill into that position. 
Finally sum of skill should be same for both team A and team B. 
Return minimum sum of skill or -1 if that's not possible.

1<=n,m<=1e5

1<=skill<=1e4

*/

#include<bits/stdc++.h>

using namespace std;

void print(vector<int>&v){
    int sum=0;
    for(int ele:v){
        cout<<ele<<" ";
        sum+=ele;
    }
    cout<<endl;
    // cout<<sum<<endl;
}

pair<vector<int>,vector<int>> findVectors(vector<int>&a,vector<int>&b){
    int n=a.size(),m=b.size();
    int count0AtA=0,count0AtB=0,sumA=0,sumB=0;
    for(int ele:a){
        if(ele==0) count0AtA++;
        sumA+=ele;
    }
    for(int ele:b){
        if(ele==0) count0AtB++;
        sumB+=ele;
    }

    if(sumA<=sumB){
        if(sumA+count0AtA*10000>=sumB+count0AtB*1){
            for(int i=0;i<m;i++){
                if(b[i]==0) b[i]=1;
            }
            int needAtA=sumB+count0AtB*1-sumA;
            for(int i=0;i<n;i++){
                if(a[i]==0){
                    a[i]=needAtA/count0AtA+needAtA%count0AtA;
                    needAtA-=a[i];
                    count0AtA--;
                }
            }
            return {a,b};
        }
        else{
            cout<<-1<<endl;
            return {{},{}};
        }
    }
    else{
        if(sumB+count0AtB*10000>=sumA+count0AtA*1){
            for(int i=0;i<n;i++){
                if(a[i]==0) a[i]=1;
            }
            int needAtB=sumA+count0AtA*1-sumB;
            for(int i=0;i<m;i++){
                if(b[i]==0){
                    b[i]=needAtB/count0AtB+needAtB%count0AtB;
                    needAtB-=b[i];
                    count0AtB--;
                }
            }
            return {a,b};
        }
        else{
            cout<<-1<<endl;
            return {{},{}};
        }
    }
}

int main(){
    vector<int>a={10000,0,10000,10000};
    int n=a.size();
    vector<int>b={10000,0,1,10000,10000};
    int m=b.size();
    pair<vector<int>,vector<int>>v=findVectors(a,b);
    print(v.first);
    print(v.second);
}