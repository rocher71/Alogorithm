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
#define R 0
#define G 1
#define B 2

//arr[집번호][색]
//dp[집번호][색 i] = 해당 집을 i 색상으로 칠하는데까지의 최소값
int arr[MAX][3], dp[MAX][3], ans[3];
int n;

int main(){
    
    cin>>n;
    for(int i= 0; i<n; i++){
        for(int j = 0; j<3; j++){
            cin>>arr[i][j];
        }
    }
    
    //dp 초기화
    dp[0][R] = arr[0][R];
    dp[0][G] = arr[0][G];
    dp[0][B] = arr[0][B];
    
    // 해당 집을 R로 칠할거면 그 직전 집 dp에서 R말고 다른 색으로 칠한것 중 최소값 + 해당 집 R 칠하는데 드는 비용
    for(int i = 1; i <= n-1; i++){
        dp[i][R] = min(dp[i-1][G], dp[i-1][B]) + arr[i][R];
        dp[i][G] = min(dp[i-1][R], dp[i-1][B]) + arr[i][G];
        dp[i][B] = min(dp[i-1][R], dp[i-1][G]) + arr[i][B];
    }
    
    for(int i = 0; i<3; i++){
        ans[i] = dp[n-1][i];
    }
    
    sort(ans, ans+3);
    cout << ans[0]<<"\n";
    
    return 0;
    
}
