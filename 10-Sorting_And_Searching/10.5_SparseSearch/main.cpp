#include <stdio.h>
#include <vector>
#include <string>
#include <string.h>

using namespace std;

int sparseSearch(vector<string>& strs, string str){
    int start = 0;
    int end = strs.size() - 1;
    while(start <= end){
        int mid = start + ((end-start)/2);
        if(strs[mid].empty()){
            // goto to any direction to find the string
            int emptyMid = mid;
            while(++emptyMid < end){
                if(!strs[emptyMid].empty()){
                    break;
                }
            }
            
            if(strs[emptyMid].empty()){
                emptyMid = mid;
                while(--emptyMid > start){
                    if(!strs[emptyMid].empty()){
                        break;
                    }
                }
                end = emptyMid;
            }
            mid = emptyMid;
        }
        if(strs[mid] == str){
            return mid;
        }else if(strcmp(strs[mid].c_str(), str.c_str()) > 0){
            end = mid - 1;
        }else{
            start = mid + 1;
        }
    }
    return -1;
}

int main()
{
    vector<string> arr = {"for", "geeks", "", "", "", "", "ide", 
                      "practice", "", "", "", "quiz"};
    
    string str = "geeks";
    printf("%s is found at %d\n", str.c_str(), sparseSearch(arr, str));
    str = "for";
    printf("%s is found at %d\n", str.c_str(), sparseSearch(arr, str));
    str = "ide";
    printf("%s is found at %d\n", str.c_str(), sparseSearch(arr, str));
    str = "practice";
    printf("%s is found at %d\n", str.c_str(), sparseSearch(arr, str));
    str = "quiz";
    printf("%s is found at %d\n", str.c_str(), sparseSearch(arr, str));
    str = "google";
    printf("%s is found at %d\n", str.c_str(), sparseSearch(arr, str));    
    
    return 0;
}
