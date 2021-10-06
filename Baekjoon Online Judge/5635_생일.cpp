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
string name, youngest, oldest;
vector<string> nameVec;
vector<int> dateVec, monthVec;
vector<pair<int, int>> yearVec; //year, idx
vector<pair<int, int>> youngVec, oldVec, oldSameMonth;


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

	int young = 0, old = 9999;
	for (int i = 0; i < n; i++)
	{
		int idx = yearVec[i].second;
		if (yearVec[i].first == young)
		{
			youngVec.push_back({ yearVec[i].first, idx });
		}
		else if(yearVec[i].first > young)
		{
			young = yearVec[i].first;
			youngVec.clear();
			youngVec.push_back({ yearVec[i].first, idx });
		}

		if (yearVec[i].first == old)
		{
			oldVec.push_back({ yearVec[i].first, idx });
		}
		else if (yearVec[i].first < old)
		{
			old = yearVec[i].first;
			oldVec.clear();
			oldVec.push_back({ yearVec[i].first, idx });
		}
	}
	
	if (youngVec.size() == 1)
	{
		youngest = nameVec[youngVec[0].second];
	}
	if (oldVec.size() == 1)
	{
		oldest = nameVec[oldVec[0].second];
	}

	if (youngVec.size() == 1 && oldVec.size() == 1)
	{
		cout << youngest << "\n" << oldest << "\n";
		return 0;
	}

	yearVec.clear();
	int youngMonth = 0, oldMonth = 13;
	//연도 같은 사람들의 달 비교
	for (int i = 0; i < youngVec.size(); i++)
	{
		int idx = youngVec[i].second;
		if (youngVec.size() == 1) //젤 어린 연도 한명일 때
		{
			yearVec.push_back({ monthVec[idx], idx });
			break;
		}

		if (monthVec[idx] > youngMonth) //젤 어린 애 달이 한명이면 변수 벡터 초기화
		{
			youngMonth = monthVec[idx];
			yearVec.clear();
			yearVec.push_back({ monthVec[idx], idx });
		}
		else if (monthVec[idx] == youngMonth)
		{
			yearVec.push_back({ monthVec[idx], idx });
		}
	}

	for (int i = 0; i < oldVec.size(); i++)
	{
		int idx = oldVec[i].second;

		if (oldVec.size() == 1) //젤 많은 연도 한명일 때
		{
			oldSameMonth.push_back({ monthVec[idx], idx });
			break;
		}

		if (monthVec[idx] < oldMonth) //젤 많은 달이 한명이면 변수 벡터 초기화
		{
			oldMonth = monthVec[idx];
			oldSameMonth.clear();
			oldSameMonth.push_back({ monthVec[idx], idx });
		}
		else if (monthVec[idx] == oldMonth)
		{
			oldSameMonth.push_back({ monthVec[idx], idx });
		}
	}

	if (yearVec.size() == 1)
	{
		youngest = nameVec[yearVec[0].second];
	}
	if (oldSameMonth.size() == 1)
	{
		oldest = nameVec[oldSameMonth[0].second];
	}

	if (yearVec.size() == 1 && oldSameMonth.size() == 1)
	{
		cout << youngest << "\n" << oldest << "\n";
		return 0;
	}


	sort(yearVec.begin(), yearVec.end());
	sort(oldSameMonth.begin(), oldSameMonth.end());

	youngest = nameVec[yearVec[yearVec.size()-1].second];
	oldest = nameVec[oldSameMonth[0].second];

	cout << youngest << "\n" << oldest << "\n";

	return 0;

}
