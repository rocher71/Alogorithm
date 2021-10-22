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

string n;
vector<int> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	
	for (int i = 0; i < n.length(); i++)
	{
		v.push_back(n[i] - '0');
	}

	sort(v.begin(), v.end(), greater<>());

	for (int i : v)
		cout << i;
	cout << "\n";
}
