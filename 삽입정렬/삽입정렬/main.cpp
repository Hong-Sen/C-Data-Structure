#include <iostream>
using namespace std;

void insert_sort(int A[], int n){
    for(int i=1; i<n; i++){
        int key = A[i];
        int j;
        for(j=i-1; j>=0 && A[j]>key; j--)
            A[j+1] = A[j];
        A[j+1] = key;
    }
}

int main(){
     
}
