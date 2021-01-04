#include <iostream>
#define MAX_SIZE 100
using namespace std;

static void merge(int list[], int left, int mid, int right){
    int i,j,k = left, l;
    static int sorted[MAX_SIZE];
    
    cout<<"\n[MERGE] "<<"LEFT: ";
    for(int q=left; q<=mid; q++)  cout<<list[q]<<" ";
    cout<<"  RIGHT: ";
    for(int q=mid+1; q<=right; q++)  cout<<list[q]<<" ";
    cout<<"\n\n";
    
    for(i=left, j=mid+1; i<=mid && j<=right; ){
        //sorted[k++] = (list[i]<=list[j]) ? list[i++] : list[j++];
        if(list[i]<=list[j]){
            sorted[k++] = list[i++];
        }
        else{
            sorted[k++] = list[j++];
        }
    }
    
    if(i>mid) //left배열이 먼저끝 --> right나머지를 sorted에 복사
        for(l=j; l<=right; l++, k++)
            sorted[k] = list[l];
    else
        for(l=i; l<=mid; l++, k++)
            sorted[k] = list[l];
    
    for(l=left; l<=right; l++) //sorted를 list에 복사
        list[l] = sorted[l];
}

void merge_sort(int list[], int left, int right){
    
    cout<<"[DIVIDE] ";
    cout<<"left="<<left<<", right="<<right<<" : ";
    for(int i=left; i<=right; i++)
        cout<<list[i]<<" ";
    cout<<"\n";
    
    if(left<right){
        int mid = (left+right)/2;
        merge_sort(list, left, mid);
        merge_sort(list, mid+1, right);
        merge(list, left, mid, right);
    }
}
int main(){
    int arr[5] = {3,1,1,2,3};
    
    cout<<"Original = ";
    for(int i=0; i<5;i++)
    cout<<arr[i]<<" ";
    cout<<"\n";
    
    merge_sort(arr, 0, 4);
    
    cout<<"Merge Sorting = ";
    for(int i=0; i<5;i++)
    cout<<arr[i]<<" ";
    cout<<"\n";
}
