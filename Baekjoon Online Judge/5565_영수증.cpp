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

int sum, add;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> sum;

	for (int i = 0; i < 9; i++)
	{
		int tmp;
		cin >> tmp;
		add += tmp;
	}

	cout << sum - add << "\n";
}