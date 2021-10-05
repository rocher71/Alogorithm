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
//bronze

int m, n, sum;
vector<int> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> m >> n;

	int sqrtM = sqrt(m);

	if (pow(sqrtM, 2) < m)
		sqrtM++;

	for (int i = sqrtM; i <= sqrt(n); i++)
	{
		v.push_back(pow(i, 2));
	}

	if (v.size() == 0)
	{
		cout << -1 << "\n";
		return 0;
	}

	for (int i : v)
	{
		sum += i;
	}

	cout << sum << "\n" << v[0];
	
}
