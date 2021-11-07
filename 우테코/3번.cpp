#include <string>
#include <vector>
#include<iostream>
#include<map>

using namespace std;

int solution(vector<string> ings, vector<string> menu, vector<string> sell) {
    int answer = 0;

    map<string, int> ingPriceMap, menuProfitMap;

    for (int i = 0; i < ings.size(); i++)
    {
        string ing = ings[i].substr(0, 1);
        int ingPrice = stoi(ings[i].substr(2, ings[i].length() - 2));
       // cout << "ing, ingPrice : " << ing << ", " << ingPrice << "\n";
        ingPriceMap.insert({ ing, ingPrice });
    }

    for (int i = 0; i < menu.size(); i++)
    {
        string menuNm = "", ing = "", priceStr = "";

        int j = 0;
        do
        {
            menuNm += menu[i][j];
            j++;
        } 
        while (menu[i][j] != ' ');

        j++;
        do
        {
            ing += menu[i][j];
            j++;
        } while (menu[i][j] != ' ');

        j++;
        for ( ; j < menu[i].length(); j++)
        {
            priceStr += menu[i][j];
        }

        //cout << "menuNm, ing, pricStr : " << menuNm << ", " << ing << ", " << priceStr << "\n";

        int priceInt = stoi(priceStr);
        int cost = 0;

        for (int k = 0; k < ing.length(); k++)
        {
            string ingChar = ing.substr(k, 1);
            cost += ingPriceMap.find(ingChar)->second;
        }

        int profit = priceInt - cost;

        menuProfitMap.insert({ menuNm, profit });
    }

    for (int i = 0; i < sell.size(); i++)
    {
        int j = 0, soldCnt = 0;
        string menuNm = "", soldStr = "";

        //int j = 0;
        do
        {
            menuNm += sell[i][j];
            j++;
        } while (sell[i][j] != ' ');
        j++;

        for (; j < sell[i].length(); j++)
        {
            soldStr += sell[i][j];
        }
        soldCnt = stoi(soldStr);

        answer += soldCnt * menuProfitMap.find(menuNm)->second;

    }



    return answer;
}

int main() {

    vector<string> ings = { "x 25", "y 20", "z 1000" };
    vector<string> menu = { "AAAA xyxy 15", "TTT yy 30", "BBBB xx 30" };
    vector<string> sell = { "BBBB 3", "TTT 2" };

    cout << solution(ings, menu, sell);
}