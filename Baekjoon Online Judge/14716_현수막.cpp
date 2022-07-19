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
#define MAX 251

int graph[MAX][MAX];
int n, m, ans;
bool visited[MAX][MAX];

int ny[] = { 1, 1, 1, 0, 0, -1, -1, -1};
int nx[] = { -1,0, 1, -1, 1, -1, 0, 1};

void dfs(int y, int x){
    visited[y][x] = true;
    
    for(int i = 0; i<8; i++){
        int nextY = y+ny[i];
        int nextX = x + nx[i];
        
        if(nextY < 0 || nextX < 0 || nextY >=m || nextX >= n )
            continue;
        //갈수 있는곳이면
        if(graph[nextY][nextX] == 1 && !visited[nextY][nextX]){
            visited[nextY][nextX] = true;
            dfs(nextY, nextX);
        }
    }
}

int main(){
    
    cin>> m >>n;
    //그래프 초기화
    for(int i = 0; i<m; i++){
        for(int j =0; j<n; j++){
            cin >> graph[i][j];
        }
    }
    
    //끊어진거 있을 때마다 cnt ++
    for(int i = 0 ; i<m; i++){
        for(int j = 0; j<n; j++){
            if(graph[i][j] == 1 && !visited[i][j]){
                dfs(i, j);
                ans++;
            }
        }
    }
   
    cout<<ans<<"\n";
    
    return 0;
}
