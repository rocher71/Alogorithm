#include <iostream>
#include <string>
#include <queue>
using namespace std;
#define MAX 101

//bfs, 한 칸씩 보되 visit[] 필요 없고 cnt[]로 다음 칸 갈 때마다 +1 해줘서 최종 최단거리 계산

int arr[MAX][MAX], cnt[MAX][MAX];
int x, y;
int nx[4] = {0, 0, 1, -1},
    ny[4] = {1, -1, 0, 0};


void bfs(){
    queue<pair<int, int>> q;
    q.push({1, 1});
    
    while(!q.empty()){
        int currY = q.front().first;
        int currX = q.front().second;
        q.pop();
        
        for(int i =0;i <4; i++){
            int newX = currX + nx[i];
            int newY = currY + ny[i];
            
            if(newX < 1 || newY < 1 || newX > x || newY > y)
                continue;
            if(arr[newY][newX] == 0 || cnt[newY][newX] != 0) //가지 못하는 칸 or 이미 간 칸은 pass
                continue;
            
            cnt[newY][newX] = cnt[currY][currX] + 1;
            q.push({newY, newX});
            
        }
    }
    
}

int main(){
    cnt[1][1] = 1;
    cin>>y>>x;
    for(int i = 1; i<=y; i++){
        string str;
        cin>>str;
        
        for(int j =1 ; j <= x; j++){
            arr[i][j] = str[j-1] - '0';
        }
    }
    
    bfs();
    
    cout<< cnt[y][x]<<"\n";
}
