#include <stdio.h>
#include <vector>

using namespace std;

struct Listy{
  vector<int> list;
  int elementAt(int index){
      if(index >= list.size()){
          return -1;
      }
      return list[index];
  }
  
  Listy(){
      for(int i = 0; i < 100 ; ++i){
          list.push_back(i);
      }
  }
};

int findElement(Listy& listy, int elem){
    int start = 0;
    int end = ((long)1 << (sizeof(int) * 8) - 1) - 1;
    
    while(start <= end){
        int mid = start + ((end-start)/2);
        if(listy.elementAt(mid) != -1){
            if(listy.elementAt(mid) == elem){
                return mid;
            }else if(listy.elementAt(mid) >  elem){
                end = mid - 1;                
            }else{
                start = mid + 1;
            }
        }else{
            if((end >> 1) > start){
                end = end >> 1;
            }else{
                end = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{
    Listy listy;
    printf("Found at %d\n", findElement(listy, 99));
    printf("Found at %d\n", findElement(listy, 100));
    printf("Found at %d\n", findElement(listy, 11242));
    printf("Found at %d\n", findElement(listy, 12));
    printf("Found at %d\n", findElement(listy, 1));
    printf("Found at %d\n", findElement(listy, 0));
    printf("Found at %d\n", findElement(listy, -1));
    printf("Found at %d\n", findElement(listy, 50));
    printf("Found at %d\n", findElement(listy, 48));

    return 0;
}
