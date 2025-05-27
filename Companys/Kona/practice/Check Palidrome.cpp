#include<bits/stdc++.h>

using namespace std;


struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(NULL) {}
};

Node *head=NULL,*temp=NULL;

void Insert(int val){
    Node *ptr =new Node(val);
    if(head==NULL){
        head=temp=ptr;
    }
    else{
        temp->next=ptr;
        temp=ptr;
    }
}

Node *reverse(Node *current){
    Node *prev = nullptr;
    while(current){
        Node *next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    return current;
}

bool isPalindrome(Node *head){
    Node *slow=head,*fast=head;
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    Node *first=head;
    Node *second=reverse(slow);
    while(second){
        if(first->val!=second->val) return false;
        first=first->next;
        second=second->next;
    }
    return true;
}


int main(){
    // int arr[] = {2,4,7,6,3};
    int arr[] = {3,6,7,6,3};
    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++){
        Insert(arr[i]);
    }
    cout<<isPalindrome(head)<<endl;
}