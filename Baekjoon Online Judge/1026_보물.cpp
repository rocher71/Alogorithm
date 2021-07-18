#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<map>
#include<stack>
#include<string>
#include<cstring>
using namespace std;

int n, s = 0;
vector<int> a;
vector<int> b;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		a.push_back(tmp);
	}
	
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		b.push_back(tmp);
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	for (int i=0; i<n ; i++)
	{
		s += a[i] * b[n - i - 1];
	}

	cout << s << "\n";

	return 0;

}