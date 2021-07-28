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
#define MAX 10000001

//½ÇÆÐ

long long int _min, _max;
//vector<long long int> nums;
vector<long long int> nono;
long long int nums[MAX];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> _min >> _max;
	/*
	if (_max >= MAX)
		_max = MAX;*/
	
	nums[0] = -1;
	/*
	for (long long int i = 1; i <= MAX; i++)
		nums[i] = i;*/

	for (long long int i = 2; i <= _max; i++)
	{
		bool isBreak = false;
		if (nums[i] == -1)	continue;
		if (i * i > _max)
		{
			isBreak = true;
			break;
		}
		for (long long int j = i*i; j <= _max; j += i*i)
		{
			if (j >= MAX)  break;
			if (nums[j] == -1 || i == j)	continue;
			nums[j] = -1;
		}
		//if (isBreak) break;
	}

	//for (long long int i : nums)
	//{
	//	if (i == -1) continue;
	//	nono.push_back(i);
	//}

	for (long long int i = 0; i <= _max; i++)
	{
		if (nums[i] == -1) continue;
		nums[i] = i;
		if(i>=_min && i <= _max)
			nono.push_back(1);
	}

	/*int cnt = 0;
	for (int i : nono)
	{
		if (i < _min) continue;
		if (i > _max) break;
		cnt++;
	}*/

	cout << nono.size() << "\n";



}