#include <iostream>
#include <vector>
using namespace std;

int arr[50][50];
int ny[4] = {1, -1, 0, 0},
    nx[4] = {0, 0, 1, -1};
bool visit[50][50];
int m, n, k, tc;

// 인접 행렬 방식의 그래프로 구현, dfs로 탐색

void dfs(int currX, int currY){
    for(int i = 0; i<4; i++){
        int newX = currX + nx[i];
        int newY = currY + ny[i];
        
        if(newY < 0 || newX < 0 || newX >= m || newY >= n)
            continue;
        if(visit[newX][newY] || arr[newX][newY] == 0) //이미 방문한 곳 or 배추가 없는 곳 이면 pass
            continue;
        
        visit[newX][newY] = true;
        dfs(newX, newY);
    }
}

int main(){
    cin >>tc;
    
    for(int testCase = 0; testCase<tc; testCase++){
        int cnt = 0;
        cin>>m>>n>>k;
        for(int i = 0; i<k ; i++){
            int x, y;
            cin>>x>>y;
            arr[x][y] = 1;
        }
        
        for(int i  = 0; i< m ;i++){
            for(int j = 0; j<n; j++){
                if(!visit[i][j] && arr[i][j] == 1){ //배추가 있고 아직 방문하지 않은 곳일 경우 탐색 시작
                    visit[i][j] = true;
                    dfs(i, j);
                    cnt++;
                }
                    
            }
        }
        cout<<cnt <<"\n";
        
        //초기화
        for(int i=0;i <m; i++){
            for(int j=0; j<n; j++){
                arr[i][j] = 0;
                visit[i][j] = false;
            }
        }
        
    }
    
    
    
    
}
