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

int n, m, v;
vector<int> vec[1001];
bool visit[1001];
bool visitBfs[1001];

void bfs()
{
	
	queue<int> q;
	q.push(v);
	visitBfs[v] = true;

	while (!q.empty())
	{
		int curr = q.front();
		q.pop();
		cout << curr << " ";
		/*for (int next : vec[curr])
		{
			visit[next] = true;
			q.push(next);
		}*/
		

		for (int i = 0; i < vec[curr].size(); i++)
		{
			int nxt = vec[curr][i];
			if (visitBfs[nxt]) continue;
			visitBfs[nxt] = true;
			q.push(nxt);
		}
		//if (visitBfs[curr]) continue;
	}

}

void dfs(int curr)
{
	visit[curr] = true;
	cout << curr << " ";
	for (int i = 0; i < vec[curr].size(); i++)
	{
		int nxt = vec[curr][i];
		if (!visit[nxt])
			dfs(nxt);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m >> v;
	
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}

	for (int i = 0; i < 1001; i++)
	{
		sort(vec[i].begin(), vec[i].end());
	}

	dfs(v);
	cout << "\n";
	bfs();

	cout << "\n";


}