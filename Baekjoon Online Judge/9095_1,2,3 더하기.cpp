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
#define MAX 11

int testCase;
int arr[MAX];

int solve(int n)
{
	if (arr[n] != 0) return arr[n];

	for (int i = 4; i <= n; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
	}
	return arr[n];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;

	cin >> testCase;
	for (int i = 0; i < testCase; i++)
	{
		int num;
		cin >> num;
		cout << solve(num) << "\n";
	}

}