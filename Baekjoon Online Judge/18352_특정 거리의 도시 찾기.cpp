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
#define MAX 300001

int nodes, edges, objDistance, start;
vector<int> graph[MAX];
queue<int> Q;
int dist[MAX];
bool visited[MAX], isAnswer = false;

int main(){
    cin>>nodes>>edges>>objDistance >>start;
    
    //단방향 그래프 초기화   
    for(int i = 0;i < edges; i++){
        int a, b;
        cin>>a>>b;
        graph[a].push_back(b);
    }
    
    //시작점이 있는 단방향 BFS
    Q.push(start);
    visited[start] = true;
    while(!Q.empty()){
        
        int curr = Q.front();
        Q.pop();
        
        for(int i =0;i <graph[curr].size(); i++){
            int next = graph[curr][i];
            if(!visited[next]){
                visited[next] = true;
                Q.push(next);
                dist[next] = dist[curr] + 1;
            }
        }
    }
    
    //시작점으로부터의 최단거리가 정답과 같은 점이 있으면 출력
    for(int i = 0; i<nodes+1; i++){
        if(dist[i] == objDistance){
            cout<< i<<"\n";
            isAnswer = true;
        }
            
    }
    //없으면 -1 출력
    if(!isAnswer) cout<<"-1\n";
    
    return 0;
}
