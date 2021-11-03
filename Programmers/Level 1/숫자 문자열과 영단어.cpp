//성공

//#include<iostream>
//#include<algorithm>
//#include<queue>
//#include<vector>
//#include<map>
//#include<stack>
//#include<string>
//#include<cstring>
//#include<sstream>
//#include<deque>
//#include<cmath>
//using namespace std;
//
//string ans, str;
//int answer;
//
//void len3() {
//    str = str.substr(3, str.length() - 3);
//}
//
//void len4() {
//    str = str.substr(4, str.length() - 4);
//}
//
//void len5() {
//    str = str.substr(5, str.length() - 5);
//}
//
//int solution(string s) {
//    //str = s;
//    //int answer = 0;
//    //str = s;
//
//    //answer = stoi(ans);
////return answer;
//
//    //return answer;
//}
//
//int main() {
//
//    cin >> str;
//    for (int i = 0; i < str.length();)
//    {
//        bool isNum = str[i] - '0' <= 9 ? true : false;
//
//        if (isNum)
//        {
//            ans += str[i];
//            str = str.substr(1, str.length() - 1);
//            continue;
//        }
//
//        else
//        string subStr = str.substr(0, 3);
//
//        if (subStr == "one") {
//            ans += '1';
//            len3();
//        }
//        else if (subStr == "two") {
//            ans += '2';
//            len3();
//        }
//        else if (subStr == "thr") {
//            ans += '3';
//            len5();
//        }
//        else if (subStr == "fou") {
//            ans += '4';
//            len4();
//        }
//        else if (subStr == "fiv") {
//            ans += '5';
//            len4();
//        }
//        else if (subStr == "six") {
//            ans += '6';
//            len3();
//        }
//        else if (subStr == "sev") {
//            ans += '7';
//            len5();
//        }
//        else if (subStr == "eig") {
//            ans += '8';
//            len5();
//        }
//        else if (subStr == "nin") {
//            ans += '9';
//            len4();
//        }
//        else if (subStr == "zer") {
//            ans += '0';
//            len4();
//        }
//
//        if (str.length() == 0) break;
//
//    }
//
//    cout << ans;
//
//}

//프로그래머스
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

string ans, str;

void len3() {
    str = str.substr(3, str.length() - 3);
}

void len4() {
    str = str.substr(4, str.length() - 4);
}

void len5() {
    str = str.substr(5, str.length() - 5);
}

int solution(string s) {
    //str = s;
    int answer = 0;
    str = s;

    for (int i = 0; i < str.length();)
    {
        bool isNum = str[i] - '0' <= 9 ? true : false;

        if (isNum)
        {
            ans += str[i];
            str = str.substr(1, str.length() - 1);
            continue;
        }

        //else
        string subStr = str.substr(0, 3);

        if (subStr == "one") {
            ans += '1';
            len3();
        }
        else if (subStr == "two") {
            ans += '2';
            len3();
        }
        else if (subStr == "thr") {
            ans += '3';
            len5();
        }
        else if (subStr == "fou") {
            ans += '4';
            len4();
        }
        else if (subStr == "fiv") {
            ans += '5';
            len4();
        }
        else if (subStr == "six") {
            ans += '6';
            len3();
        }
        else if (subStr == "sev") {
            ans += '7';
            len5();
        }
        else if (subStr == "eig") {
            ans += '8';
            len5();
        }
        else if (subStr == "nin") {
            ans += '9';
            len4();
        }
        else if (subStr == "zer") {
            ans += '0';
            len4();
        }

        if (str.length() == 0) break;

    }
    answer = stoi(ans);
    return answer;
}