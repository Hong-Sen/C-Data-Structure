#include "MaxHeap.h"

int main(){
    MaxHeap heap;
    
    heap.insert(2);
    heap.insert(5);
    heap.insert(6);
    heap.insert(8);
    heap.insert(9);
    heap.insert(10);
    heap.display();
    
    heap.remove();
    heap.display();
   
}
