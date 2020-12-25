#include <iostream>
#include <cstdio>
#define swap(x,y,t) ((t) = (x), (x) = (y), (y) = (t))
using namespace std;

void selection_sort(int list[], int n){
    int least,tmp;
    for(int i=0; i<n-1; i++){
        least = i;
        for(int j=i+1; j<n; j++){
            if(list[j] < list[least])   least = j;
        }
        swap(list[i], list[least], tmp);
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
    selection_sort(list, 9);
    printArray(list, 9, "selection");
}
