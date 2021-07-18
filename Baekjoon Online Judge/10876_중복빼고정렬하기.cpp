#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<map>
#include<stack>
#include<string>
#include<cstring>
using namespace std;

int n;
vector<int> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());
	vector<int>::iterator uni = unique(v.begin(), v.end());

	if (uni != v.end()) //중복이 존재한다면
	{
		v.erase(uni, v.end());
	}

	for (int i : v)
	{
		cout << i << " ";
	}

}