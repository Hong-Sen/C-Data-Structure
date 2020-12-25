#include "AdjMatGraph.cpp"
#define INF 9999 //값이 9999이상이면 간선이 없음을 표시

class WGraph : public AdjMatGraph{
public:
    void insertEdge(int u, int v, int weight){
        if(weight>INF)
            weight = INF;
        setEdge(u, v, weight);
    }
    
    bool hasEdge(int i, int j){
        return (getEdge(i, j) < INF);
    }
    
    void load(const char *filename ){
        FILE *fp = fopen(filename, "r");
        if(fp!=NULL){
            int n,val;
            fscanf(fp, "%d", &n);
            for(int i=0;i<n;i++){
                char str[80];
                int val;
                fscanf(fp, "%s", str);
                insertVertex(str[0]);
                for(int j=0;j<n;j++){
                    fscanf(fp, "%d", &val);
                    insertEdge(i, j, val);
                }
            }
            fclose(fp);
        }
    }
};
