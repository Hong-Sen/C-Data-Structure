#include <stdio.h>
#define MAX_VTXS 256

class Node{
protected:
    int id;
    Node *link;
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
        for(int i=0;i<size;i++)
        if(adj[i]!=NULL)
            delete adj[i];
        size = 0;
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
        // 새로운 노드가 추가되면 연결리스트의 끝에 insert되게 하도록 변경됨.
        //insert edge(u,v)
        if(adj[u] == NULL)
            adj[u] = new Node(v,NULL);
        else{
            Node* p = adj[u];
            while(p->getLink()!=NULL)
                p=p->getLink();
            p->setLink(new Node(v,NULL));
            
            //insert(v,u)
            if(adj[v]==NULL)
                adj[v] = new Node(u,NULL);
            else{
                Node* p = adj[v];
                while(p->getLink() != NULL)
                    p=p->getLink();
                p->setLink(new Node(u,NULL));
            }
        }
    }
    
    void load(const char *filename)
    {
        FILE *fp = fopen(filename,"r");
        if(fp!=NULL){
            int n,val;
            fscanf(fp, "%d", &n);
            for(int i=0; i<n; i++){
                char str[80];
                fscanf(fp, "%s", str);
                insertVertex(str[0]);
                for(int j=0; j<n; j++){ //read matrix
                    fscanf(fp, "%d", &val);
                    if(i>j){
                        if(val != 0)
                            insertEdge(i, j);
                    }
                    
                }
            }
            fclose(fp);
        }
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




