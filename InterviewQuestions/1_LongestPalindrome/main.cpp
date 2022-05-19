#include <stdio.h>
#include <string>
#include <unordered_map>

using namespace std;

bool isPalindrome(string& str, int s, int e){
    while(s <= e){
        if(str[s] == str[e]){
            ++s;
            --e;
        }else{
            break;
        }
    }
    if(s > e){
        return true;
    }
    return false;
}


int longestPalindrome(string& str, int s, int e, int& longestPalin, unordered_map<string, int>& memo){
    string key = to_string(s) + "_" + to_string(e);
    if(memo.find(key) != memo.end()){
        return memo[key];
    }
    if(s <= e){
        if(isPalindrome(str, s, e)){
            int len = e - s + 1;
            if(longestPalin  < len){
                longestPalin = len;
            }
        }else{
            longestPalin = max(longestPalindrome(str, s + 1, e, longestPalin, memo),
                            longestPalindrome(str, s, e - 1, longestPalin, memo));
        }
    }
    memo[key] = longestPalin;
    return longestPalin;
}

int main()
{
    string str = "abcdcba";
    int l = 0;
    unordered_map<string, int> memo;
    longestPalindrome(str, 0, str.size() - 1, l, memo);
    printf("%d\n", l);

    return 0;
}
