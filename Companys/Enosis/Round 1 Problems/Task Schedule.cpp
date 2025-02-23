/*
Given n tasks, m processor and an integer k. You have to schedule all the tasks in a balanced manner so that the k'th processor gets the most task.
In a balanced distribution of tasks, the amount of tasks two neighboring processor gets may differ by atmost 1. Also, each processor must get atleast 1 task to do.
You have to output the most amount of tasks you can give to the k'th processor.

Constraints: 
1<=n<=1e9
1<=m<=min(n, 1e5)
1<=k<=m

Sample Input: n=14, m=7, k=4
Sample Output: 3

[1, 2, 2, 3, 3, 2, 1] is a valid distribution.
[1, 1, 2, 4, 3, 2, 1] is not a valid distribution.
*/
#include<bits/stdc++.h>

using namespace std;

int minNeed(int mid,int len){
    int common=(mid*(mid-1))/2;
    if(mid-1==len) return common;
    else if(mid-1<len) return common+(len-(mid-1));
    else return common-((mid-1-len)*(mid-len))/2;
}

bool good(int n,int m,int k,int mid){
    int left=k-1,right=m-k;
    // cout<<mid<<"-> "<<left<<": "<<minNeed(mid,left)<<", "<<right<<": "<<minNeed(mid,right)<<endl;
    return minNeed(mid,left)+minNeed(mid,right)+mid<=n;
}

int main(){
    int n,m,k; cin>>n>>m>>k;
    int high=n+1,low=0;
    while(high>low+1){
        int mid=(low+high)/2;
        if(good(n,m,k,mid)) low=mid;
        else high=mid;
    }
    cout<<low<<endl;
}