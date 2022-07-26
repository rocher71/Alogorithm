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
#define MAX 5001
#define MAX_K 1000000001

int n, q, cnt;
vector<int> vec[MAX];
int usdos[MAX][MAX];
bool visited[MAX];

int main(){
    cin>>n>>q;
    for(int i = 0; i<n-1; i++){
        int node1, node2, usado;
        cin>>node1>>node2>>usado;
        vec[node1].push_back(node2);
        vec[node2].push_back(node1);
        usdos[node1][node2] = usado;
        usdos[node2][node1] = usado;
    }
    
    for(int i = 0; i<q; i++){
        int minUsado, start, cnt = 0;
        cin >> minUsado>> start;
        
        queue<pair<int, int>> q; //정점, 지금까지 온 거리의 유사도 중 최소값
        q.push({start, MAX_K});
        visited[start] = true;
        
        while (!q.empty()) {
            int curr = q.front().first;
            int currUsado = q.front().second;
            q.pop();
            //int currMin = q.front().second;
            if(curr!= start && currUsado >= minUsado) cnt++;
            
            for(int j = 0; j< vec[curr].size(); j++){
                int nxt = vec[curr][j];
                if(visited[nxt]) continue;
                visited[nxt] = true;
                //지금까지 온 거리 중 최소값을 유사도로 넣어줌
                q.push({nxt, min(usdos[curr][nxt], currUsado)});
            }
        }
        cout<<cnt<<"\n" ;
        memset(visited, 0, (n+1)*sizeof(bool));
        
    }
    
    
}
