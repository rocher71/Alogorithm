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
#include<regex>
using namespace std;

int n, upCnt = 999999999, downCnt = 999999999, m, hunCnt = 9999999999;
vector<string> mal;
//regex findStr;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		string tmp;
		cin >> tmp;
		mal.push_back(tmp);

	}
	
	hunCnt = abs(100 - n);
	if (m == 10 || hunCnt == 0)
	{
		cout << abs(100 - n) << "\n";
		return 0;
	}

	

	
	
	for (int i = 0; i < 500000; i++)
	{
		int downNum = n - i;
		string downNumStr = to_string(downNum);
		bool isMatch = false;
		for (int j = 0; j < m; j++)
		{
			if (downNumStr.find(mal[j]) != string::npos)
			{
				isMatch = true;
				break;
			}

		}
		if (isMatch) continue; //���峭 ��ȣ�� ������ �� ���� �� ���� ��ȣ��

		//���峭 ��ȣ ������ �� ������ �ִ� ��ȣ��
		downCnt = n - downNum;
		downCnt += to_string(downNum).length();

		
		break;
	}

	for (int i = 0; i < 500000; i++)
	{


		int upNum = n + i;
		string upNumStr = to_string(upNum);
		bool isMatch = false;
		//���峭 ������ ��ȣ�� �ִ���

		for (int j = 0; j < m; j++)
		{
			if (upNumStr.find(mal[j]) != string::npos)
			{
				isMatch = true;
				break;
			}

		}
		if (isMatch) continue; //���峭 ��ȣ�� ������ �� ���� �� ���� ��ȣ��

		//���峭 ��ȣ ������ �� ������ �ִ� ��ȣ��
		upCnt = upNum - n;
		upCnt += to_string(upNum).length();
		break;
	}

	cout << min(min(downCnt, upCnt), hunCnt) << "\n";



}
