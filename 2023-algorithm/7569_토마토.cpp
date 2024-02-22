#include<iostream>
#include<algorithm>
#include<math.h>
#include <sstream>
#include<queue>
using namespace std;

#define MAX_DAYS 1000000

struct Coordinate{
    int z;
    int y;
    int x;
    Coordinate(int z, int y, int x){
        this->z = z;
        this->y = y;
        this->x = x;
    }
};

int col, row, height, minDays = 0, tomatoCnt = 0, ripedTomatoCnt = 0;
int tomato[101][101][101], days[101][101][101];
queue<Coordinate> q;
int dz[6] = {-1, 1, 0, 0, 0, 0};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dx[6] = {0, 0, 0, 0, -1, 1};

void bfs(){
//    q.push(Coordinate(startZ, startY, startX));

    while(!q.empty()){
        int currZ = q.front().z;
        int currY = q.front().y;
        int currX = q.front().x;
        q.pop();

        for(int i = 0; i<6; i++){
            int newZ = currZ + dz[i];
            int newY = currY + dy[i];
            int newX = currX + dx[i];

            if(newZ <0 || newY < 0 || newX < 0 || newZ >= height || newY >= row || newX >= col) continue;
            if(tomato[newZ][newY][newX] == -1
                || !days[newZ][newY][newX]
                || days[newZ][newY][newX] <= days[currZ][currY][currX] + 1) continue;

            q.push(Coordinate(newZ, newY, newX));
//            days[newZ][newY][newX] = min(days[newZ][newY][newX], days[currZ][currY][currX] + 1);
            //다 익었는지 확인용
            if(days[newZ][newY][newX] == MAX_DAYS){
                ripedTomatoCnt++;
            }
            days[newZ][newY][newX] = days[currZ][currY][currX] + 1;
            tomato[newZ][newY][newX] = 1;
            minDays = max(minDays, days[newZ][newY][newX]);
        }
    }
}


int main(){
    fill(&days[0][0][0], &days[100][100][101], MAX_DAYS);

    cin >> col >> row >> height;
    for(int i = 0; i < height ; i++){
        for(int j = 0; j < row; j++){
            for(int k = 0; k < col; k++){
                cin >> tomato[i][j][k];
                //토마토 없는경우 패스
                if(tomato[i][j][k] == -1) continue;

                //익은 토마토인 경우 익은 토마토 개수 갱신, 익는 날짜 0으로 set
                if(tomato[i][j][k] == 1){
                    days[i][j][k] = 0;
                    ripedTomatoCnt++;
                }

                //익은, 안익은 토마토 모두 전체 토마토 개수는 세주기
                tomatoCnt++;
            }
        }
    }



    for(int i = 0; i < height ; i++){
        for(int j = 0; j < row; j++){
            for(int k = 0; k < col; k++){
//                if(tomato[i][j][k] && days[i][j][k] == 0) bfs(i, j, k);
                if(tomato[i][j][k] && days[i][j][k] == 0)
                    q.push(Coordinate(i, j, k));
            }
        }
    }

    if(q.empty()){
        cout << -1;
        return 0;
    }
    bfs();

    if(tomatoCnt != ripedTomatoCnt){
//        cout << "Tomato Count : " << tomatoCnt << "\nRiped tomato Count : " << ripedTomatoCnt <<"\n";
        cout << -1;
        return 0;
    }

    cout << minDays;


    return 0;
}
