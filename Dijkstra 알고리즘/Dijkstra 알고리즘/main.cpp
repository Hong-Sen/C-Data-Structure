#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#define MAX_ELEMENT 200
#define MAX_VTXS 1001
#define INF 9999 //값이 9999이상이면 간선이 없음을 표시
using namespace std;


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
};

class WGraph : public AdjMatGraph{
public:
    void insertEdge(int u, int v, int weight){
        if(weight>=INF)
            weight = INF;
        setEdge(u, v, weight);
    }
    
    bool hasEdge(int i, int j){
        return (getEdge(i, j) < INF);
    }
    
    void load(const char *filename ){
        FILE *fp = fopen(filename, "r");
        if(fp!=NULL){
            int n;
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

class WGraphDijkstra : public WGraph {
    int      dist[MAX_VTXS];    // 시작노드로부터의 최단경로 거리
    bool found[MAX_VTXS];    // 방문한 정점 표시  집합 S
    int path[MAX_VTXS];
    int fourVertext[MAX_VTXS];
    int update[MAX_VTXS];
public:
    int chooseVertex() {   // 가장 비용 적은 미방문 정점을 반환
        int min = INF;
        int minpos = -1;
        for( int i=0 ; i<size ; i++ )
        if( dist[i]< min && !found[i] ){
            min = dist[i];
            minpos = i;
        }
        return minpos;
    }
    void printDistance() { //모든 정점들의 dist[] 값 출력
        for( int i=0 ; i<size ; i++)
        cout<<dist[i]<<" ";
        printf("\n");
    }
    
    //1. 정점4개가 추가된 단계에서 정점 출력
    void printFourVertex(){
        for(int j=0; j<4; j++)
            cout<<(char)(fourVertext[j]+ 'A')<<" ";
        cout<<"\n";
    }

    //3. 업데이트되는 정점의 개수 출력
    void printUpdate() { //모든 정점들의 dist[] 값 출력
        for( int i=0 ; i<size ; i++)
        cout<<update[i]<<" ";
        printf("\n");
    }

    
    //5. 각 정점까지의 shortest path출력
    void printPath(){
        for(int i=1; i<size; i++){
            printf("[%c] " ,(char)(i + 'A'));
            cout<<(char)(i + 'A')<<" ";
            int index = i;
            while (1) {
                int next = path[index];
                if(next == 0){
                    cout<<"A\n";
                    break;
                }
                cout<<(char)(next + 'A')<<" ";
                index = next;
            }
        }
    }
    
    // Dijkstra의 최단 경로 알고리즘: start 정점에서 시작함.
    void ShortestPath( int start ) {
        for( int i=0 ; i<size ; i++) {  //초기화: dist[], found[]
            dist[i] = getEdge(start,i); //인접행렬 값 반환(간선 가중치)
            found[i] = false;           //처음에 S집합은 비어있음.
            if(getEdge(start, i) != INF)    path[i] = start;
            update[i] = 0;
        }
        found[start] = true;    // S에 포함
        dist[start] = 0;      // 최초 거리
        path[start] = 0;
        fourVertext[0] = 0;
        for( int i=0 ; i<size ; i++ ){
            //printf("Step%2d:", i+1);
            //printDistance();// 모든 dist[] 배열값 출력
            int u = chooseVertex(); // S에 속하지 않은 비용 가장 작은 정점 반환
            found[u] = true;        // 집합 S에 포함
            fourVertext[i+1] = u;
            
            //1.정점4개가 추가된 단계에서 정점 출력 + 2. 거리 출력
            if(i==3){
                printFourVertex();
                printDistance();
            }
                //1 3 4 2 2 2 1
            for( int w=0 ; w<size ; w++) {
                if( found[w] == false )//S에 속하지 않는 노드 w의 dist값 갱신
                    if( dist[u] + getEdge(u,w) < dist[w] ){
                        dist[w] = dist[u] + getEdge(u,w);
                        path[w] = u;
                    }
            }       // u를 거쳐가는 것이 최단 거리이면 dist[] 갱신
        }
       // printUpdate();
        printDistance();
        printPath();
    }
};


int main(){
    WGraphDijkstra g;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        g.insertVertex('A' + i);
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n+1; j++){
            string s;
            cin>>s;
            if(j!=0){
                int w = stoi(s);
                if(w != 0)   g.insertEdge(i, j-1, w);
            }
        }
    }

    g.ShortestPath( 0 );
  
}
