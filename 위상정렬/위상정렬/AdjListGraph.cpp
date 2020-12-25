#include <stdio.h>
#define MAX_VTXS 256

class Node{
protected:
    int id; //정점의id
    Node *link; //다음노드의 포인터 
public:
    Node(int i,Node *l=NULL) : id(i),link(l){ }
    ~Node() {
        if(link != NULL) delete link;
    }
    int getId() {return id;}
    Node* getLink() {return link;}
    void setLink(Node* l) {link = l;}
};

class AdjListGraph{
protected:
    int size;
    char vertices[MAX_VTXS]; //정점 정보
    Node* adj[MAX_VTXS]; // 각 정점의 인접 리스트
public:
    AdjListGraph() : size(0) { }
    ~AdjListGraph() {reset();}
    void reset()
    {
        size = 0;
        for(int i=0;i<size;i++)
            if(adj[i]!=NULL)
                delete adj[i];
    }
    
    bool isEmpty() {return (size==0);}
    bool isFull() {return (size>=MAX_VTXS);}
    char getVertex(int i) {return vertices[i];}
    
    void insertVertex(char val)
    {
        if(!isFull()){
            vertices[size] = val;
            adj[size++] = NULL;
        }
        else
            printf("Error: 그래프 정점 개수 초과\n");
    }
    
    void insertEdge(int u,int v)
    {
        adj[u] = new Node (v,adj[u]);
        adj[v] = new Node (u,adj[v]); //방향그래프이면 이건 주석처리해야함!
    }
    
    void display()
    {
        printf("%d\n",size);
        for(int i=0; i<size ;i++){
            printf("%c  ", getVertex(i));
            for(Node *v=adj[i]; v!=NULL; v=v->getLink() )
                printf("  %c",getVertex(v->getId()));
            printf("\n");
        }
    }
    Node* adjacent(int v) {return adj[v];}
};

