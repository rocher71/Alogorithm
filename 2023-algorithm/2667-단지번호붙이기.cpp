#include<iostream>
#include<algorithm>
#include<math.h>
#include <sstream>
#include<queue>
using namespace std;

int n;
int arr[26][26];
bool visit[26][26];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
vector<int> ans;

int dfs(int currY, int currX, int cnt){
    visit[currY][currX] = true;

    for(int i = 0; i<4; i++){
        int newY = currY + dy[i];
        int newX = currX + dx[i];

        if(newY < 0 || newX < 0 || newY >= n || newX >= n) continue;
        if(!arr[newY][newX] || visit[newY][newX]) continue;

        cnt = dfs(newY, newX, cnt + 1);
    }
    return cnt;
}

int main(){

    cin >> n;
    for(int i = 0;i < n; i++){
        string str;
        cin >> str;
        for(int j = 0; j< n; j++){
            arr[i][j] = str[j] - '0';
        }
    }

    for(int i = 0; i<n ;i++){
        for(int j = 0; j<n ; j++){
            if(!arr[i][j] || visit[i][j]) continue;
            int cnt = dfs(i, j, 1);
            ans.push_back(cnt);
        }
    }

    sort(ans.begin(), ans.end());

    cout<< ans.size() << "\n";
    for(int i : ans){
        cout << i << "\n";
    }

    return 0;
}
