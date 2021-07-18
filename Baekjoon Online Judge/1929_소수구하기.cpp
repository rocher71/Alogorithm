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

int m, n;
vector<int> prime;
vector<int> p;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> m >> n;

	prime.push_back(-1);
	prime.push_back(-1);
	
	for (int i = 2; i <= n; i++)
		prime.push_back(i);

	for (int i = 2; i <= n; i++)
	{
		if (prime[i] == -1)	continue;
		for (int j = i; j <= n; j += i)
		{
			if (prime[j] == -1 || j == i)	continue;
			prime[j] = -1;
		}
	}

	for (int i : prime)
	{
		if (i == -1 || i < m) continue;
		p.push_back(i);
	}

	for (int i : p)
	{
		cout << i << "\n";
	}


}