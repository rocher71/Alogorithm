#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<map>
#include<stack>
#include<string>
#include<cstring>
#include<set>
#include<sstream>
#include<deque>
#include<cmath>
using namespace std;

//½ÇÆÐ¤Ð

int arr[501][501], visited[501][501];
int n, m, maxN = -1;
int ny[4] = { 0, 0, 1, -1 };
int nx[4] = { 1, -1, 0, 0 };

int maxSum(int y, int x)
{
	visited[y][x] = true;
	int sum = arr[y][x];

	for (int i = 0; i < 3; i++)
	{
		int currY = y;
		int currX = x;
		
		int maxArnd = -1, maxIdx = -1;
		for (int j = 0; j < 4; j++)
		{
			int newY = currY + ny[j];
			int newX = currX + nx[j];

			if (newY < 0 || newX<0 || newY > n - 1 || newX > m - 1)
				continue;
			if (visited[newY][newX] == true)
				continue;

			maxArnd = max(maxArnd, arr[newY][newX]);

			if (maxArnd != arr[newY][newX])
				continue;

			maxIdx = j;
		}
		y = currY + ny[maxIdx];
		x = currX + nx[maxIdx];

		visited[y][x] = true;

		sum += arr[y][x];
	}
	memset(visited, -1, sizeof(visited));
	return sum;
}

int onlyAround(int y, int x)
{	
	int sum = arr[y][x];
	vector <int> v;
	for (int j = 0; j < 4; j++)
	{
		int newY = y + ny[j];
		int newX = x + nx[j];

		if (newY < 0 || newX<0 || newY > n - 1 || newX > m - 1)
			continue;
		if (visited[newY][newX] == true)
			continue;

		v.push_back(arr[newY][newX]);
	}
	sort(v.begin(), v.end(), greater<int>());
	if (v.size() == 0)	return -1;
	
	
	for (int i = 0; i < v.size(); i++)
	{
		if (i == 3) break;
		sum += v[i];
	}
		

	return sum;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int dfs = maxSum(i, j);
			maxN = max(maxN, dfs);

			int b = onlyAround(i, j);
			maxN = max(maxN, b);
		}
	}

	cout << maxN << "\n";
}
