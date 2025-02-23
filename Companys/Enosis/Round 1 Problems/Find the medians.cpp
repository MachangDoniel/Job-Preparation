/*
Given an array.  Find the median (in sorted array) for every index insertion.

For even ans is 1st median. 
4 6 8 1 2
Output: 4 4 6 4 4
*/

#include<bits/stdc++.h>

using namespace std;

void print(priority_queue<int>pq){
    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;
}

// Approach:
// 1. Maintain two heaps. One max heap and one min heap.
// 2. Max heap will store the smaller half of the elements and min heap will store the larger half of the elements.
// 3. Median will be the top of the min heap.
// Time complexity of this approach is O(nlogn) and space complexity is O(n).
void solveUsingMinHeapMaxHeap(vector<int>&v){
    int n=v.size();

    priority_queue<int>max_heap,min_heap;
    for(int i=0;i<n;i++){
        if(min_heap.empty() || v[i]<=min_heap.top()) min_heap.push(v[i]);
        else max_heap.push(-v[i]);

        // balance
        if(0<=min_heap.size()-max_heap.size() && min_heap.size()-max_heap.size()<=1){
            // do nothing   
        }
        else if(min_heap.size()<max_heap.size()){
            min_heap.push(-max_heap.top());
            max_heap.pop();
        }
        else{
            max_heap.push(-min_heap.top());
            min_heap.pop();
        }
        // cout<<"min: "; print(min_heap);
        // cout<<"max: "; print(max_heap);
        cout<<min_heap.top()<<" ";
    }
    cout<<endl;
}

void print(multiset<int>ms){
    for(auto it=ms.begin();it!=ms.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}
// Approach:
// 1. Maintain a multiset and track the median pointer
// 2. Insert the elements one by one and update the median pointer accordingly.
// 4. Time complexity of this approach is O(nlogn) and space complexity is O(n).
void solveUsingMultiset(vector<int>&v){
    int n=v.size();
    
    multiset<int>ms;
    ms.insert(v[0]);
    auto median=ms.begin();
    bool mid=true;
    cout<<*median<<" ";
    for(int i=1;i<n;i++){
        ms.insert(v[i]);
        if(*median<=v[i]){
            if(!mid) median++;
        }
        else{
            if(mid) median--;
        }
        mid=!mid;
        // print(ms);
        cout<<*median<<" ";
    }
    cout<<endl;
}

int main(){
    string line;
    getline(cin,line);
    stringstream elements(line);
    vector<int>v;
    int element;
    while(elements>>element){
        v.push_back(element);
    }
    // solveUsingMinHeapMaxHeap(v);
    solveUsingMultiset(v);
    return 0;
}