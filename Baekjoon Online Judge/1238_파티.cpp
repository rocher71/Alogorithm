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
#define MAX_CNT 1001
#define MAX_VAL 100001
#define pii pair<int, int>

int dist[MAX_CNT]; //dist[i] : i 정점까지 거리의 최소값
bool visited[MAX_CNT];
vector<pii> vec[MAX_VAL]; // vec[i] = {c, j} : i -> j 까지의 cost c
vector<int> result;

int n, m, dest;

void dijkstra(int sp){
    priority_queue<pii, vector<pii>, greater<pii>> pq; //비용, 현재 정점, 비용 적은 순 정렬
    
    //시작점 거리 0
    dist[sp] = 0;
    pq.push({0, sp});
    
    while (!pq.empty()) {
        int curr = pq.top().second;
        int currCost = pq.top().first;
        pq.pop();
        
        if (visited[curr])  continue;
        visited[curr] =true;
        
        for(int i = 0;i < vec[curr].size(); i++){
            int nxt = vec[curr][i].second;
            int nxtCost = vec[curr][i].first;
            
            //sp->nxt 값이 (지금까지 온 cost)+ (현재 정점->nxt cost) 보다 크면
            if(dist[nxt] > currCost + nxtCost){
                dist[nxt] = currCost + nxtCost;
                pq.push({dist[nxt], nxt});
            }
            
        }
        
        
    }
}

int main(){
    cin >> n>> m >>dest;
    
    for(int i = 1; i<=m; i++){
        int start, end, cost;
        cin>>start>>end>>cost;
        vec[start].push_back({cost, end});
    }
    
    //거리 최대값으로 초기화
    for(int i = 1; i<=n; i++)
        dist[i] = MAX_VAL;
    
    for(int i = 1; i<=n; i++){
        
        dijkstra(i);
        result.push_back(dist[dest]);
        
        memset(visited, false, sizeof(visited));
        memset(vec, 0, vec->size());
        for(int i = 1; i<=n; i++)
            dist[i] = MAX_VAL;
    }
    
    dijkstra(dest);
    for(int i = 1; i<=n; i++){
        result[i-1] += dist[i];
    }
    
    sort(result.begin(), result.end());
    cout<<result[n-1]<<"\n";
    
}
