#include "AdjListGraph.cpp"
#include "ArrayStack.cpp"

class TopoSortGraph: public AdjListGraph
{
public:
    TopoSortGraph(void){ }
    ~TopoSortGraph(void){ }
    
    void insertDirEdge(int u, int v){
        adj[u-1] = new Node(v-1, adj[u-1]);
    }
    
    void TopoSort(){
        ArrayStack s;
        int *inDeg = new int[size]; //진입차수
        for(int i=0; i<size; i++)
            inDeg[i] = 0;
        
        for(int i=0; i<size; i++){
            Node *node = adj[i];
            while(node!=NULL){
                inDeg[node->getId()]++;
                node = node->getLink();
            }
        }
        
        for(int i=0; i<size; i++)
            if(inDeg[i] == 0) s.push(i); //진입차수가0인 정점 스택에 삽입
        
        while(!s.isEmpty()){
            int w = s.pop();
            printf("%c ", getVertex(w));
            Node *node = adj[w];
            while(node!=NULL){
                int u = node->getId();
                inDeg[u]--;
                if(inDeg[u] == 0) s.push(u);
                node = node->getLink();
            }
        }
        printf("\n");
        delete [] inDeg;
    }
};
