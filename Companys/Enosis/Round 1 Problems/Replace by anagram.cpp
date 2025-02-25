/*
There are given a set of words and M sentences. You can replace the words in sentence which is in the words set and replace with its anagram from the words set. For every sentence you have to find out how many ways we can change a sentence.

1 <= size of word <= 20
1 <= no of words in a sentence <= 20
1 <= M <= 1000

wordset = ['listen', 'it', 'is', 'silent']
sentence = "Iisten is silent".

Listen and Silent is anagram. So, we can rearrange the sentence in 4 ways.

listen is silent
silent is silent
listen is listen
silent is listen
*/

#include<bits/stdc++.h>

using namespace std;

int main(){
    vector<string> wordset={"listen", "it", "is", "silent"};
    string sentence = "listen is silent";
    stringstream str(sentence);
    vector<string>words;
    string word;
    while(str>>word){
        words.push_back(word);
    }
    map<string,int>mp;
    for(auto it:wordset){
        string s=it;
        sort(s.begin(),s.end());
        mp[s]++;
    }
    int ans=1;
    for(auto it:words){
        string s=it;
        sort(s.begin(),s.end());
        ans*=mp[s];
    }
    cout<<ans<<endl;
}