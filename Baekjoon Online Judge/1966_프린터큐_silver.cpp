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

//푸는중

queue<pair<int, int>> q;
int tc;
vector<pair<int, int>> v, v2;
vector<int> ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, idx;
	cin >> n >> idx;
	for (int i = 0; i < n; i++)
	{
		int priority;
		cin >> priority;
		v.push_back({ priority, i });
	}
	ans.resize(n);
	int count = 0;
	while (v.size() != 0)
	{
		for (int i = 0; i < v.size(); i++)
		{
			if (v.size() == 0) break;

			vector<pair<int, int>> v2 = v;
			sort(v2.begin(), v2.end(), greater<>());
			if (v2[0].second == v[0].second) //가장큰게 0번 idx에 있을 때
			{
				count++;
				ans[v2[0].second] = count;
				v.erase(v.begin());
			}
			else
			{
				v.push_back({ v[0].first, v[0].second });
				v.erase(v.begin());
			}

		}
	}


	cout << ans[idx] << "\n";
	
	/*vector<pair<int, int>> v2 = v;
	for (int i = 0; i < v2.size(); i++)
	{
		cout << v2[i].first << "\n";
	}*/

}
