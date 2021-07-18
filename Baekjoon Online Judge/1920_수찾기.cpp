#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<map>
#include<stack>
#include<string>
#include<cstring>
using namespace std;

int m, n;
vector <int> nums;
vector<int> isThere;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		nums.push_back(tmp);
	}

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int tmp;
		cin >> tmp;
		isThere.push_back(tmp);
	}


	sort(nums.begin(), nums.end());
	for (int i : isThere)
	{
		if (binary_search(nums.begin(), nums.end(), i)) // ¿÷¿∏∏È
		{
			cout << "1\n";
		}
		else	cout << "0\n";
	}

	return 0;



}