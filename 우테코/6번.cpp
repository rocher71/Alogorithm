#include <string>
#include <vector>
#include<iostream>

using namespace std;

string solution(double time, vector<vector<string>> plans) {
    string answer = "È£Ä¡¹Î";

    double monStrt = 13, friEnd = 18;

    for (int i = 0; i < plans.size(); i++)
    {
        double dept = 0, arr = 0, overCnt = 0;

        //Ãâ¹ß½Ã°£
        if(plans[i][1].length() == 3)
            dept = stoi(plans[i][1].substr(0, 1));
        else
            dept = stoi(plans[i][1].substr(0, 2));
        
        if (plans[i][1][plans[i][1].length() - 2] == 'P') //PM ÀÌ¸é
            dept += 12;
        
        //µµÂø½Ã°£
        if (plans[i][2].length() == 3)
            arr = stoi(plans[i][2].substr(0, 1));
        else
            arr = stoi(plans[i][2].substr(0, 2));

        if (plans[i][2][plans[i][2].length() - 2] == 'P') //PM ÀÌ¸é
            arr += 12;

        //cout << "dept, arr : " << dept << ", " << arr << " \n";

        double deptOver = friEnd - dept;
        if (deptOver < 0) // Åð±Ù ÈÄ Ãâ¹ß
            deptOver = 0;
        if (deptOver > 8.5) //±Ý Ãâ±Ù Àü Ãâ¹ß
            deptOver = 8.5;

        cout << "deptOver : " << deptOver << "\n";

        double arrOver = arr - monStrt;
       
        if (arrOver < 0) //Ãâ±Ù Àü µµÂø
            arrOver = 0;
        if (arrOver > 5) //¿ù Åð±Ù ÈÄ µµÂø
            arrOver = 5;

        //cout << "arrOver : " << arrOver << "\n";

        overCnt = deptOver + arrOver;
        //cout << "overCnt : " << overCnt << "\n";
        if (overCnt <= time)
            answer = plans[i][0];
    }


    return answer;
}

int main() {
    //cout << solution(3.5, { {"È«Äá", "11PM", "9AM"} , {"¿¤¿¡ÀÌ", "3PM", "2PM"} });
    cout << solution(1, { {"È«Äá", "8AM", "10PM"} });
}