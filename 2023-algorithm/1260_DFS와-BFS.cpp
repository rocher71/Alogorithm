#include<iostream>
#include<algorithm>
#include<math.h>
#include <sstream>
#include<queue>

using namespace std;

vector<int> graph[1001];
bool visit[1001];

void dfs(int x){
    visit[x] = true;
    cout << x <<" ";

    for(auto child : graph[x]){
        if(!visit[child]) dfs(child);
    }
}

void bfs(int start){
    queue<int> q;
    q.push(start);
    visit[start] = true;

    while(!q.empty()){
        int curr = q.front();
        q.pop();
        cout << curr << " ";

        for(auto child : graph[curr]){
            if(!visit[child]){
                q.push(child);
                visit[child] = true;
            }
        }
    }
}


int main(){

    int n, m, v;
    cin >> n >> m >> v;
    for(int i = 0; i<m; i++){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    for(int i = 0; i<= n; i++){
        if(graph[i].size() == 0) continue;
        sort(&graph[i][0], &graph[i][0] + graph[i].size());
    }

    dfs(v);
    fill(visit, visit + 1001, 0);
    cout << "\n";
    bfs(v);




    return 0;
}
