#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<map>
#include<stack>
#include<string>
#include<cstring>
#include<sstream>
#include<deque>
using namespace std;

#define MAX 301

int n;
int arr[MAX];
int dp[MAX];

int Max(int a, int b) {
	if (a > b) return a;
	return b;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	dp[1] = arr[1]; //첫 번째 계단 까지의 최대값은 무조건 1 
	dp[2] = arr[1] + arr[2]; // 두 번째 계단 최대값은 무조건 1+2
	dp[3] = Max(arr[1] + arr[3], arr[2] + arr[3]);  //세 번째 최대값은 max(1+3 || 2+3)

	// dp[n] = max( 이전 계단을 밟지 않고 온 경우 || 이전 계단을 밟고 온 경우 )
	// dp[n] = max( dp[n-2] + array[n]|| dp[n-3] + array[n] + array[n-1] )

	for (int i = 4; i <= n; i++)
	{
		dp[i] = Max(dp[i - 2] + arr[i], arr[i - 1] + dp[i - 3] + arr[i]);
	}

	cout << dp[n] << "\n";


}