
#include <stdio.h>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

 vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> hashMap;
        for(string str : strs){
            string strsorted = str;
            sort(begin(strsorted), end(strsorted));
            hashMap[strsorted].push_back(str);
        }
        
        for(auto& pair : hashMap){
            res.push_back(pair.second);
        }
        return res;
    }

int main()
{
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> output = groupAnagrams(strs);
    for(auto& vec : output){
        for(string& str : vec){
            printf(" %s ", str.c_str());
        }
        printf("|");
    }
    return 0;
}
