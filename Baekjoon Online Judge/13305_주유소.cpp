//
//  main.cpp
//  13305_주유소
//
//  Created by yejin kim on 2022/03/02.
//
#include<iostream>
//#include<algorithm>
//#include<queue>
//#include<vector>
//#include<map>
//#include<stack>
//#include<string>
//#include<cstring>
//#include<sstream>
//#include<deque>
using namespace std;
#define MAX 100001


long long int sum, greedy, n;
long long int dist[MAX], price[MAX];


int main(int argc, const char * argv[]) {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>n;
    
    for(int i= 0; i<n-1; i++){
        cin >> dist[i];
    }
    for(int i=0; i<n; i++){
        cin>>price[i];
    }
    
    greedy = MAX;
    for(int i = 0; i < n-1; i++){
        if(price[i] < greedy)
            greedy = price[i];
        sum += greedy * dist[i];
    }
    
    cout<<sum << "\n";
    
}

