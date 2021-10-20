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

int k;
vector<int> grades;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int n;
		cin >> n;
		for (int j = 0; j < n; j++)
		{
			int tmp;
			cin >> tmp;
			grades.push_back(tmp);
		}
		sort(grades.begin(), grades.end());
		int minN = grades[0], maxN = grades[n - 1], diff = -99;

		for (int j = 0; j < n - 1; j++)
		{
			diff = max(diff, abs(grades[j] - grades[j + 1]));
		}

		cout << "Class " << i + 1 << "\n";
		cout << "Max " << maxN << ", Min " << minN << ", Largest gap " << diff << "\n";

		grades.clear();
	}
	

}
