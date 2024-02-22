#include<iostream>
#include<algorithm>
#include<math.h>
#include <sstream>

using namespace std;

int T;
int arr[5][5];
bool visit[52][52];
int movY[4] = {1, -1, 0, 0};
int movX[4] = {0, 0, 1, -1};

void dfs(int y, int x, int vertical, int horizontal){
    visit[y][x] = true;

    for(int i = 0;i <4; i++){
        int nxtY = y + movY[i];
        int nxtX = x + movX[i];

        if(nxtY < 0 || nxtX <0 || nxtY >= vertical || nxtX >= horizontal)
            continue;
        if(visit[nxtY][nxtX] || !arr[nxtY][nxtX])
            continue;
        dfs(nxtY, nxtX, vertical, horizontal);
    }
}


int main(){
    
    cin >> T;
    while (T--){
        int m, n, k, cnt = 0;

        cin >> m >> n >> k;
        for(int i = 0;i <k; i++){
            int x, y;
            cin >> x >> y;
            arr[y][x] = 1;
        }

        for(int i = 0;i < n; i++){
            for(int j = 0; j < m; j++){
                if(!arr[i][j] || visit[i][j]) continue;
                dfs(i, j, n, m);
                cnt++;
            }
        }
        cout << cnt <<"\n";

        fill(&arr[0][0], &arr[51][52], 0);
        fill(&visit[0][0], &visit[51][52], false);
    }

    return 0;
}
