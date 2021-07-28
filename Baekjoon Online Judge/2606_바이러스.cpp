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

int n, m, cnt;
vector<int> v[101];
bool visit[101];

void dfs(int curr)
{
	visit[curr] = true;
	for (int i = 0; i < v[curr].size(); i++)
	{
		int nxt = v[curr][i];
		if (!visit[nxt])
		{
			dfs(nxt);
			cnt++;
		}
			
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	dfs(1);
	cout << cnt << "\n";
}