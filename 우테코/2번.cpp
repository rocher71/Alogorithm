#include <string>
#include<iostream>
#include <vector>

using namespace std;

string solution(vector<string> log) {
    string answer = "";

    int intAns = 0;
    for (int i = 0; i < log.size() ; i+= 2)
    {
        string strt = log[i], end = log[i + 1];
        int strtHr = stoi(strt.substr(0, 2));
        int strtMin = stoi(strt.substr(3, 2));
        int endHr = stoi(end.substr(0, 2));
        int endMin = stoi(end.substr(3, 2));

        int cntHr = endHr - strtHr;
        int cntMin = endMin - strtMin;

        if (cntMin < 0)
        {
            cntMin += 60;
            cntHr--;
        }

        cntMin += cntHr * 60;

        if (cntMin < 5)
            cntMin = 0;
        else if (cntMin > 105)
            cntMin = 105;

        intAns += cntMin;

    }

    string hrStr = to_string(intAns / 60);
    string minStr = to_string(intAns % 60);

    if (hrStr.length() == 1)
        answer += "0";
    answer += hrStr + ":";

    if (minStr.length() == 1)
        answer += "0";
    answer += minStr;



    return answer;
}

int main() {
    vector<string> inputV = { "01:00", "08:00", "15:00", "15:04", "23:00", "23:59" };

    cout << solution(inputV) << " ";

    
}