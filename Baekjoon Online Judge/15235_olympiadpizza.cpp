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

int n, totalPpl;
vector<int> v, ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
		totalPpl += i;
	}

	for (int i = 0; i < n; i++)
		ans.push_back(-1);

	int count = 0, finishedEating = 0;
	while (finishedEating != totalPpl)
	{
		for (int i = 1; i <= n; i++)
		{
			if (v[i-1] <= 0) continue;
			++count;

			v[i-1]--;

			if (v[i-1] == 0)
			{
				ans[i-1] = count;
				finishedEating += i;
			}
			
			if (finishedEating == totalPpl)	break;
		}
	}
	
	for (int i : ans)
		cout << i << " ";

	cout << "\n";

}
