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

	//vector<pair<int,int>> frev; //��, ��

	//int prevnum = v[0], num = 0;
	//for (int i = 1; i < n; i++)
	//{
	//	//�ߺ�x
	//	if (v[i] != v[i - 1] && num == 0) continue;

	//	//�ߺ��� �ֵ��� ���� ��
	//	if (v[i] != v[i - 1]) 
	//	{
	//		frev.push_back({ num, v[i - 1] });
	//		num = 0;	
	//		continue;
	//	}

	//	if (i == n-1 && v[i] == v[i - 1])
	//	{
	//		num++;
	//		frev.push_back({ num, v[i - 1] });
	//		continue;
	//	}

	//	//�ߺ� ing
	//	num++;
	//	
	//}

	//sort(frev.begin(), frev.end());
	//if (frev.size() == 0) return v[1];
	//if (frev.size() == 1) return frev[0].second;
	//
	//return frev[1].second;

	map<int, int> cntM; //{����, ����}
	for (int i = 0; i < v.size(); i++)
	{
		if (cntM.find(v[i]) != cntM.end()) //�ѹ� ���� ����
		{
			cntM.find(v[i])->second++;
			continue;
		}
		//ó�� ���� ����
		cntM.insert({ v[i], 1 });
	}

	vector<pair<int, int>> cntNums; //{����, ����}
	for (auto iter : cntM)
	{
		cntNums.push_back({ iter.second, iter.first });
	}

	sort(cntNums.begin(), cntNums.end());
	if (cntNums.size() <= 1)	return cntNums[0].second;

	//�ΰ� �̻�, ���� ���� �������� ���
	if (cntNums[0].second != cntNums[1].second)	return cntNums[1].second;
	return cntNums[0].second;

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
