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

double n;
vector<double> v;

int aver()
{
	if (v.size() == 1) return v[0];
	double sum = 0.0, ans = 0.0;
	for (double i : v)
		sum += i;
	
	ans = sum / n;
	
	return int(round(ans));
}

int med()
{
	if (v.size() == 1) return v[0];
	return v[int(n) / 2];
}

int freq()
{
	if (v.size() == 1) return v[0];

	vector<pair<int,int>> freV; //빈도, 값

	int prevNum = v[0], num = 0;
	for (int i = 1; i < n; i++)
	{
		//중복x
		if (v[i] != v[i - 1] && num == 0) continue;

		//중복된 애들의 연속 끝
		if (v[i] != v[i - 1]) 
		{
			freV.push_back({ num, v[i - 1] });
			num = 0;	
			continue;
		}

		if (i == n-1 && v[i] == v[i - 1])
		{
			num++;
			freV.push_back({ num, v[i - 1] });
			continue;
		}

		//중복 ing
		num++;
		
	}

	sort(freV.begin(), freV.end());
	if (freV.size() == 0) return v[1];
	if (freV.size() == 1) return freV[0].second;
	
	return freV[1].second;
}

int range()
{
	return v[v.size() - 1] - v[0];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	cin >> n;

	for (int i = 0; i < int(n); i++)
	{
		double tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());

	cout << aver() << "\n" << med() << "\n" << freq() << "\n" << range() << "\n";
}
