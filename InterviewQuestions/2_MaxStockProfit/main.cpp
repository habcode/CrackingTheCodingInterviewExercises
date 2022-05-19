/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int> arr){
    int maxP = 0;
    int prevP = 0;
    int currP = 0;
    int n = arr.size();
    
    for(int i = 1 ; i < n ; ++i){
        prevP = maxP;
        currP = arr[i] - arr[i - 1];
        maxP = max(prevP, currP);
        maxP = max(prevP+currP, maxP);
    }
    return maxP;
}

int main()
{
    vector<int> arr {100, 180, 260, 310, 40, 535, 695};
    int m = maxProfit(arr);
    cout<<"Max Profit: "<<m<<endl;

    return 0;
}