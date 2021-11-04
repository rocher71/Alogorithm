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
		if (isMatch) continue; //고장난 번호가 있으면 즉 누를 수 없는 번호면

		//고장난 번호 없으면 즉 누를수 있는 번호면
		downCnt = n - downNum;
		downCnt += to_string(downNum).length();

		
		break;
	}

	for (int i = 0; i < 500000; i++)
	{


		int upNum = n + i;
		string upNumStr = to_string(upNum);
		bool isMatch = false;
		//고장난 리모콘 번호가 있는지

		for (int j = 0; j < m; j++)
		{
			if (upNumStr.find(mal[j]) != string::npos)
			{
				isMatch = true;
				break;
			}

		}
		if (isMatch) continue; //고장난 번호가 있으면 즉 누를 수 없는 번호면

		//고장난 번호 없으면 즉 누를수 있는 번호면
		upCnt = upNum - n;
		upCnt += to_string(upNum).length();
		break;
	}

	cout << min(min(downCnt, upCnt), hunCnt) << "\n";



}
