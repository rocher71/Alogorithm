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

float n;
vector<double> v;
pair<int, int> arr[4001]; //개수, 값

int aver()
{
	float sum = 0, ans = 0;
	for (double i : v)
	{
		sum += i;
	}
	ans = sum / n;
	
	int firstDec = int(ans * 10) % 10;

	if (firstDec < 5) return int(ans);
	else return int(ans) + 1;
	
}

float med()
{
	sort(v.begin(), v.end());
	if (int(n) % 2 != 0) //홀수
		return v[int(n) / 2];

	//짝수
	return (v[n / 2 - 1] + v[n / 2]) / 2.0;
}

int freq()
{
	sort(arr, arr + int(n), greater<>()); //여러개인 순으로 정렬
	vector <int> secondMin;
	for (int i = 0; i < n; i++)
	{
		secondMin.push_back(arr[i].second);
		if (arr[i].first != arr[i + 1].first)
			break;
	}
	if (secondMin.size() == 1) return secondMin[0];

	sort(secondMin.begin(), secondMin.end());
	return secondMin[1];
}

int range()
{
	sort(v.begin(), v.end());
	return v[v.size() - 1] - v[0];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		arr[i].second = i;
	}

	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
		arr[tmp].first++;
	}

	cout << aver() << "\n" << med() << "\n" << freq() << "\n" << range() << "\n";
}
