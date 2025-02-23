/*
Given an array of n integers and q queries. In every query find the number of elements in the range l and r inclusive.
1<=n<=10^5
1<=a[i]<=10^9
1<=q<=10^5
0<=l<=r<=10^9

arr=[ 1, 2, 2, 3, 4]
For l=2 and r=4, ans=4
*/

#include<bits/stdc++.h>

using namespace std;

int main(){
    int n; cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int q; cin>>q;
    for(int i=0;i<q;i++){
        int l,r; cin>>l>>r;
        int low=lower_bound(a,a+n,l)-a;
        int high=upper_bound(a,a+n,r)-a;
        cout<<high-low<<endl;
    }
}