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

//¼º°ø
int n;
vector<pair<int, int>> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		v.push_back({ x, y });
	}

	for (int i = 0; i < n; i++)
	{
		int myWeight = v[i].first;
		int myHeight = v[i].second;
		int myPlace = 0;
		for (int j = 0; j < n; j++)
		{
			if (j == i)		continue;

			int yourWeight = v[j].first;
			int yourHeight = v[j].second;

			if (yourWeight > myWeight && yourHeight > myHeight)
				myPlace++;
		}
		cout << myPlace + 1 << " ";
	}
	cout << "\n";


}
