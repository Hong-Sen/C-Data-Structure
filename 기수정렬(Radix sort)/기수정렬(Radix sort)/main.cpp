#include <iostream>
#include "CircularQueue.cpp"
#define BUCKETS 10
#define DIGITS 4

void radixSort(int list[], int n){
    CircularQueue q[BUCKETS];
    int factor = 1, i, b, d; //i=list index, b=queue index
    
    for(d=0; d<DIGITS; d++){
        for(int i=0; i<n; i++)
        q[(list[i]/factor) % 10].enQueue(list[i]);
        
        for(b=i=0; b<BUCKETS; b++){
            while(!q[b].isEmpty())
                list[i++] = q[b].deQueue();
        }
        factor *= 10;
    }
}
int main(){
    
}
