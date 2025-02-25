/*
In a school there is a room where n students will sit for an exam.
i'th student will sit for the exam from time s_i to t_i
If there're at least k students in the room, then we need an invigilator.

given q queries. For each query, you're given a time range l r.
Count the number of minutes where we need an invigilator.
Sample for problem 1:
N = 3
K = 2
2 9
3 5
7 8
q = 2
1 10 ans: 5
6 7 ans: 1

everything <= 1e6
*/

// Approach:
// step 1: keep tracking of students incoming & leaving.
// step 2: keep tracking by v, when no of students >= k.
// step 3: keep tracking by prefix, using prefix sum, to get the ans when given range

#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,k; cin>>n>>k;
    map<int,int>mp;
    while(n--){
        int l,r; cin>>l>>r;
        mp[l]++;
        mp[r+1]--;
    }
    vector<int>v(1e6+1,0);
    for(int i=1;i<v.size();i++){
        v[i]+=v[i-1]+mp[i];
    }
    // for(int i=0;i<10;i++){
    //     cout<<v[i]<<" ";
    // }
    // cout<<endl;
    vector<int>prefix(v.size());
    int count=0;
    for(int i=1;i<prefix.size();i++){
        prefix[i]+=prefix[i-1]+(v[i]>=k);
        // cout<<prefix[i]<<" ";
    }
    // cout<<endl;
    int q; cin>>q;
    while(q--){
        int l,r; cin>>l>>r;
        cout<<prefix[r]-prefix[l-1]<<endl;
    }
}