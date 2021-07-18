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
vector<int> v;
vector<int> prime;
int arr[1001];

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

	arr[0] = -1;
	for (int i = 1; i <= 1000; i++)
	{
		arr[i] = i;
	}
	arr[1] = -1;
	
	//arr[2] = 2 บฮลอ
	for (int i = 2; i <= 1000; i++)
	{
		if (arr[i] == -1) continue;
		for (int j = i; j <= 1000 ; j+= i)
		{
			if (arr[j] == -1 || j == i) continue;
			arr[j] = -1;
		}
	}

	for (int i : arr)
	{
		if (i == -1) continue;
		prime.push_back(i);
	}

	for (int i : v)
	{
		if (binary_search(prime.begin(), prime.end(), i))
		{
			cnt++;
		}
	}


	cout << cnt << "\n";


}