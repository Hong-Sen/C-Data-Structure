#ifndef HeapNode_h
#define HeapNode_h

#include <stdio.h>

class HeapNode{
    int key;
public:
    HeapNode(int k=0) : key(k) { }
    void setKey(int k) {key = k;}
    int getKey() {return key;}
    void display() {printf("%4d",key);}
};

#endif
