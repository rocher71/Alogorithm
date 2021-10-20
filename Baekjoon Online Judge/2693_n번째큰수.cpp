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

int t;
vector<int> v;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;
	for (int i = 0; i < t; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			int tmp;
			cin >> tmp;
			v.push_back(tmp);
		}
		sort(v.begin(), v.end());
		cout << v[7] << "\n";
		v.clear();
	}

}
