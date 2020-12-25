////힙 정렬 프로그램 (배열을 오름차순으로 정렬)
//#include "HeapNode.h"
//#include "MaxHeap.h"
//#include <cstdlib>
//
//void heapSort(int a[], int n){
//    MaxHeap h;
//    for(int i=0;i<n;i++)
//        h.insert(a[i]);
//    
//    for(int i=n-1;i>=0;i--)
//        a[i] = h.remove().getKey(); //heap은 큰값부터 remove하기때문에
//}
//
//int main(){
//    MaxHeap heap;
//    int data[10];
//    
//    for(int i=0;i<10;i++)
//        data[i] = rand()%100;
//    printf("\n정렬전: ");
//    for(int i=0;i<10;i++)
//        printf("%3d",data[i]);
//    
//    heapSort(data, 10);
//    
//    printf("\n정렬후: ");
//    for(int i=0;i<10;i++)
//    printf("%3d",data[i]);
//    printf("\n");
//    
//}
