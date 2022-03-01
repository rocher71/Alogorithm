//
//  main.cpp
//  algo-local
//
//  Created by yejin kim on 2022/02/27.
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
#define MAX 1000001

int arr[MAX];
int n;

int Min(int a, int b)
{
    if(a>b) return b;
    return a;
}

int solve(int n)
{
    for(int i = 4; i<= n; i++)
    {
        int divByTwo = (i%2 == 0) ? i/2 : 0;
        int divByThree = (i%3 == 0) ? i/3 : 0;
        int minusOne = i - 1;
        
        arr[i] = Min(Min(arr[divByTwo], arr[divByThree]), arr[minusOne]) + 1;
    }
    return arr[n];
}

int main(int argc, const char * argv[]) {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    arr[0] = MAX;
    arr[1] = 0;
    arr[2] = 1;
    arr[3] = 1;
    
    cin>>n;
    
    cout << solve(n) << "\n";
}

