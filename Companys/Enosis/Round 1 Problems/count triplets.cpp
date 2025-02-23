/*
Given an array of n distinct integers, d = [d[0], d[1],..., d[n-1]], and an integer threshold, t, how many (a, b, c) index triplets exist that satisfy both of the following conditions?

d[a] < d[b] < d[c]
d[a] + d[b] + d[c] ≤ t

Example:
d = [1,2,3,4,5]
t=8
The following 4 triplets satisfy the constraints:
(1,2,3) → 1 + 2 + 3 = 6 ≤ 8
(1,2,4) → 1 + 2 + 4 = 7≤ 8
(1,2,5) → 1 + 2 + 5 = 8≤ 8
(1,3,4) → 1 + 3 + 4 = 8≤ 8

Constraints:
    • 1≤n≤10^4
    • 0≤d[i]<10^9
    • 0<t<3×10^9

link: https://brainly.com/question/34247760
*/
//Approach:
// 1. Sort the array
// 2. Fix the first element of the triplet and then iterate over the second element and then find the third element using binary search
// 3. If the sum of the three elements is less than or equal to t, then increment the count
// Time complexity: O(n^2logn), Space complexity: O(n)
#include<bits/stdc++.h>

#define ll long long

using namespace std;

int main(){
    int n; cin>>n;
    vector<ll>d(n);
    for(int i=0;i<n;i++) cin>>d[i];
    ll t; cin>>t;
    sort(d.begin(),d.end());
    ll count=0;
    for(int i=0;i<n-2;i++){
        ll a=d[i];
        for(int j=i+1;j<n-1;j++){
            ll b=d[j];
            ll maxC=t-a-b;
            if(maxC<=b) break;
            int cMaxIndex=upper_bound(d.begin(),d.end(),maxC)-d.begin()-1;
            if(cMaxIndex>j) count+=(cMaxIndex-j);
        }
    }
    cout<<count<<endl;
}