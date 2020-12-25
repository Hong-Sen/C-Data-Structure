//가중치그래프
//MST (minimum spaning tree)
//Kruskal algorithm

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1001
using namespace std;

int m,n; //n=정점수 m=연결선의 수
int parent[MAX];
vector<pair<int, pair<int, int>>> v; //가중치,(정점,정점)
int sum;

//부모찾기
int Find(int x){
    if(parent[x] == x) return x;
    else return parent[x] = Find(parent[x]);
}


void Union(int x,int y){
    x = Find(x);
    y = Find(y);
    if(x != y)  parent[y] = x;
}

bool sameParent(int x, int y){
    x = Find(x);
    y = Find(y);
    if(x == y)  return true;
    else    return  false;
}

void MST(){
    sort(v.begin(), v.end()); //가중치값으로 오름차순 정렬
    //부모 초기값 설정
    for(int i=1; i<=n; i++){
        parent[i] = i;
    }
    for(int i=0; i<=m; i++){
        if(!sameParent(v[i].second.first, v[i].second.second)){
            Union(v[i].second.first, v[i].second.second);
            sum += v[i].first;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int a,b,c;
        cin>>a>>b>>c;
        v.push_back(make_pair(c, make_pair(a, b)));
    }
    MST();
    cout<<sum<<"\n";
    
}
