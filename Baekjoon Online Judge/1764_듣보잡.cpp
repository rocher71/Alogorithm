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

//¼º°ø
int n, m;
vector<string> ans;
set<string> see, hear;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		see.insert(s);
	}
	for (int i = 0; i < m; i++)
	{
		string s;
		cin >> s;
		hear.insert(s);
	}

	int ansCnt = 0;

	//set<string>::iterator iter;
	for (const auto& name : see)
	{
		auto iter = hear.find(name);
		if (iter == hear.end())	continue;
		ans.push_back(name);
	}

	cout << ans.size() << "\n";
	for (string name : ans)
		cout << name << "\n";

	

}
