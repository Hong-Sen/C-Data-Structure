#include "HeapNode.hpp"
#define MAX_ELEMENT 200
#include <stdio.h>

class MaxHeap
{
    HeapNode node[MAX_ELEMENT];
    int size;
public:
    MaxHeap() : size(0) { }
    bool isEmpty() {return size == 0;}
    bool isFull() {return size ==MAX_ELEMENT -1;}
    
    HeapNode& getParent(int i){return node[i/2];}
    HeapNode& getLeft(int i){return node[i*2];}
    HeapNode& getRight(int i){return node[i*2+1];}
    
    void insert(int key) {
        if(isFull())
            return;
        int i= ++size; //증가된 힙 크기의 위치에서 시작(key삽입을 위해 힙 사이즈 늘리기)
       
        //트리를 거슬러 올라가면서 부모 노드와 비교하는 과정
        while(i!=1 && key>getParent(i).getKey())//i=1이거나 key값이 부모노드보다 작을때 최대힙이 완성되니까 stop
        {
            node[i] = getParent(i); //부모노드를 자신노드로 끌어내림
            i/=2; //한 레벨 상승
        }
        node[i].setKey(key); //최종위치에 데이터복사
    }
    HeapNode remove() {
        if(isEmpty())
            return NULL;
        HeapNode item = node[1]; //루트노드 (꺼낼요소)
        HeapNode last = node[size--]; //마지막노드 (하나 remove하니까 사이즈 줄이기)
        int parent = 1; //마지막노드의 위치를 루트로 옮김
        int child = 2; //루트의 왼쪽 자식
        while(child<=size){
            if(child<size && getLeft(parent).getKey() < getRight(parent).getKey()) //오른쪽자식이 더크면 child++해서 오른쪽 노드로 이동(최대힙이니까)
                child++;
            
            if(last.getKey() >= node[child].getKey()) // last값이 자식노드보다 크면 부모 자리에 안착
                break;
            node[parent] = node[child];
            parent = child;
            child *= 2;
        }
        node[parent] = last;  //최종위치에 마지막 노드 저장
        return  item; //루트노드 반환
    }
    HeapNode find() {return node[1];}
    
    void display() {
        for(int i=1, level=1; i<=size; i++){
            if(i==level){
                printf("\n");
                level *= 2;
            }
            node[i].display();
        }
        printf("\n-----------------------\n");
    }
};
