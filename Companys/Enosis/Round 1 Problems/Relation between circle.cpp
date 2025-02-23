/*
দুইটা সার্কেলের কেন্দ্রের পজিশন দেয়া ছিলো আর ব্যাসার্ধ দেয়া ছিলো (string আকারে, multiple testcase), দুইটা সার্কেলের কেন্দ্র হয় X অক্ষের উপর 
অথবা দুইটাই Y অক্ষের উপর। বলসে, এদের মাঝে রিলেশন বের করো (touching, intersecting, disjoint-inside, disjoint-outside).
সলভ করার পর বলসে, যদি দুইটার কেন্দ্র রেন্ডম পজিশনে হইতো, তাহলে কেমনে সলভ করা যাইতো, অইটা বোর্ডে সলভ করতে বলসে।
input: vector of string (x1 y1 x2 y2 r1 r2 x1 y1 x2 y2 r1 r2...)
2 0 2 0 3 4 0 7 0 7 3 1
output: disjoint-inside, disjoint-outside
*/

#include<bits/stdc++.h>

using namespace std;

// void solve(){
//     int x1,x2,y1,y2; cin>>x1>>y1>>x2>>y2;  // either x1==x2==0 or y1==y2==0 according to the problem statement
//     int r1,r2; cin>>r1>>r2;
//     int d=abs(x1-x2)+abs(y1-y2); // d=sqrt((x1-x2)^2+(y1-y2)^2)
//     if(d==r1+r2) cout<<"touching"<<endl;
//     else if(d>r1+r2) cout<<"disjoint-outside"<<endl;
//     else if(d<r1+r2){
//         if(d+min(r1,r2)==max(r1,r2)) cout<<"touching"<<endl;
//         else if(d+min(r1,r2)<max(r1,r2)) cout<<"disjoint-inside"<<endl;
//         else cout<<"intersecting"<<endl;
//     }
// }

// int main(){
//     // expecting w/o extraction
//     int T; cin>>T;
//     for(int t=1;t<=T;t++){
//         solve();
//     }
//     return 0;
// }

void solve(vector<int>&v){
    int x1,x2,y1,y2;   // either x1==x2==0 or y1==y2==0 according to the problem statement
    int r1,r2;
    for(int i=0;i<v.size();i+=6){
        x1=v[i], y1=v[i+1], x2=v[i+2], y2=v[i+3];
        r1=v[i+4], r2=v[i+5];
        int d=abs(x1-x2)+abs(y1-y2); // d=sqrt((x1-x2)^2+(y1-y2)^2)
        if(d==r1+r2) cout<<"touching"<<endl;
        else if(d>r1+r2) cout<<"disjoint-outside"<<endl;
        else if(d<r1+r2){
            if(d+min(r1,r2)==max(r1,r2)) cout<<"touching"<<endl;
            else if(d+min(r1,r2)<max(r1,r2)) cout<<"disjoint-inside"<<endl;
            else cout<<"intersecting"<<endl;
        }
    }
    
}

int main(){
    int T; cin>>T;
    T=1;
    for(int t=1;t<=T;t++){
        vector<int>v={2, 0, 2, 0, 3, 4, 0, 2, 0, 7, 3, 1};
        solve(v);
    }
    return 0;
}