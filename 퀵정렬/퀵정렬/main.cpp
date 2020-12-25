#include <iostream>
#define swap(x,y,t) ((t) = (x), (x) = (y), (y) = (t))
using namespace std;

int partition(int list[],int left, int right){
    int tmp;
    int pivot = list[left];
    int low = left+1;
    int high = right;
    
    while(low < high){
        for(;low<=right&&list[low]<pivot;low++);
        for(;high>=left&&list[high]>pivot;high--);
        if(low < high)  swap(list[low], list[high], tmp);
    }
    
    swap(list[left],list[high],tmp);
    return high;
    
}

void quick_sort(int list[], int left, int right){
    int q;
    if(left < right){
        q = partition(list,left,right);
        quick_sort(list, left, q-1);
        quick_sort(list, q+1, right);
    }
    
}
int main(){
    int n;
    cin>>n;
    int arr[100];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    quick_sort(arr, 0, n-1);
    for(int i=0; i<n; i++)
        cout<<arr[i]<<"* ";
}
