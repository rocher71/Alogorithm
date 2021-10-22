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

//¼º°ø

vector<pair<int, int>> v;
vector<int> scores;
vector<int> idx;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 1; i <= 8; i++)
	{
		int tmp;
		cin >> tmp;
		v.push_back({ tmp, i });
	}

	sort(v.begin(), v.end());
	for (int i = 1; i <= 5; i++)
	{
		scores.push_back(v[8 - i].first);
		idx.push_back(v[8 - i].second);
	}

	int sum = 0;
	for (int i : scores)
		sum += i;

	sort(idx.begin(), idx.end());

	cout << sum << "\n";
	for (int i : idx)
		cout << i << " ";
	cout << "\n";



}
