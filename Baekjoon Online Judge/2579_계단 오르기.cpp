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

	dp[1] = arr[1]; //ù ��° ��� ������ �ִ밪�� ������ 1 
	dp[2] = arr[1] + arr[2]; // �� ��° ��� �ִ밪�� ������ 1+2
	dp[3] = Max(arr[1] + arr[3], arr[2] + arr[3]);  //�� ��° �ִ밪�� max(1+3 || 2+3)

	// dp[n] = max( ���� ����� ���� �ʰ� �� ��� || ���� ����� ��� �� ��� )
	// dp[n] = max( dp[n-2] + array[n]|| dp[n-3] + array[n] + array[n-1] )

	for (int i = 4; i <= n; i++)
	{
		dp[i] = Max(dp[i - 2] + arr[i], arr[i - 1] + dp[i - 3] + arr[i]);
	}

	cout << dp[n] << "\n";


}