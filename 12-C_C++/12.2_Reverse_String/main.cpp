/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <string>

void reverseString(char * str, int iter, int& start){
    if(str[iter] == 0){
        return;
    }

    reverseString(str, iter + 1, start);
    if(start < iter){
        std::swap(str[start], str[iter]);
        ++start;
    }
}

int main()
{
    char str[] { 'h', 'e', 'l', 'l', 'o', 0};
    int iter = 0;
    int start = 0;
    reverseString(str, iter, start);
    printf("%s", str);

    return 0;
}
