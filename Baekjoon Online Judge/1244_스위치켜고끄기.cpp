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
//실패 푸는중

int n, stuCnt;
vector<pair<int, int>> stu;
//vector<int> light;
int light[102];

void toggleLight(int idx)
{
	if (light[idx] == 1)
		light[idx] = 0;
	else
		light[idx] = 1;
}

bool isSymmetric(int jmpNum, int idx)
{
	if (light[idx - jmpNum] == light[idx + jmpNum])
	{
		return true;
	}
	else return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 102; i++)
		light[i] = -1;

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int tmp;
		cin >> tmp;
		light[i] = tmp;
	}

	cin >> stuCnt;
	for (int i = 0; i < stuCnt; i++)
	{
		int gender, num;
		cin >> gender >> num;
		stu.push_back({ gender, num });
	}

	//학생 한명씩 수행
	for (int i = 0; i < stuCnt; i++)
	{
		int gender = stu[i].first;
		int switchNum = stu[i].second;

		if (gender == 1)//남자
		{
			for (int j = switchNum; j <= n; j += switchNum)
			{
				toggleLight(j);
			}
		}
		else //여자
		{
			int jmpNum = min(switchNum - 1, n - switchNum); // 대칭 가능 수 중 가장 큰거
			int maxJmpNum = -1;
			//대칭인지 찾기
			for (int j = jmpNum; j >= 1 ; j--)
			{
				if (switchNum == 1 || switchNum ==  n) break;
				if (isSymmetric(j, switchNum))
				{
					maxJmpNum = j;
					break;
				}
			}
			if (maxJmpNum == -1) maxJmpNum = 0;
			//구간 내 불 켜기/끄기
			for (int j = switchNum - maxJmpNum; j <= switchNum + maxJmpNum; j++)
			{
				toggleLight(j);
			}

		}
	}

	for (int i = 1; i <= n; i++)
	{
		cout << light[i] << " ";
		if (i % 20 == 0)
			cout << "\n";
	}


}
