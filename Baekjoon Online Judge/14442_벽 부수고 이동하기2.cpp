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
int n, m, k;
int arr[MAX][MAX], dist[MAX][MAX][11]; //dist[i][j][k] = i, j 까지 k번 벽 부술고 갈 때의 최단거리
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

int main(){
    cin >> n >> m >>k;
    for(int i = 1; i<=n; i++){
        string tmp;
        cin>>tmp;
        for(int j = 0; j< m; j++){
            arr[i][j+1] = tmp[j] - '0';
        }
    }
    
    queue<pair<int, pair<int, int>>> q; // <벽 부순 횟수 <y, x>>
    q.push({0, {1, 1}});
    dist[1][1][0] = 1;
    
    while (!q.empty()) {
        int crashCnt = q.front().first;
        int y = q.front().second.first;
        int x = q.front().second.second;
        q.pop();
        
        // 끝까지 온 경우
        if(y == n && x == m ){
            cout << dist[y][x][crashCnt] <<"\n";
            return 0;
        }
        
        for(int i = 0; i<4; i++){
            int nxtY = y+ dy[i];
            int nxtX = x + dx[i];
            int nCnt = crashCnt+  arr[nxtY][nxtX];
            //범위 밖인 경우
            if(nxtY <1 || nxtX <1 || nxtY > n || nxtX > m) continue;
            //벽 부술 횟수 없는 경우
            if(nCnt > k) continue;
            //새로운 벽 부술 횟수로 이미 새로운 y,x 칸의 횟수가 있고, 해당 값이 더 최단거리면 방문x
            if(dist[nxtY][nxtX][nCnt] && dist[nxtY][nxtX][nCnt] <= dist[y][x][crashCnt] + 1) continue;
            dist[nxtY][nxtX][nCnt] = dist[y][x][crashCnt] + 1;
            
            q.push({nCnt, {nxtY, nxtX}});
//            cout << "y, x : ( " << y <<" , " << x << " )\n";
//            cout << "nxtY, nxtX : ( " << nxtY <<" , " << nxtX << " )\n";
            //cout<< " ( " << y <<" , " << x<<" )  ->  ( " <<  nxtY << " , " << nxtX <<" ) \n";
        }
        
        
    }
    cout<< -1 <<"\n";
    return 0;
}
