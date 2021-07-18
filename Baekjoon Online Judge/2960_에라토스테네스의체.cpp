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

int n, k, cnt;
vector<int>nums;
vector<int> prime;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;

	nums.push_back(-1);
	nums.push_back(-1);
	for (int i = 2; i <= n; i++)
		nums.push_back(i);

	for (int i = 2; i <= n; i++)
	{
		if (nums[i] == -1)
		{
			continue;
		}
		for (int j = i; j <= n; j += i)
		{
			if (nums[j] == -1)	continue;
			
			cnt++;
			if (cnt == k)
			{
				cout << j << "\n";
				return 0;
			}
			nums[j] = -1;
		}
	}

}