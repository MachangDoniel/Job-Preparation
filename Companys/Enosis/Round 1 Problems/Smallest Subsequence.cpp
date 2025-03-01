/*
Given an String S and a dictionary of n Strings.
from the given n strings find the lexicographically smallest one 
which is a subsequence of S.
*/

#include <bits/stdc++.h>

using namespace std;

// Function to check if 'word' is a subsequence of 'S'
bool isSubsequence(const string& S, const string& word) {
    int n = S.size(), m = word.size();
    int i = 0, j = 0;

    // Use two pointers to check if 'word' is a subsequence of 'S'
    while (i < n && j < m) {
        if (S[i] == word[j]) {
            j++;
        }
        i++;
    }

    return j == m; // If we've matched all characters of 'word', it's a subsequence
}

string findSmallestSubsequence(const string& S, const vector<string>& dict) {
    string result = "";

    for (const string& word : dict) {
        if (isSubsequence(S, word)) {
            if (result == "" || word < result) {
                result = word;
            }
        }
    }

    return result; // Return the lexicographically smallest subsequence
}

int main() {
    string S = "abcabcd";
    vector<string> dict = {"abc", "ab", "cd", "ac", "a"};

    string result = findSmallestSubsequence(S, dict);
    cout << result << endl;

    return 0;
}
