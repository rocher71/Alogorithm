//
//  1541_잃어버린 괄호.cpp
//  algo-local
//
//  Created by yejin kim on 2022/03/03.
//
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


string str;

int solve(string str){
    int addSum = 0, minusSum = 0;
    string num = "";
    bool isMinus = false;
    for(int i = 0; i<= str.length(); i++){
        //cout<< i << "\n";
        //cout<< str[i] << "\n";
        if(( i != str.length()) && str[i] != '+' && str[i] != '-'){
            num += str[i];
            continue;
        }
        
        if(isMinus){
            minusSum += stoi(num);
            num = "";
            //if(str[i] != '-') continue; //-인 상황에서 -만 아니면 계속 빼기로 가야함
            continue;
        }
        else{
            addSum += stoi(num);
            num = "";
            if(str[i] == '+') continue;
        }
        
        isMinus = true;
    }
    return addSum - minusSum;
}

int main(int argc, const char * argv[]) {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>str;
    //cout<< str.length();
    
    cout << solve(str) <<"\n";
    
}

