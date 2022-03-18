#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 101

vector<int> vec[MAX];
int n, m, per1, per2;
int cnt[MAX];

//bfs로 풀되, bool visited[] 필요 없이 촌수 계산하는 cnt[] 배열 사용

void bfs(){
    queue<int> q;
    q.push(per1);
    
    while (!q.empty()) {
        int curr = q.front();
        
        if(curr == per2) return; // 찾는 사람 닿았을 경우.
        
        q.pop();
        for(int i = 0; i<vec[curr].size(); i++){
            
            
            int nxt = vec[curr][i];
            if(cnt[nxt] != 0) continue; //이미 촌수가 정해진 경우
            cnt[nxt] = cnt[curr] + 1;
            q.push(nxt);
        }
    }
}

int main(){
    cin>>n>>per1>>per2>>m;
    
    for(int i = 0; i<m; i++){
        int a, b;
        cin>>a>>b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    
    bfs();
    
    if(cnt[per2] == 0) cout<<"-1\n";
    else cout<< cnt[per2] <<"\n";
    
}
