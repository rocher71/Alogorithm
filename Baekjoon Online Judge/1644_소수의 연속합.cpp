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

int n, cnt;
vector<int> nums;
vector<int> prime;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	nums.push_back(-1);
	nums.push_back(-1);

	for (int i = 2; i <= n; i++)
		nums.push_back(i);

	for (int i = 2; i <= n; i++)
	{
		if (nums[i] == -1) continue;
		for (int j = i; j <= n; j+= i)
		{
			if (nums[j] == -1 || i == j) continue;
			nums[j] = -1;
		}
	}

	for (int i : nums)
	{
		if (i == -1) continue;
		prime.push_back(i);
	}

	if (binary_search(prime.begin(), prime.end(), n))
		cnt++;

	for(int i = 0; i < prime.size(); i++)
	{
		int sum = prime[i];
		//if (i == prime.size() - 1) break;
		for (int j = i + 1; j < prime.size() ; j++)
		{
			sum += prime[j];
			if (sum == n)
			{
				cnt++;
			}
			else if (sum > n)
			{
				break;
			}
		}
	}

	cout << cnt;


}