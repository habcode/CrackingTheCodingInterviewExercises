/******************************************************************************

Cracking The Coding Interview
Chapter: 10 Sorting and Searching
Exercise: 10.1 Sorted Merge

*******************************************************************************/
#include <stdio.h>

void SortedMerge(int A[], int aSize, int B[], int bSize){
    int i = aSize - 1;
    int j = bSize - 1;
    int k = i + bSize;
    while(i >= 0 && j >= 0){
        if(A[i] > B[j]){
            A[k--] = A[i--];
        }else{
            A[k--] = B[j--];
        }
    }
}

int main()
{
    int A[10] = { 1,2,4,5,9,12 };
    int B[4] = { 3,6,7,10 };
    SortedMerge(A, 6, B, 4);
    for(int i = 0 ; i <= 9 ; i++){
        printf("%d ", A[i]);
    }

    return 0;
}
