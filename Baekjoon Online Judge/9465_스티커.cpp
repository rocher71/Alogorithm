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
#define MAX 100001

/*
 1. dp[0][0] = arr[0][0], dp[1][0] = arr[1][0]
 2. dp[0][i], dp[1][i]를 왔다갔다 하면서 채움
 3. dp[j][i] => 해당 칸 까지 최대값
    dp[j][i] = 해당 칸 값 + max(대각선 x-1, 대각선 x-2);
    --> dp[j][i] = arr[j][i] + max(dp[(j+1)%2][i-1], dp[(j+1)%2][i-2]);
*/
int tc, n;
int arr[2][MAX], dp[2][MAX];

int solve(){
    dp[0][0] = arr[0][0];
    dp[1][0] = arr[1][0];
    int ans = max(dp[0][0], dp[1][0]);
    
    for(int i = 1; i<n; i++){
        for(int j = 0; j<= 1; j++){
            //dp[j(0,1)][i]
            if(j==1 && i==0) continue;
            if(i-2 < 0){
                dp[j][i] = arr[j][i] + dp[(j+1)%2][i-1];
            }
            else{
                dp[j][i] = arr[j][i] + max(dp[(j+1)%2][i-1], dp[(j+1)%2][i-2]);
            }
            ans = max(ans, dp[j][i]);
        }
    }
    
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>tc;
    for(int i = 0;i <tc; i++){
        cin>>n;
        for(int j = 0; j< n; j++){
            cin>> arr[0][j];
        }
        for(int j = 0; j< n; j++){
            cin>> arr[1][j];
        }
        
        cout << solve()<<"\n";
        
        //tc 한개 후 배열 초기화
        for(int j=0; j<2; j++){
            memset(arr[j], 0, sizeof(int)*MAX);
            memset(dp[j], 0, sizeof(int)*MAX);
        }
    }
    

}
