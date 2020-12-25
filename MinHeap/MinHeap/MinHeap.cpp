#include <stdio.h>
#define MAX_ELEMENT 200

class HeapNode{
    int key;
public:
    HeapNode(int k=0) : key(k) { }
    void setKey(int k) {key = k;}
    int getKey() {return key;}
    void display() {printf("%4d",key);}
};
class MinHeap
{
    HeapNode node[MAX_ELEMENT];
    int size;
public:
    MinHeap() : size(0) { }
    bool isEmpty() {return size == 0;}
    bool isFull() {return size == MAX_ELEMENT -1;}
    
    HeapNode& getParent(int i){return node[i/2];}
    HeapNode& getLeft(int i){return node[i*2];}
    HeapNode& getRight(int i){return node[i*2+1];}
    
    void insert(int key){
        if(isFull())
            return;
        int i = ++size;
        while(i!=1 && key<getParent(i).getKey())
        {
            node[i] = getParent(i);
            i/=2;
        }
        node[i].setKey(key);
    }
    
    HeapNode remove(){
        if(isEmpty())
            return NULL;
        HeapNode item = node[1];
        HeapNode last = node[size--];
        
        int parent = 1;
        int child = 2;
        while(child<=size){
            if(child<size && getLeft(parent).getKey() > getRight(parent).getKey())
                child++; //오른쪽 노드가 더 작으면 오른쪽 노드로 이동(최소힙이니까 더 작은 자식노드로 이동)
            if(last.getKey()<=node[child].getKey())
                break;
            node[parent] = node[child];
            parent = child;
            child*=2;
        }
        node[parent] = last;
        return item;
    }
    
    void display(){
        for(int i=1,level=1; i<=size; i++){
            if(i==level){
                printf("\n");
                level*=2;
            }
            node[i].display();
        }
        printf("\n------------------------\n");
    }
};

int main(){
    MinHeap heap;
    heap.insert(3);
    heap.insert(6);
    heap.insert(7);
    heap.insert(12);
    heap.insert(13);
    heap.insert(15);
    heap.insert(20);
    heap.display();
    

    heap.remove();
    heap.display();
    
    
}
