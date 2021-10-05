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

int n, p, c;
string name;
vector<pair<int, string>> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> p;
		for (int j = 0; j < p; j++)
		{
			cin >> c >> name;
			v.push_back({ c, name });
		}
		sort(v.begin(), v.end(), greater<>());
		cout << v[0].second << "\n";
		v.clear();
	}

	return 0;



}
