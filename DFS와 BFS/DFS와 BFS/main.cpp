#include "SrchALGraph.cpp"
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n,m,v,x,y;
    SrchALGraph g;
    vector<pair<int, int>> vp;
    cin>>n>>m>>v;
    for(int i=0;i<n;i++){
        g.insertVertex('1'+i);
    }
   
    
    for(int i=0; i<m; i++){
        cin>>x>>y;
        vp.push_back(make_pair(x, y));
    }

    sort(vp.begin(), vp.end());

    for(int i=0;i<m;i++){
        int edge1 = vp[i].first;
        int edge2 = vp[i].second;
        g.insertEdge(edge1-1, edge2-1);
//        cin>>x>>y;
//        g.insertEdge(x, y);
    }
    
    
//    g.display();
    g.DFS(v);
    printf("\n");
    g.resetVisited();
    g.BFS(v);
    
}
