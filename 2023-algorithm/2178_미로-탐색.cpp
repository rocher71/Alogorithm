#include<iostream>
#include<algorithm>
#include<math.h>
#include <sstream>
#include<queue>
using namespace std;

int col, row;
int arr[101][101];
int visit[101][101];
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void bfs(int startY, int startX){
    queue<pair<int, int>> q;
    q.push({startY, startX});
    visit[startY][startX] = true;
    bool end = false;

    while(!q.empty()){
        int currY = q.front().first;
        int currX = q.front().second;
        q.pop();

        //cout

        for(int i = 0;i < 4; i++){
            int newY = currY + dy[i];
            int newX = currX + dx[i];

            if(newY < 0 || newX < 0 || newY >= col || newX >= row) continue;
            if(visit[newY][newX] || !arr[newY][newX]) continue;

            q.push({newY, newX});
            visit[newY][newX] = visit[currY][currX] + 1;
        }


        if(visit[col-1][row-1]){
            break;
        }
    }
}


int main(){

    cin >> col >> row;
    for(int i = 0; i< col; i++){
        string s;
        cin >> s;
        for(int j = 0; j<row; j++){
            int x = s[j] - '0';
            arr[i][j] = x;
        }
    }

    bfs(0, 0);
    cout << visit[col-1][row-1];

    return 0;
}
