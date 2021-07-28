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

int n, cnt;

int color[101][101], visit[101][101];
int my[4] = { 0, 0, -1, 1 };
int mx[4] = { -1, 1, 0, 0 };
queue<pair<int, int>> q;

void bfs()
{
	
	/*visit[1][1] = true;
	q.push({ 1, 1 });
	*/
	/*for (int i = 0; i < 4; i++)
	{
		int ny = 1 + my[i];
		int nx = 1 + mx[i];

		if (ny<1 || nx<1 || ny>n || nx>n)
			continue;
		if (visit[ny][nx])
			continue;

		if (color[1][1] == color[ny][nx])
		{
			visit[ny][nx] = true;
			q.push({ ny, nx });
		}
	}*/

	bool finished = false;
	while (!finished)
	{
		for (int i = 1; i <= n; i++)
		{
			bool found = false;
			for (int j = 1; j <= n; j++)
			{
				if (!visit[i][j])
				{
					visit[i][j] = true;
					q.push({ i, j });
					found = true;
					break;
				}
			}
			if (found)
				break;
		}

		while (!q.empty())
		{
			int curry = q.front().first;
			int currx = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++)
			{
				int ny = curry + my[i];
				int nx = currx + mx[i];

				if (ny<1 || nx<1 || ny>n || nx>n)
					continue;
				if (visit[ny][nx])
					continue;

				if (color[ny][nx] == color[curry][currx])
				{
					visit[ny][nx] = true;
					q.push({ ny, nx });
				}
			}
		}
		cnt++;

		int check = 0;
		//bool check = false;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (!visit[i][j])
					break;
				else
					check++;
			}
		}
		if (check == n * n)
			break;
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			char a;
			cin >> a;

			if (a == 'R')
				color[i][j] = 1;
			else if (a == 'G')
				color[i][j] = 2;
			else if (a == 'B')
				color[i][j] = 3;
		}
	}

	bfs();
	cout << cnt << " ";

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (color[i][j] == 1)
				color[i][j] = 2;
		}
	}
	cnt = 0;
	memset(visit, false, sizeof(visit));

	bfs();
	cout << cnt << "\n";
	
	

}