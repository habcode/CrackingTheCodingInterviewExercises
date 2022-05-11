/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// print last k lines of file
// circular buffer of length k

void PrintLastKLinesOfFile(std::string file, unsigned k){
    std::ifstream inFile(file.c_str());
    std::vector<std::string> buffer(k, "");
    int index = 0;
    if(inFile.is_open()){
        while(!inFile.eof()){
            index = index % k;
            std::getline(inFile, buffer[index++]);
        }
    }else{
        std::cout<<"Unable to open file: "<< file << std::endl;
    }
    
    int iter = index;
    do{
        if(!buffer[iter].empty()){
            std::cout<<buffer[iter]<<std::endl;
        }
        iter++;
        iter = iter % k;
    }while(iter != index);
}

int main()
{
   std::string filepath = "test.txt";
   PrintLastKLinesOfFile(filepath,-1);
    return 0;
}
