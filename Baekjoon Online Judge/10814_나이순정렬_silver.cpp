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

//성공
int n;
vector<pair<int, int>> v; //나이, 가입순서
string nameHash[100001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int age;
		string name;
		cin >> age >> name;
		v.push_back({ age, i });
		nameHash[i] = name;
	}

	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++)
	{
		cout << v[i].first << " " << nameHash[v[i].second] << "\n";
	}
	cout << "\n";

}
