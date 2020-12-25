#pragma once
#include <stdio.h>
#define MAX_VTXS 10001

class AdjMatGraph{
protected:
    int size;
    char vertices[MAX_VTXS];
    int adj[MAX_VTXS][MAX_VTXS];
public:
    AdjMatGraph(){reset();}
    char getVertex(int i) {return vertices[i];}
    int getEdge(int i, int j) {return adj[i][j];}
    void setEdge(int i, int j, int val) {adj[i][j] = val;}
    bool isEmpty() {return size==0;}
    bool isFull() {return size>=MAX_VTXS;}
    
    void reset(){
        size = 0;
        for(int i=0;i<MAX_VTXS;i++){
            for(int j=0;j<MAX_VTXS;j++)
            setEdge(i, j, 0);
        }
    }
    
    void insertVertex(char name){
        if(!isFull())
            vertices[size++] = name;
        else
            printf("Error: 그래프 정점 개수 초과\n");
    }
    
    void display(FILE *fp = stdout) //유저가 파라메테로 파일명에 주면 파일로 출력, 안주면 화면에 출력
    {
        fprintf(fp, "%d\n", size);
        for(int i=0; i<size; i++){
            fprintf(fp, "%c", getVertex(i));
            for(int j=0; j<size; j++)
               fprintf(fp, "%3d", getEdge(i, j));
            fprintf(fp, "\n");
        }
    }
};

