#include "WGraph.cpp"
#include "MinHeap.cpp"
#include "VertexSets.cpp"

class WGraphMST : public WGraph{
public:
    void Kruskal(){  //kruskal의 최소비용신장트리
        MinHeap heap; //오름차순 정렬
        for(int i=0; i<size-1; i++){
            for(int j=i+1; j<size; j++){
                if(hasEdge(i, j))   heap.insert(getEdge(i, j), i, j);
            }
        }
        
        VertexSets set(size);    //size개의 집합
        int edgeAccepted = 0;    //선택된 간선의 수
        while(edgeAccepted < size-1){         //(n-1)개의 edge가 삽일될때까지
            HeapNode e = heap.remove();       //가장작은 edge선택
            int uset = set.findSet(e.getV1());    //v1이 속한 집합의 루트
            int vset = set.findSet(e.getV2());    //v2가 속한 집합의 루트
            if(uset != vset){       //사이클이 생기지 않으면 MST삽입
                printf("간선추가: %c - %c (비용:%d)\n", getVertex(e.getV1()), getVertex(e.getV2()), e.getKey());
                set.unionSets(uset, vset);
                edgeAccepted++;
            }
        }
    }
};
