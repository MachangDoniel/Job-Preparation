/*
Given an array of strings words and a width maxWidth, format the text such that each line has exactly maxWidth characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line does not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left-justified, and no extra space is inserted between words.

Note:

A word is defined as a character sequence consisting of non-space characters only.
Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
The input array words contains at least one word.
 

Example 1:

Input: words = ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16
Output:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Example 2:

Input: words = ["What","must","be","acknowledgment","shall","be"], maxWidth = 16
Output:
[
  "What   must   be",
  "acknowledgment  ",
  "shall be        "
]
Explanation: Note that the last line is "shall be    " instead of "shall     be", because the last line must be left-justified instead of fully-justified.
Note that the second line is also left-justified because it contains only one word.
Example 3:

Input: words = ["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"], maxWidth = 20
Output:
[
  "Science  is  what we",
  "understand      well",
  "enough to explain to",
  "a  computer.  Art is",
  "everything  else  we",
  "do                  "
]
 

Constraints:

1 <= words.length <= 300
1 <= words[i].length <= 20
words[i] consists of only English letters and symbols.
1 <= maxWidth <= 100
words[i].length <= maxWidth

link: https://leetcode.com/problems/text-justification/description/
*/

#include<bits/stdc++.h>

using namespace std;

string format(vector<string>&temp,int wordlen,int maxWidth){
    int noOfWord=temp.size();
    int space=maxWidth-wordlen;
    int segment=noOfWord-1;
    string res=temp[0];
    for(int i=1;i<temp.size();i++){
        int tempspace=space/segment+(space%segment!=0);
        space-=tempspace;
        segment--;
        while(tempspace--){
            res+=" ";
        }
        res+=temp[i];
    }
    while(res.size()<maxWidth){
        res+=" ";
    }
    return res;
}

vector<string> fullJustify(vector<string>&words, int maxWidth){
    int n=words.size();
    vector<string> result;
    vector<string> temp;
    int wordlen=0;
    for(int i=0;i<n;i++){
        if(temp.empty() || temp.size()+wordlen+words[i].size()<=maxWidth){
            temp.push_back(words[i]);
            wordlen+=words[i].size();
        }
        else{
            result.push_back(format(temp,wordlen,maxWidth));
            temp.clear();
            temp.push_back(words[i]);
            wordlen=words[i].size();
        }
    }
    string last=temp[0];
    for(int i=1;i<temp.size();i++){
        last+=" "+temp[i];
    }
    while(last.size()<maxWidth){
        last+=" ";
    }
    result.push_back(last);
    return result;
}

int main(){
    // vector<string> words={"This", "is", "an", "example", "of", "text", "justification."};
    vector<string> words={"What","must","be","acknowledgment","shall","be"};
    int maxWidth=16;
    vector<string> result=fullJustify(words,maxWidth);
    for(auto s:result){
        cout<<s<<endl; 
        // cout<<s.size()<<endl;
    }
}