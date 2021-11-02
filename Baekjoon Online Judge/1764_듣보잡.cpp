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
#include<cmath>
using namespace std;

int n, m;
vector<string> see, hear, ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		see.push_back(s);
	}
	for (int i = 0; i < m; i++)
	{
		string s;
		cin >> s;
		hear.push_back(s);
	}

	sort(see.begin(), see.end());
	sort(hear.begin(), hear.end());
int ansCnt = 0;
	for (int i = 0; i < n; i++)
	{
		
		for (int j = 0; j < m - ansCnt; j++)
		{
			if (see[i][0] < hear[j][0]) break;
			if (see[i] == hear[j])
			{
				ans.push_back(hear[j]);
				hear.erase(hear.begin() + j);
				ansCnt++;
			}
		}
	}

	sort(ans.begin(), ans.end());
	cout << ans.size() << "\n";

	for (string s : ans)
		cout << s << "\n";


}
