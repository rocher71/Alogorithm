#include<iostream>
#include<algorithm>
#include<math.h>
#include <sstream>

using namespace std;

int n, m, cnt;
bool visit[1001];
vector<int> graph[1001];

void dfs(int x){
    visit[x] = true;

    for(int i =0 ;i < graph[x].size(); i++){
        int child = graph[x][i];
        if(!visit[child]) dfs(child);
    }
}


int main(){
    cin>> n>>m;
    for(int i = 0; i<m; i++){
        int x, y;
        cin >> x >>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    for(int i = 1; i<=n; i++){
        if(visit[i]) continue;
        dfs(i);
        cnt++;
    }

    cout<< cnt;
    return 0;
}
