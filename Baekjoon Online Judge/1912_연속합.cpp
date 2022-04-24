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

// dp[i] = max(dp[i-1]+arr[i], arr[i])

int arr[MAX], dp[MAX];
int n;

void solve(){
    
    for(int i = 1; i<n; i++){
        dp[i] = max(dp[i-1] + arr[i], arr[i]);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>n;
    for(int i= 0; i<n; i++){
        cin >> arr[i];
    }
    
    dp[0] = arr[0];
    solve();
    
    sort(dp, dp+n);
    
    cout<< dp[n-1] << "\n";

}
