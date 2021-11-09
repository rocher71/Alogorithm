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

int n, m, sum;
vector<int> v, asc, desc;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		sum += tmp;
		v.push_back(tmp);
		asc.push_back(sum);
	}

	for (int i = 0; i < n; i++)
	{
		desc.push_back(sum);
		sum -= v[i];
	}

	sum = 0;
	for (int i = 0; i < m; i++)
	{
		sum = 0;
		int x, y;
		cin >> x >> y;
		x--;
		y--;

		if (x == 0)
		{
			cout << asc[y] << "\n";
			continue;
		}
		/* 시간초과 나는 코드
		for (int j = x - 1; j <= y - 1; j++)
		{
			sum += v[j];
		}
		cout << sum << "\n";
		*/

		cout << asc[y] - asc[x-1] << "\n";
	}

}
