#include <iostream>
using namespace std;

static void sortGapInsertion(int list[], int first, int last, int gap){
    int i,j,key;
    for( i=first+gap; i<=last; i+=gap){
        key = list[i];
        cout<<key<<",";
        for(j=i-gap; j>=first && list[j] > key; j-=gap){
            cout<<list[j]<<"*";
            list[j+gap] = list[j];
        }
        cout<<"\n";
        list[j+gap] = key;
    }
}

void shell_sort(int list[], int n){
    int i,gap,count = 0;
    for(gap=n/2; gap>0; gap/=2){
        if((gap%2)==0)  gap++;
        cout<<"\ngap = "<<gap<<"\n";
        for(i=0; i<gap; i++){
            cout<<i<<":";
            sortGapInsertion(list, i, n-1, gap);
        }
            
    }
}
 
int main(){
    int list[9] = {5,3,8,4,9,1,6,2,7};
    shell_sort(list, 9);
}
