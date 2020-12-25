#include "TopoSort.cpp"

int main(){
    TopoSortGraph g;
    for(int i=0; i<6; i++)
        g.insertVertex('1' + i);

    g.insertDirEdge(1, 4);
    g.insertDirEdge(4, 3);
    g.insertDirEdge(6, 2);
    g.insertDirEdge(2, 5);
    g.insertDirEdge(5, 4);
    g.insertDirEdge(2, 3);

    
    printf("Topology Sort: ");
    g.TopoSort();
    printf("\n");
    return 0;
}
