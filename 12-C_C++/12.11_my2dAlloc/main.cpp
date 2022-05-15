#include <iostream>

using namespace std;

int** my2dalloc(int r, int c){
    int** mem = (int**)malloc(r * sizeof(int*) + r * c *sizeof(int));
    int* arr = (int*)(mem + r);
    for(int i = 0 ; i < r ; ++i){
        mem[i] = arr + (i * c);
    }
    return mem;
}

void my2dfree(void* p){
    free(p);
}

int main()
{
    int r = 5;
    int c = 5;
    int** m2darr = my2dalloc(r,c);
    int value = 0;
    for(int i = 0 ; i < r ; ++i){
        for(int j = 0 ; j < c ; ++j){
            m2darr[i][j] = value++;
        }
    }
    
    for(int i = 0 ; i < r ; ++i){
        for(int j = 0 ; j < c ; ++j){
            printf("m2darr[%d][%d] = %d\n", i, j, m2darr[i][j]);
        }
    }

    my2dfree(m2darr);

    return 0;
}