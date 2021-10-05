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

int n, year, month, date;
string name;
vector<string> nameVec;
vector<int> dateVec, monthVec;
vector<pair<int, int>> yearVec; //year, idx
vector<pair<int, int>> youngVec, oldVec;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> name >> date >> month >> year;
		nameVec.push_back(name);
		dateVec.push_back(date);
		monthVec.push_back(month);
		yearVec.push_back({ year, i });
	}

	sort(yearVec.begin(), yearVec.end());

	int young = 9999, old = 0;
	for (int i = 0; i < n; i++)
	{
		if (yearVec[i].first == young)
		{
			youngVec.push_back({ yearVec[i].first, i });
		}
		else if(yearVec[i].first < young)
		{
			young = yearVec[i].first;
			youngVec.clear();
			youngVec.push_back({ yearVec[i].first, i });
		}

		if (yearVec[i].first == old)
		{
			oldVec.push_back({ yearVec[i].first, i });
		}
		else if (yearVec[i].first > old)
		{
			young = yearVec[i].first;
			oldVec.clear();
			oldVec.push_back({ yearVec[i].first, i });
		}
	}

	int leastMonth = 13, mostMonth = 0;
	for (int i = 0; i < youngVec.size(); i++)
	{
		yearVec.clear();
		if (monthVec[youngVec[i].second] < leastMonth)
		{

		}
	}



}
