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
#define MAX 10001

/*
 dp[i] = max(dp[i-1], dp[i-3]+arr[i-1]+arr[i]); // OOX XOO 비교
 dp[i] = max(dp[i], dp[n-2]+arr[n]); // 위에 두개 중 큰것, OXO 비교
 */

int arr[MAX], dp[MAX];
int n;

int solve(){
    
    for(int i = 2; i<n; i++){
//        dp[i] = max(dp[i-3] + arr[i-1] + arr[i], dp[i-3] + arr[i-2] + arr[i]); // XOO OXO 비교
//        dp[i] = max(dp[i], dp[i-3]+ arr[i-2] + arr[i-1]); // 위에 두개 중 큰것, OOX 비교
        dp[i] = max(dp[i-1], dp[i-3]+arr[i-1]+arr[i]); // OOX XOO 비교
        dp[i] = max(dp[i], dp[i-2]+arr[i]); // 위에 두개 중 큰것, OXO 비교
        // OXO 할 때 dp[n-2] + arr[n] 으로해야함. dp[i-3] + arr[i-2] + arr[i] 으로 하면 안됨.
        // OOX도 마찬가지로 dp[i-1] 맞, dp[i-3]+ arr[i-2] + arr[i-1] 틀. 후자로 하면 OOOX 도 들어감!!
    }
    return dp[n-1];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 0;i <n; i++){
        cin>>arr[i];
    }
    
    dp[0] = arr[0];
    dp[1] = arr[0] + arr[1];
    
    cout << solve() <<"\n";


}
