#include <iostream>
#define swap(x,y,t) ((t) = (x), (x) = (y), (y) = (t))
using namespace std;

void bubbleSort(int A[], int n){
    int tmp, bChanged;
    for(int i=n-1; i>0; i--){
        bChanged = 0;
        for(int j=0; j<i; j++)
        if(A[j] > A[j+1]){
            swap(A[j], A[j+1], tmp);
            bChanged = 1;
        }
        if(!bChanged)   break;
    }
}

void printArray(int arr[], int n, char *str="Array"){
    printf("%s = ", str);
    for(int i=0; i<n; i++)
        printf("%3d", arr[i]);
    printf("\n");
}

int main(){
    int list[9] = {5, 3, 8, 4, 9, 1, 6, 2, 7};
    printArray(list, 9, "Original");
    bubbleSort(list, 9);
    printArray(list, 9, "selection");
}

