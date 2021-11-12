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
string a, b, c, d;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> a >> b;

	for (int i = 2; i >= 0; i--)
	{
		c += a[i];
		d += b[i];
	}

	if (stoi(c) > stoi(d))
	{
		cout << c << "\n";
	}
	else
		cout << d << "\n";
}
