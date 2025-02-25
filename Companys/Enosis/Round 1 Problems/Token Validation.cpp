/*
Given an array of tokens.
Given a 2d array of requests.
2types of request=get,post.


If token doesn't contained in the token array, request is invalid.
If there is no csrf for post request, it is invalid.

input
tokens=["ajjajsjsskskks7","abcd',"xyz"]
requests=[["get","https://exampld.com/?token=aaaaa&name=rrrr"],
["get","https://exampld.com/?token=abcd&name=rrrr&location=kuet"],
["post","https://exampld.com/?token=abcd&csrf=asJ124Kii&name=rrrr&location=kuet&id=hiji"]]
["post","https://exampld.com/?token=abcd&name=rrrr&location=kuet&id=hiji"]]

Output
"INVALID"
"VALID,name,rrrr,location,kuet"
"VALID,name,rrrr,location,kuet,id,hiji"
"INVALID"
exampld.com
*/

#include <bits/stdc++.h>

using namespace std;

// Function to parse query parameters from URL
map<string, string> parseQueryParams(string url) {
    map<string, string> params;
    int pos = url.find('?');
    if (pos == -1) return params;  // No query params

    string query = url.substr(pos + 1);
    stringstream ss(query);
    string pair;

    while (getline(ss, pair, '&')) {
        int equalPos = pair.find('=');
        if (equalPos != -1) {
            string key = pair.substr(0, equalPos);
            string value = pair.substr(equalPos + 1);
            params[key] = value;
        }
    }
    return params;
}

// Function to validate requests
void validateRequests(vector<string> &tokens, vector<pair<string, string>> &requests) {
    unordered_set<string> tokenSet(tokens.begin(), tokens.end());

    for (auto &req : requests) {
        string method = req.first;
        string url = req.second;

        // Parse query parameters
        map<string, string> params = parseQueryParams(url);

        // Check if token exists and is valid
        if (params.find("token") == params.end() || tokenSet.find(params["token"]) == tokenSet.end()) {
            cout << "\"INVALID\"" << endl;
            continue;
        }

        // If it's a POST request, check for CSRF
        if (method == "post" && params.find("csrf") == params.end()) {
            cout << "\"INVALID\"" << endl;
            continue;
        }

        // Construct the valid response
        cout << "\"VALID";
        vector<string> ordered_keys = {"name", "location", "id"};

        for (string &key : ordered_keys) {
            if (params.find(key) != params.end()) {
                cout << "," << key << "," << params[key];
            }
        }

        cout << "\"" << endl;
    }
}

int main() {
    vector<string> tokens = {"ajjajsjsskskks7", "abcd", "xyz"};
    vector<pair<string, string>> requests = {
        {"get", "https://exampld.com/?token=aaaaa&name=rrrr"},
        {"get", "https://exampld.com/?token=abcd&name=rrrr&location=kuet"},
        {"post", "https://exampld.com/?token=abcd&csrf=asJ124Kii&name=rrrr&location=kuet&id=hiji"},
        {"post", "https://exampld.com/?token=abcd&name=rrrr&location=kuet&id=hiji"}
    };

    validateRequests(tokens, requests);
    return 0;
}
