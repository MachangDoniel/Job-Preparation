// ## ✅ Problem: Simplify a File Path Using Custom Linked List

// ### 📝 Description:

// You are given a UNIX-style file path as a string, which may contain directory names and special symbols like:

// * `"."` : refers to the **current directory** and has no effect.
// * `".."` : refers to the **parent directory** and removes the last valid directory from the path.
// * Any other name represents a **valid directory name**.

// Your task is to **simplify the path** and print the canonical version using a **custom linked list** (not using built-in libraries like `deque` or `vector` for path simulation).

// Use a `Node` class to represent each directory as part of a singly linked list. The final path should be printed by traversing the linked list.

// ---

// ### 📥 Input:

// * A single string `path` (1 ≤ `path.length` ≤ 10⁴), representing the UNIX-style path.
// * The path starts with `'/'` and contains segments separated by `'/'`.

// Each segment is either:

// * A valid directory name (consisting of lowercase/uppercase letters, numbers, or symbols like `...`)
// * `"."` or `".."`

// ---

// ### 📤 Output:

// * Print the simplified absolute path starting from root (`/`) followed by each valid directory, separated by `/`.

// ---

// ### 🔁 Rules:

// * `"."` is ignored.
// * `".."` removes the **last added directory** (if any).
// * If the result is the root directory, output just `'/'`.

// ---

// ### 🧪 Example 1:

// **Input:**

// ```
// /amader/../amar/sonar/./bangla/.../ok/
// ```

// **Output:**

// ```
// /amar/sonar/bangla/.../ok
// ```

// ---

// ### 🧪 Example 2:

// **Input:**

// ```
// /mahmud/./tahim/valobase/../ekta/./.../meyeke/
// ```

// **Output:**

// ```
// /mahmud/tahim/ekta/.../meyeke
// ```


#include<bits/stdc++.h>

using namespace std;

class Node{
public:
    string name;
    Node *next;
    Node(string Name) : name(Name),next(NULL) {}
};

Node *head=NULL,*temp=NULL;
stack<Node*>st;
void Insert(string Name){
    Node *ptr =new Node(Name);
    if(head==NULL){
        head=temp=ptr;
    }
    else{
        temp->next=ptr;
        temp=ptr;
    }
    st.push(ptr);
}
void Delete(){
    if(head==NULL){
        // stack empty
        return;
    }
    else{
        st.pop();
        if(st.empty()) head=NULL;
        else{
            temp=st.top();
            temp->next=NULL;
        }
    }
}

int main(){
    string path; cin>>path;
    string Name;
    for(int i=0;i<path.size();i++){
        if(path[i]=='/'){
            if(!Name.empty()){
                if(Name==".") {}
                else if(Name=="..") Delete();
                else Insert(Name);
            }
            Name.clear();
        }
        else Name+=path[i];
    }
    Node *ptr=head;
    while(ptr){
        cout<<"/"<<ptr->name;
        ptr=ptr->next;
    }
}