#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<map>
#include<stack>
#include<string>
#include<cstring>
using namespace std;

int n;
vector<pair<int, string>> v;
vector<string> strVec;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string tmp;
		cin >> tmp;
		strVec.push_back(tmp);
	}

	//sort(strVec.begin(), strVec.end());
	//if (unique(strVec.begin(), strVec.end()) != strVec.end()) //�ߺ��� ������ (�ߺ����� �־�� �����Ⱚ �ּ� != ������ ���ּ�)
	//{
	//	sort(strVec.begin(), strVec.end());
	//	strVec.erase(unique(strVec.begin(), strVec.end()), strVec.end()); //�ߺ�����
	//}
	//	

	sort(strVec.begin(), strVec.end());
	vector<string>::iterator uni = unique(strVec.begin(), strVec.end());
	if (uni != strVec.end())
	{
		strVec.erase(uni, strVec.end());
	}

	
	for (string s : strVec)
	{

		v.push_back({ s.length(), s });
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i].second << "\n";
	}

	return 0;


}