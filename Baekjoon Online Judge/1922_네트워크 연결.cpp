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
#define MAX 1001

int n, m, ans;
vector<pair<int, pair<int, int>>> graph; // cost, a, b
int parent[MAX];


int Find(int a){
    if(parent[a] == a) return a;
    return parent[a] = Find(parent[a]);
}

void Union(int a, int b){
    a = Find(a);
    b = Find(b);
    if( a == b) return;
    parent[a] = b;
}

int main(){
    cin>>n>>m;
    for(int i = 0; i<m; i++){
        int cost, a, b;
        cin >> a>> b >> cost;
        graph.push_back({cost, {a, b}});
    }

    for(int i = 1; i<= n; i++)
        parent[i] = i;

    sort(graph.begin(), graph.end());

    int cnt = 0;
    for(int i =  0; i<graph.size(); i++){
        int cost = graph[i].first;
        int x = graph[i].second.first;
        int y = graph[i].second.second;
        if(Find(x) == Find(y)) continue;
        Union(x, y);
        ans += cost;
        if(++cnt == n-1) break;
    }
    cout<< ans <<"\n";
}
