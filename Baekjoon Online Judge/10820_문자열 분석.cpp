#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<map>
#include<stack>
#include<string>
#include<cstring>
#include<set>
#include<sstream>
#include<deque>
#include<cmath>
using namespace std;

//����
string str;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (true) {
		getline(cin, str);
		if (str == "")
			break;
		int small = 0, cap = 0, num = 0, space = 0;
		for (int i = 0; i < str.length(); i++)
		{
			auto ascii = str[i] - '0';
			if (str[i] >= 'a' && str[i] <= 'z') //�ҹ���
				small++;
			else if (str[i] >= 'A' && str[i] <= 'Z') //�ҹ���
				cap++;
			else if (str[i] >= '0' && str[i] <= '9') //�ҹ���
				num++;
			else if (str[i] == ' ')
				space++;

			
		}
		cout << small << " " << cap << " " << num << " " << space << "\n";
	}
	

}
