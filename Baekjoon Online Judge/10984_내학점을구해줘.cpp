#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<iomanip>
#include<map>
#include<stack>
#include<string>
#include<cstring>
#include<sstream>
#include<deque>
using namespace std;

int t, n;
double c, g, sum, avgGrade;
vector<double> num, grade;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> n;
		for (int j = 0; j < n; j++)
		{
			cin >> c >> g;
			num.push_back(c);
			grade.push_back(g);
		}

		for (int j = 0; j < n; j++)
		{
			sum += num[j];
			avgGrade = avgGrade + (num[j] * grade[j]);
		}
		avgGrade = avgGrade / sum;
		cout << fixed << setprecision(0) << sum << " ";
		cout << fixed << setprecision(1) << avgGrade << "\n";

		sum = 0;
		avgGrade = 0;
		num.clear();
		grade.clear();

	}

}