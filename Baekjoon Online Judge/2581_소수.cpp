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

int m, n, sum;
vector<int> primes;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> m >> n;
	for (int i = m; i <= n; i++)
	{
		for (int j = 2; j <= i; j++)
		{	
			if (j == i)
			{
				primes.push_back(i);
			}
			if (i % j == 0) break;
			
			

		}
	}

	if (primes.size() == 0)
	{
		cout << -1 << "\n";
		return 0;
	}

	for (int i : primes) {
		sum += i;
	}

	cout << sum << "\n" << primes[0] << "\n";
}
