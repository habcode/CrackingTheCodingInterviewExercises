/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

void* aligned_malloc(size_t size, int align){
    size_t totalMemorySize = size + align + sizeof(void*);
    void* actualMemStart = malloc(totalMemorySize);
    size_t alignedMemStart = (size_t)actualMemStart + align + sizeof(void*);
    alignedMemStart = alignedMemStart &  ~(align - 1);
    size_t offsetToAlignedMem = alignedMemStart - (size_t)actualMemStart;
    *(size_t*)(alignedMemStart - sizeof(void*)) = offsetToAlignedMem;
    return (void*)alignedMemStart;
}


void aligned_free(void * mem){
    size_t offset = *(size_t*)((size_t)mem - sizeof(void*));
    void *actualMem = (void*)((size_t)mem - offset);
    free(actualMem);
}


int main()
{
    void * p = aligned_malloc(100, 2);
    printf("Alignment 2 = %p\n", p);
    aligned_free(p);
    
    p = aligned_malloc(100, 4);
    printf("Alignment 4 = %p\n", p);
    aligned_free(p);
    
    p = aligned_malloc(100, 8);
    printf("Alignment 8 = %p\n", p);
    aligned_free(p);    

    p = aligned_malloc(100, 16);
    printf("Alignment 16 = %p\n", p);
    aligned_free(p);    

    p = aligned_malloc(100, 32);
    printf("Alignment 32 = %p\n", p);
    aligned_free(p);   
    
    p = aligned_malloc(100, 64);
    printf("Alignment 64 = %p\n", p);
    aligned_free(p);
    
    p = aligned_malloc(100, 128);
    printf("Alignment 128 = %p\n", p);
    aligned_free(p);    
    return 0;
}
