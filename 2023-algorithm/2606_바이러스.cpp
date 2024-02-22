#include<iostream>
#include<algorithm>
#include<math.h>
#include <sstream>
#include<queue>
using namespace std;

int cnt;
vector<int> graph[101];
bool visit[101];

void dfs(int x){
    visit[x] = true;

    for(int child : graph[x]){
        if(!visit[child]){
            dfs(child);
            cnt++;
        }
    }
}

int main(){

    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    dfs(1);

    cout<< cnt;

    return 0;
}
