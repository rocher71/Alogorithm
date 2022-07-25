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
#define MAX 501

int n, ans = 1;
int arr[MAX][MAX], dp[MAX][MAX];
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

int dfs(int y, int x){
    if(dp[y][x] != -1) return dp[y][x];
    dp[y][x] = 1;
    
    
    for(int i = 0; i<4; i++){
        int nxtY = y + dy[i];
        int nxtX = x + dx[i];
        
        if(nxtY < 0 || nxtX < 0 || nxtX >= n || nxtY >= n) continue;
        if(arr[nxtY][nxtX] <= arr[y][x])     continue;
        
        int tmp = 1;
        tmp += dfs(nxtY, nxtX);
        dp[y][x] = max(tmp, dp[y][x]);
        ans = max(ans, dp[y][x]);
    }
    
    return dp[y][x];
}

int main(){
    cin>>n;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n ;j++){
            cin >> arr[i][j];
            dp[i][j] = -1;
        }
    }
    
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n ;j++){
            if(dp[i][j] == -1 )
                dfs(i, j);
        }
    }
    
    cout<<ans<<"\n";

    return 0;
}
