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

//성공
int n, m;
map<string, int> nameMap;
string nameArr[100001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	nameArr[0] = -1;

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		string str;
		cin >> str;
		nameMap.insert({ str, i });
		nameArr[i] = str;
	}

	for (int i = 1; i <= m; i++)
	{
		string cmd;
		cin >> cmd;
		if (cmd[0] - '0' <= 9) //숫자인 경우
		{
			cout << nameArr[stoi(cmd)] << "\n";
		}
		else
		{
			cout << nameMap.find(cmd)->second << "\n";
		}
	}
}
