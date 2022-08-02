#include <iostream>
#include <string>
#include <string.h>
#include<algorithm>
#include <queue>
#include <vector>
#include <map>
#include <stack>
#include <string>
#include <cstring>
#include <set>
#include <sstream>
#include <deque>
#include <cmath>
using namespace std;
#define MAX 100001

int v;
bool visit[MAX];
vector<int> vec[MAX];
vector<int> dfsAns, inputAns;
queue<int> inputAnsQ;

void dfs(int curr){
    if(visit[curr] == true){
        return;
    }
    visit[curr] = true;
    dfsAns.push_back(curr);
    for(int i = 0; i<vec[curr].size(); i++){
        int nxt;
        for(int j = 0; j<vec[curr].size(); j++){
            nxt = vec[curr][j];
            if(inputAnsQ.front() == nxt){
                inputAnsQ.pop();
                break;
            }
        }
        if(visit[nxt]) continue;
        dfs(nxt);
    }

}

int main(){
    cin>> v;
    for(int i = 0; i<v-1; i++){
        int a, b;
        cin>> a>>b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }

    for(int i = 0;i <v; i++){
        int tmp;
        cin>>tmp;
        inputAns.push_back(tmp);
        //큐에 정답 인풋을 저장
        inputAnsQ.push(tmp);
    }
    inputAnsQ.pop();
    dfs(1);

    for(int i = 0; i<inputAns.size(); i++){
        if(inputAns[i] != dfsAns[i]){
            cout << "0\n";
            return 0;
        }
    }

    cout<< "1\n";
    return 0;

}
