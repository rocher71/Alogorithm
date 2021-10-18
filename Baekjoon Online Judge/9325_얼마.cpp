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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int price, n, sum = 0;
		cin >> price >> n;
		sum = price;
		for (int j = 0; j < n; j++)
		{
			int q, p;
			cin >> q >> p;
			sum += q * p;
		}
		cout << sum << "\n";
	}

}