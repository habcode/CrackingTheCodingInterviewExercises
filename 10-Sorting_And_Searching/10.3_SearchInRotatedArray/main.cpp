
#include <stdio.h>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int searchInRotatedArray(vector<int>& arr, int elem, int start, int end) {
    if(start <= end){
        int mid = start + ((end - start) / 2);
        if(elem == arr[mid]){
            return mid;
        }else if(elem > arr[mid] && elem <= arr[end]){
            return searchInRotatedArray(arr, elem, mid+1, end);
        }else{
            return searchInRotatedArray(arr, elem, start, mid-1);
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14};
    int ri = searchInRotatedArray(arr, 14, 0, arr.size()-1);
    printf("%d\n", ri);
    ri = searchInRotatedArray(arr, 15, 0, arr.size()-1);
    printf("%d\n", ri);
    ri = searchInRotatedArray(arr, 25, 0, arr.size()-1);
    printf("%d\n", ri);
    ri = searchInRotatedArray(arr, 1, 0, arr.size()-1);
    printf("%d\n", ri);
    ri = searchInRotatedArray(arr, 7, 0, arr.size()-1);
    printf("%d\n", ri);
    ri = searchInRotatedArray(arr, 19, 0, arr.size()-1);
    printf("%d\n", ri);
    ri = searchInRotatedArray(arr, 20, 0, arr.size()-1);
    printf("%d\n", ri);
    return 0;
}
