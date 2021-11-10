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

//성공
int tc, n;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> tc;
	for (int i = 0; i < tc; i++)
	{
		cin >> n;
		map<string, vector<string>> m;
		for (int j = 0; j < n; j++)
		{

			string name, typ;
			cin >> name >> typ;

			auto item = m.find(typ);

			if (item == m.end()) //처음 입력받는 종류
			{
				m.insert({ typ, {name} });
				continue;
			}

			//이미 있는 종류면
			item->second.push_back(name);


		}
		//경우의수 구하기 (모든 경우의 수 - 1)
		int ans = 1;
		for (auto k = m.begin(); k != m.end(); k++)
		{
			ans *= k->second.size() + 1;
		}
		cout << ans - 1 << "\n";

	}

}
