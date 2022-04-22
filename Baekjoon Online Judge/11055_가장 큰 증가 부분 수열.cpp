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

/*
 1. dp[0] = arr[0]로 초기화.
 2. arr[1]~[n]까지 돌면서, arr[0]~arr[i-1]까지 2중 for문 돌며 arr[i]와 arr[j]를 비교.
 3. arr[i] > arr[j] 면 dp[i] = dp[j]+arr[i], 이걸 변수에 넣어 max로 계속 비교하여 가장 큰 값이 dp에 들어갈수 있도록 함.
 */


int arr[MAX], dp[MAX];
int n;

void solve(){
    for(int i = 1; i<n; i++){
        int maxDP = arr[i];
        for(int j = 0; j< i; j++){
            if(arr[i] <= arr[j]) continue;
            
            maxDP = max(maxDP, dp[j]+arr[i]);
        }
        dp[i] = maxDP;
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }
    
    dp[0] = arr[0];
    
    solve();
    
    sort(dp, dp+n);
    
    cout<< dp[n-1]<<"\n";

}
