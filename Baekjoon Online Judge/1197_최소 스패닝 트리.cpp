#include <iostream>
#include <string>
#include <string.h>
#include<algorithm>
#include <queue>
#include <vector>
#include <map>
#include <stack>
#include <string>
#include <cstring>
#include <set>
#include <sstream>
#include <deque>
#include <cmath>
using namespace std;

int v, e, ans, cntEdges;
int parent[10002];
vector<pair<int, pair<int, int>>> graph;

//정점의 부모 찾기
int Find(int node){
    if(parent[node] == node)
        return node;
    return parent[node] = Find(parent[node]);
}
//정점들 이어주기
void Union(int a, int b){
    a = Find(a);
    b = Find(b);
    if(a != b)
        parent[a] = b;
}

int main(){
    cin>> v >>e;

    //기본 그래프 입력받기
    for(int i = 0 ;i<e; i++){
        int a, b, cost;
        cin>>a>>b>>cost;
        graph.push_back({cost, {a, b}});
    }

    for(int i = 1; i<=v; i++)
        parent[i] = i;

    //cost를 기준으로 오름차순 정렬
    sort(graph.begin(), graph.end());


    for(int i = 0;i < graph.size(); i++){
        int nodeA = graph[i].second.first;
        int nodeB = graph[i].second.second;
        //이미 연결돼있는 정점들일 경우 continue
        if(Find(nodeA) == Find(nodeB)) continue;

        //연결돼있지 않은 정점들일 경우 union 후 cost값 더해주기
        Union(nodeA, nodeB);
        ans += graph[i].first;

        //MST가 이미 만들어진 경우(간선의 개수가 정점수-1인 경우)
        if(++cntEdges == v-1) break;
    }
    cout<< ans <<"\n";

}
