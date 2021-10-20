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

int currHr, currMin, currSec, endHr, endMin, endSec, leftHr, leftMin, leftSec;
string currStr, endStr, leftStr;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> currStr >> endStr;
	
	endHr = stoi(endStr.substr(0, 2));
	endMin = stoi(endStr.substr(3, 2));
	endSec = stoi(endStr.substr(6, 2));;

	currHr = stoi(currStr.substr(0, 2));
	currMin = stoi(currStr.substr(3, 2));
	currSec = stoi(currStr.substr(6, 2));

	if (endSec < currSec)
	{
		endMin--;
		endSec += 60;
	}
	leftSec = endSec - currSec;

	if (endMin < currMin)
	{
		endHr--;
		endMin += 60;
	}
	leftMin = endMin - currMin;
	leftHr = endHr - currHr;

	if (leftHr < 0)
		leftHr += 24;

	
	if (leftHr <= 9 ) // 0~9
		leftStr += "0";
	leftStr += (to_string(leftHr) + ":");
	
	if (leftMin <= 9)
		leftStr += "0";
	leftStr += (to_string(leftMin) + ":");

	if (leftSec <= 9)
		leftStr += "0";
	leftStr += to_string(leftSec);

	cout << leftStr << "\n";
	
	
	

	
}
